%{
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>

enum dataType { integer, voidtype, invalid};
//invalid - symbols that do not have a type

enum symType { vartmp, int_const, str_const, labelvar, fvar };
//vartmp - variable or temporary
//fvar - function name


struct symbol {
        char name[256];
        enum dataType type;
        struct symbol* next;
	enum symType sType;
        int offset; //wrt rbp in x86 assembly

};

struct symtab {
        struct symbol* symbols;
        struct symtab* next;
};

struct symtab* symStack = NULL; //points to top of symbol table stack




struct quadtab
{
        int idx;
        char opcode[256];
        struct symbol* src1;
        struct symbol* src2;
        struct symbol* dst;
        struct quadtab* next;


};

struct quadtab* quads = NULL; //list of quadruples
struct quadtab* quadTail = NULL;

struct backpatchList
{
    struct quadtab* quad;
    struct backpatchList* next;
};

struct argList
{
    struct symbol* arg;
    struct argList* next;
};



struct info {
struct symbol* sym;
        char lexeme[256];
        enum dataType type;
        struct backpatchList* truelist;
        struct backpatchList* falselist;
        struct backpatchList* nextlist;
        struct argList* args; //for call statements

};


#define YYSTYPE struct info*

int IncLabel();
int GetLabel();
struct symbol* InstallLabel();
void Backpatch(struct backpatchList* l, struct symbol* s);
void MergeBackpatch(struct backpatchList** x, struct backpatchList* y);
void InsertTarget(struct backpatchList** x, struct quadtab* y);
void InsertArg(struct argList** x, struct symbol* y);
void InsertArgList(struct argList** x, struct argList* y);
void PrintQuads();
void PushSymTab();
void PopSymTab();
struct symbol* AddSym (char* name, enum dataType ty, enum symType sy);
void UpdateType(enum dataType ty);
struct symbol* GenSym(enum dataType ty);
struct quadtab* GenQuad(char* opcode, struct symbol* src1, struct symbol* src2, struct symbol* dst) ;
struct symbol* GenParams (struct argList* x);
struct info* Init (struct info** x);
void PrintSymbols();
struct symbol* FindSymbol(char* lexeme);
void PrintQuad (struct quadtab* q);
void PrintList (struct backpatchList* l) ;
void EmitX86Code ();

%}

%token IF WHILE DO ID NUM string_literal CALLOUT

%nonassoc '<'
%left '+'
%left '*'
%right UMINUS


%%

program	:	block	{
				Init(&$$);
				MergeBackpatch(&($$->nextlist), $1->nextlist);
				struct symbol* s = InstallLabel();
				GenQuad("halt", NULL, NULL, NULL);
				Backpatch($$->nextlist, s);
				//PrintQuads();
				EmitX86Code();
			}
	;

block	:	'{' { PushSymTab(); } stmts '}'	{
							Init(&$$);
							MergeBackpatch(&($$->nextlist), $3->nextlist);
							PopSymTab();
						}
	;

stmts	:	stmts M stmt	{
					Init(&$$);
					Backpatch($1->nextlist, $2->sym);
					MergeBackpatch(&($$->nextlist), $3->nextlist);
				}
	|			{
					Init(&$$);
				}
	;

stmt	:	expr ';'			{
							Init(&$$);
							MergeBackpatch(&($$->nextlist), $1->truelist);
							MergeBackpatch(&($$->nextlist), $1->falselist);
						}
	|	IF '(' expr ')' M stmt		{
							Init(&$$);
							Backpatch($3->truelist, $5->sym);
							MergeBackpatch(&($$->nextlist), $3->falselist);
							MergeBackpatch(&($$->nextlist), $6->nextlist);
						}
	|	WHILE M '(' expr ')' M stmt		{
								Init(&$$);
								Backpatch($4->truelist, $6->sym);
								Backpatch($7->nextlist, $2->sym);
								MergeBackpatch(&($$->nextlist), $4->falselist);
								GenQuad("goto", NULL, NULL, $2->sym);
							}
	|	DO M stmt WHILE M '(' expr ')' ';'	{
								Init (&$$);
								Backpatch($7->truelist, $2->sym);
								MergeBackpatch(&($$->nextlist), $7->falselist);
								Backpatch($3->nextlist, $5->sym);
						}
	|	block				{
							Init(&$$);
                            MergeBackpatch(&($$->nextlist), $1->nextlist);
						}
	|	method_call ';'
	;

method_call	:	CALLOUT '(' string_literal callout_args ')'     {       Init(&$$);
                                                                                struct symbol* nArgs = GenParams($4->args);
                                                                                struct symbol* f = FindSymbol($3->lexeme);
                                                                                if (!f) f = AddSym($3->lexeme, integer, fvar);
                                                                                GenQuad("call", f, nArgs , NULL);
                                                                        }
		;

callout_args    :       callout_args ',' string_literal         {       Init(&$$);
                                                                        struct symbol* s = FindSymbol ($3->lexeme);
                                                                        if (!s) s = AddSym($3->lexeme, voidtype, str_const);
                                                                        InsertArgList(&($$->args), $1->args);
                                                                        InsertArg(&($$->args), s);
                                                                }
                |       callout_args ',' expr           { 	Init (&$$);
								InsertArgList(&($$->args), $1->args);
                                                          	InsertArg(&($$->args), $3->sym); }
                |       { Init (&$$); }
                ;


expr	:	ID '=' expr 	{
					Init(&$$);
					struct symbol* s = FindSymbol($1->lexeme);
					if (!s) {
						s = AddSym($1->lexeme, integer, vartmp);
					}
					GenQuad("=", $3->sym, NULL, s);
					$$->sym = s;
				}
	|	expr '<' expr	{
					Init(&$$);
					$$->sym = GenSym(integer);
					GenQuad("<", $1->sym, $3->sym, $$->sym);
					struct quadtab* q1 = GenQuad("if", $$->sym, NULL, NULL);
					InsertTarget(&($$->truelist), q1);
					struct quadtab* q2 = GenQuad("ifFalse", $$->sym, NULL, NULL);
                                        InsertTarget(&($$->falselist), q2);
                                }
	|	expr '+' expr	{
					Init (&$$);
                                        $$->sym = GenSym(integer);
                                        GenQuad("+", $1->sym, $3->sym, $$->sym);
                                }
	|	expr '*' expr	{
					Init (&$$);
                                        $$->sym = GenSym(integer);
                                        GenQuad("*", $1->sym, $3->sym, $$->sym);
                                }
	|	'-' expr %prec UMINUS	{
						Init (&$$);
						$$->sym = GenSym(integer);
						struct symbol* s = FindSymbol("0");
						if (!s) s = AddSym("0", integer, int_const);
						GenQuad("-", s, $2->sym, $$->sym);
                                	}
	|	'(' expr ')'	{
					$$ = $2;
				}
	|	NUM		{
					Init(&$$);
                                        struct symbol* s = FindSymbol ($1->lexeme);
					if (!s) {
						s = AddSym($1->lexeme, integer, int_const);
					}
					$$->sym = s;

				}
	|	ID		{
					Init(&$$);
                                        struct symbol* s = FindSymbol ($1->lexeme);
                                        if (!s) {
                                                s = AddSym($1->lexeme, integer, vartmp);
                                        }
                                        $$->sym = s;
				}
	;

M       :       {
			Init (&$$);
			$$->sym = InstallLabel();
	}
        ;

%%

#include "lex.yy.c"

int quadid = 1;
int offset = 0;

int IncLabel()
{
        quadid ++;
        return quadid;
}

int GetLabel()
{
        return quadid;
}

struct symbol* InstallLabel()
{
        char label[256];
        sprintf(label, "L%d", GetLabel());
        return(AddSym(label, integer, labelvar));
}

void Backpatch(struct backpatchList* l, struct symbol* s)
{
        struct backpatchList* b = l;
        while (b != NULL)
        {
                //printf("backpatch L%d to %s\n", b->quad->idx, s->name);
                b->quad->dst = s;
                b = b->next;
        }
}//Backkpatch

void MergeBackpatch(struct backpatchList** x, struct backpatchList* y)
{


        if (*x == NULL) {  *x = y;  return; }
        struct backpatchList* b = *x;
        while (b->next != NULL)
        {

                b = b->next;
        }

        b->next = y;

	//PrintList(*x);

}//MergeBackpatch

void InsertTarget(struct backpatchList** x, struct quadtab* y)
{
        if (*x == NULL)
        {
                *x = (struct backpatchList*)malloc(sizeof(struct backpatchList));
                (*x)->quad = y;
                (*x)->next = NULL;
		//PrintList (*x);
                return;
        }

        struct backpatchList* z = (struct backpatchList*)malloc(sizeof(struct backpatchList));
        z->quad = y;
        z->next = *x;

        *x = z;

	//PrintList (*x);
}//InsertTarget



struct symbol* FindSymbol(char* lexeme)
{
        struct symtab* s = symStack;
        while (s != NULL) {
                struct symbol* sym = s->symbols;
                while (sym != NULL)
                {
                                if (strcmp(lexeme, sym->name) == 0) return sym;
                                sym = sym->next;
                }
                s = s->next;
        }
        return NULL;
}

void PrintQuads()
{

        struct quadtab* q = quads;

        while (q != NULL)
        {

		PrintQuad(q);

                q = q->next;

        }
        printf ("\n\n");
}//PrintQuads

void PrintQuad(struct quadtab* q) {
	if (strcmp(q->opcode, "=") == 0) printf("L%d: %s = %s\n", q->idx, q->dst->name, q->src1->name);
	else if (strcmp(q->opcode, "if") == 0) printf("L%d: if %s goto %s\n", q->idx, q->src1->name, q->dst->name);
	else if (strcmp(q->opcode, "ifFalse") == 0) printf("L%d: ifFalse %s goto %s\n", q->idx, q->src1->name, q->dst->name);
	else if (strcmp(q->opcode, "goto") == 0) printf("L%d: goto %s\n", q->idx, q->dst->name);
	else if (strcmp(q->opcode, "halt") == 0) printf("L%d: halt\n", q->idx);
	else if (strcmp(q->opcode, "call") == 0) printf("L%d: call %s, %s\n", q->idx, q->src1->name, q->src2->name);
        else if (strcmp(q->opcode, "param") == 0) printf("L%d: param %s\n", q->idx, q->dst->name);


	else if (q->src2 == NULL) printf("L%d: %s = %s %s\n", q->idx, q->dst->name, q->opcode, q->src1->name);
	else printf ("L%d: %s = %s %s %s\n", q->idx, q->dst->name, q->src1->name, q->opcode, q->src2->name);


}//PrintQuad

void PushSymTab() //push new symbol table to symbol table stack
{
        struct symtab* s = (struct symtab*) malloc(sizeof( struct symtab));



        s->next = symStack;
        symStack = s;

}//PushSymTab

void PopSymTab() //pop from symbol table stack
{
        symStack = symStack->next;



}//PopSymTab

int GetOffset (int x) {

	x = x + 16;

	//align
	x = ((x + 15) / 16) * 16;

	return x;

}//GetOFfset

struct symbol* AddSym (char* name, enum dataType ty, enum symType sy)
{
        struct symbol* var = (struct symbol*) malloc(sizeof( struct symbol));
        strcpy(var->name, name);
        var->type = ty;
	var->sType = sy;

	if (var->sType == vartmp) {
		offset = GetOffset(offset);
		var->offset = offset;

	}


        var->next = symStack->symbols;
        symStack->symbols = var;

        return var;

}//AddSym





struct symbol* GenSym(enum dataType ty)
{
        static int tempid = 0;
        tempid ++;
        struct symbol* temp = (struct symbol*) malloc (sizeof( struct symbol));
        sprintf(temp->name, "t%d", tempid);
        temp->type = ty;
	temp->sType = vartmp;
	offset = GetOffset(offset);
	temp->offset = offset;

        temp->next = symStack->symbols;
        symStack->symbols = temp;
        return temp;
}//GenSym

struct quadtab* GenQuad(char* opcode, struct symbol* src1, struct symbol* src2, struct symbol* dst)
{
        int quadid = GetLabel();
        struct quadtab* q = (struct quadtab*) malloc(sizeof( struct quadtab));
        strcpy(q->opcode, opcode);
        q->src1 = src1;
        q->src2 = src2;
        q->dst = dst;
        q->idx = quadid;
        q->next = NULL;

        if (quads == NULL)
        {
                quads = q;
                quadTail = q;
        }
        else
        {
                quadTail->next = q;
                quadTail = q;
        }

        IncLabel();
        return q;

}//GenQuad

struct symbol* GenParams (struct argList* x)
{
        int nArgs = 0;
        struct argList* z = x;
        while (z != NULL) {
                GenQuad("param", NULL, NULL, z->arg);
                nArgs ++;
                z = z->next;
        }
        char a[256]; sprintf(a, "%d", nArgs);
        struct symbol* s = FindSymbol(a);
        if (s) return s;

        if (a[0] == '"') { s = AddSym(a, voidtype, str_const); }
        else { s = AddSym(a, integer, int_const); }
        return s;
}//GenParams

void InsertArg(struct argList** x, struct symbol* y)
{
        struct argList* z = (struct argList*) malloc (sizeof (struct argList));
        z->arg = y;
        z->next= NULL;
        if (*x == NULL) { *x = z; return;}
        struct argList* w = *x;
        while (w->next != NULL) w = w->next;
        w->next = z;
}//InsertArg

void InsertArgList(struct argList** x, struct argList* y)
{
        if (*x == NULL)         {
                *x = y;
                return;
        }

        struct argList* z = *x;
        while (z->next != NULL) {
                z = z->next;
        }
        z->next = y;
}//InsertArgList


struct info* Init (struct info** x)
{
        *x = (struct info*) malloc (sizeof(struct info));
        (*x)->sym = NULL;
        (*x)->type = invalid;
        strcpy((*x)->lexeme, "");
        (*x)->truelist = NULL;
        (*x)->falselist = NULL;
        (*x)->nextlist = NULL;
        return *x;
}//Init

void PrintSymbols()
{

        printf("SYMBOLS BEGIN:\n");

        struct symtab* s = symStack;
        while (s != NULL) {
                struct symbol* sym = s->symbols;
                while (sym != NULL)
                {
                                if (sym->type == integer) printf("%s integer\n", sym->name);
                                if (sym->type == invalid) printf("%s invalid\n", sym->name);
                                sym = sym->next;
                }
                s = s->next;
        }
        printf("SYMBOLS END\n");
}

void PrintList(struct backpatchList* l) {
	printf("*********************\n");
	while (l != NULL) {
		struct quadtab* q = l->quad;
		PrintQuad(q);
		l = l->next;

	}
	printf("*********************\n");
}//PrintList

#include "x86.cpp"

int main(void)
{

	PushSymTab();

        yyparse();
        return 0;
}

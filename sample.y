%{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum dataType { integer, invalid, boolean, character, string, array};
//invalid - symbols that do not have a type

struct symbol {
    char name[256];
    enum dataType type;
    struct symbol* next;
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

struct info {
        char PD2_type[100];
        struct info* firstChild;
        struct info* nextSibling;
        struct symbol* sym;
        char lexeme[256];
        enum dataType type;
        struct backpatchList* truelist;
        struct backpatchList* falselist;
        struct backpatchList* nextlist;
};

#define YYSTYPE struct info*

void yyerror (char const *s);

int IncLabel();

int GetLabel();

struct symbol* InstallLabel();

void Backpatch(struct backpatchList* l, struct symbol* s);

void MergeBackpatch(struct backpatchList** x, struct backpatchList* y);

void InsertTarget(struct backpatchList** x, struct quadtab* y);

void PrintQuads();

void PushSymTab();

void PopSymTab();

struct symbol* AddSym (char* name, enum dataType ty);

void UpdateType(enum dataType ty);

struct symbol* GenSym(enum dataType ty);

struct quadtab* GenQuad(char* opcode, struct symbol* src1, struct symbol* src2, struct symbol* dst) ;

struct symbol* getFindSym(char* lexeme, enum dataType ty);

void PrintSymbols();

struct symbol* FindSymbol(char* lexeme, enum dataType ty);

void rel_operation(char *op, struct info* SS, struct info* S1, struct info* S3);

void PrintQuad (struct quadtab* q);

void PrintList (struct backpatchList* l) ;

struct info* Init_PD2(struct info** x, char* y);
void PrintTree (struct info* x);
void Print (struct info* x, int l);
void PrintTree2 (struct info* x);

%}

%token CLASS PROGRAM
%token IF FOR ID VOID INT BOOL CALLOUT BREAK CONTINUE ELSE RETURN
%token bool_literal char_literal string_literal int_literal
%token COMMA SEMCOL
%token PLUS MINUS MUL DIV MOD
%token LT GT LE GE NE EQ
%token ASS PASS MASS
%token AND OR NOT
%token OP CP OB CB OS CS

%nonassoc NE EQ
%nonassoc LT GT GE LE
%right UMINUS


%%

program	: CLASS PROGRAM	OB feild_methods CB {	Init_PD2 (&$$, "program");
                                                $$->firstChild = $4;
                                                PrintTree2($$);
                                                PrintQuads();
                                            }
    ;

feild_methods    :   feild_methods  feild_method    {   Init_PD2(&$$, "feild_methods");
                                                        if($1){
                                                            $$->firstChild = $1;
                                                            $1->nextSibling = $2;
                                                        }
                                                        else
                                                            $$->firstChild = $2;
                                                    }
    |       {   $$ = NULL; }
    ;

feild_method    :   type ID OP args CP block {   Init_PD2(&$$, "method_decl");
                                $$->firstChild = $2;
                                if($4) {
                                    $2->nextSibling = $4;
                                    $4->nextSibling = $6;
                                }
                                else
                                    $2->nextSibling = $6;
                            }
    |   VOID ID OP args CP block    {   Init_PD2(&$$, "method_decl");
                                        $$->firstChild = $2;
                                        if($4) {
                                            $2->nextSibling = $4;
                                            $4->nextSibling = $6;
                                        }
                                        else
                                            $2->nextSibling = $6;
                                    }
    |   type ID OS int_literal CS ARR_IDS SEMCOL {   Init_PD2(&$$, "feild_decl");
                                            $$->firstChild = $1;
                                            $1->nextSibling = $2;
                                            $2->nextSibling = $4;
                                            $4->nextSibling = $6;
                                        }
    |   type ID ARR_IDS SEMCOL  {   Init_PD2(&$$, "feild_decl");
                                    $$->firstChild = $1;
                                    $1->nextSibling = $2;
                                    $2->nextSibling = $3;
                                }
    |   type ID ASS literal SEMCOL  {   Init_PD2(&$$, "feild_decl");
                                        $$->firstChild = $1;
                                        $1->nextSibling = $2;
                                        $2->nextSibling = $4;
                                        //strcpy($3->PD2_type, "assign_op");
                                    }
    ;

type    :   INT {   Init_PD2(&$$, "int");
                    //$$->firstChild = $1;
                }
    |   BOOL    {   Init_PD2(&$$, "bool");
                    //$$->firstChild = $1;
                }
    ;

ARR_IDS :   COMMA ARR_ID ARR_IDS    {   Init_PD2(&$$, "feild");
                                        $$->firstChild = $2;
                                        $2->nextSibling = $3;
                                    }
    |       {   $$ = NULL;
            }
    ;

ARR_ID  :   ID  {   $$ = $1;
                }
    |   ID OS int_literal CS    {   Init_PD2(&$$, "array");
                                    $$->firstChild = $1;
                                    $1->nextSibling = $3;
                                    PrintTree($$);
                                }
    ;

args    :   arg args1   {   Init_PD2(&$$, "args");
                            $$->firstChild = $1;
                            $1->nextSibling = $2;
                        }
    |       {   $$ = NULL;
            }
    ;

args1   :   COMMA arg args1 {   Init_PD2(&$$, "args");
                                $$->firstChild = $2;
                                $2->nextSibling = $3;
                            }
    |       {   $$ = NULL;
            }
    ;

arg :   BOOL ID {   Init_PD2(&$$, "bool");
                    $$->firstChild = $2;
                }
    |   INT ID  {   Init_PD2(&$$, "int");
                    $$->firstChild = $2;
                }
    ;

block   :   OB var_decls stmts CB   {   Init_PD2(&$$, "block");
                                        if($2){
                                            $$->firstChild = $2;
                                            $2->nextSibling = $3;
                                        }
                                        else
                                            $$->firstChild = $3;
                                    }
    ;

var_decls   :   var_decls var_decl  {   Init_PD2(&$$, "var_decls");
                                        if($1){
                                            $$->firstChild = $1;
                                            $1->nextSibling = $2;
                                        }
                                        else
                                            $$->firstChild = $2;
                                    }
    |       {   $$ = NULL;
            }
    ;

var_decl    :   arg vars SEMCOL {   Init_PD2(&$$, "var_decl");
                                    $$->firstChild = $1;
                                    $1->nextSibling = $2;
                                }
    ;

vars    :   COMMA var vars  {   Init_PD2(&$$, "var");
                                $$->firstChild = $2;
                                $2->nextSibling = $3;
                            }
    |       {   $$ = NULL;
            }
    ;

var :   ID  {   $$ = $1;
            }
    ;

stmts	:	stmts M stmt	{	Init_PD2 (&$$, "stmts");
                            if ($1) {
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
                            else
                                $$->firstChild = $3;
                            PrintTree($$);
                        }
    |			{	$$ = NULL;
                    PrintTree($$);
                }
    ;

stmt	:	block    {   $$ = $1; }
    |   expr_a SEMCOL	{	Init_PD2 (&$$, "eval");
                            $$->firstChild = $1;
                            PrintTree($$);
                        }
    |	IF OP expr_a CP block   {   Init_PD2 (&$$, "if");
                                    $$->firstChild = $3;
                                    $3->nextSibling = $5;
                                    PrintTree($$);
                                }
    |	IF OP expr_a CP block ELSE block  {   Init_PD2 (&$$, "if");
                                    $$->firstChild = $3;
                                    $3->nextSibling = $5;
                                    $5->nextSibling = $7;
                                    PrintTree($$);
                                }
    |   FOR fexpr COMMA expr_a block  {   Init_PD2(&$$, "for");
                                        $$->firstChild = $2;
                                        $2->nextSibling = $4;
                                        $4->nextSibling = $5;
                                        PrintTree($$);
                                    }
    |   RETURN Rexpr SEMCOL   {   Init_PD2(&$$, "return");
                            $$->firstChild = $1;
                            $1->nextSibling = $2;
                        }
    |   BREAK SEMCOL  {  $$ = $1;
                }
    |   CONTINUE SEMCOL  {   $$ = $1;
                }
    |   method_call SEMCOL  {   Init_PD2(&$$, "method_call");
                        $$->firstChild = $1;
    }
    ;

method_call :   CALLOUT OP string_literal CP   {   Init_PD2(&$$, "callout");
                                                    $$->firstChild = $3;
                                                    $3->nextSibling = $4;
        }
    ;

Rexpr   :   OP expr_a CP    {  $$ = $2;

                            }
    |       {   $$ = NULL;  }
    ;

fexpr   :   ID ASS expr_a { Init_PD2(&$$, "assign");
                            $$->firstChild = $1;
                            $1->nextSibling = $3;
                        }
    ;

expr_a    :   expr_or   {   $$ = $1;
                        }
    |   ID ASS expr_or  {   Init_PD2(&$$, "assign_op");
                            $$->firstChild = $1;
                            $1->nextSibling = $3;
                            $$->sym = getFindSym($1->lexeme, $1->type);
                            GenQuad("=", $3->sym, NULL, $$->sym);
                        }
    |   ID PASS expr_or {   Init_PD2(&$$, "plus_eq");
                            $$->firstChild = $1;
                            $1->nextSibling = $3;
                            $$->sym = getFindSym($1->lexeme, $1->type);
                            GenQuad("+", $$->sym, $3->sym, $$->sym);
                            //GenQuad("=", $3->sym, NULL, $$->sym);
                        }
    |   ID MASS expr_or {   Init_PD2(&$$, "minus_eq");
                            $$->firstChild = $1;
                            $1->nextSibling = $3;
                            $$->sym = getFindSym($1->lexeme, $1->type);
                            GenQuad("-", $$->sym, $3->sym, $$->sym);
                            //GenQuad("=", $3->sym, NULL, $$->sym);
                        }
    |   ID OP expr_rec CP   {   Init_PD2(&$$, "method_call");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    ;

expr_rec    :   expr_a  expr_rec2   {   Init_PD2(&$$, "args");
                                        $$->firstChild = $1;
                                        $1->nextSibling = $2;
                                    }
    |       {   $$ = NULL;  }
    ;

expr_rec2   :   COMMA expr_a expr_rec2  {   Init_PD2(&$$, "args");
                                            $$->firstChild = $2;
                                            $2->nextSibling = $3;
    }
    |       {   $$ = NULL;  }
    ;

expr_or :   expr_and    {   $$ = $1;
                        }
    |   expr_or OR expr_and {   Init_PD2(&$$, "cond_OR");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    ;

expr_and :   expr_eq    {   $$ = $1;
                        }
    |   expr_and AND expr_eq    {   Init_PD2(&$$, "cond_AND");
                                    $$->firstChild = $1;
                                    $1->nextSibling = $3;
                                }
    ;

expr_eq :   expr_rel    {   $$ = $1;
                        }
    |   expr_eq EQ expr_rel {   Init_PD2(&$$, "EQUAL");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                                rel_operation("==", $$, $1, $3);
                            }
    |   expr_eq NE expr_rel {   Init_PD2(&$$, "NOT_EQUAL");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                                rel_operation("!=", $$, $1, $3);
                            }
    ;

expr_rel :   expr_pm {   $$ = $1;
                    }
    |   expr_rel LT expr_pm {   Init_PD2(&$$, "LESS_THAN");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                                rel_operation("<", $$, $1, $3);
                            }
    |   expr_rel GT expr_pm {   Init_PD2(&$$, "GREATER_THAN");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                                rel_operation(">", $$, $1, $3);
                            }
    |   expr_rel LE expr_pm {   Init_PD2(&$$, "LESS_EQUAL");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                                rel_operation("<=", $$, $1, $3);
                            }
    |   expr_rel GE expr_pm {   Init_PD2(&$$, "GREATER_EQUAL");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                                rel_operation(">=", $$, $1, $3);
                            }
    ;

expr_pm :   expr_mdm    {   $$ = $1;
                        }
    |   expr_pm PLUS expr_mdm   {   Init_PD2(&$$, "plus");
                                        $$->firstChild = $1;
                                        $1->nextSibling = $3;
                                        $$->sym = GenSym(integer);
                                        GenQuad("+", $1->sym, $3->sym, $$->sym);
                                    }
    |   expr_pm MINUS expr_mdm  {   Init_PD2(&$$, "minus");
                                    $$->firstChild = $1;
                                    $1->nextSibling = $3;
                                    $$->sym = GenSym(integer);
                                    GenQuad("-", $1->sym, $3->sym, $$->sym);
                                }
    ;

expr_mdm    :   factor  {   $$ = $1;
                        }
    |   expr_mdm MUL factor {   Init_PD2(&$$, "mul");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                                $$->sym = GenSym(integer);
                                GenQuad("*", $1->sym, $3->sym, $$->sym);
                            }
    |   expr_mdm DIV factor {   Init_PD2(&$$, "div");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                                $$->sym = GenSym(integer);
                                GenQuad("/", $1->sym, $3->sym, $$->sym);
                            }
    |   expr_mdm MOD factor {   Init_PD2(&$$, "mod");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                                $$->sym = GenSym(integer);
                                GenQuad("%", $1->sym, $3->sym, $$->sym);
                            }
    ;

factor  :	OP expr_a CP	{	$$ = $2;
                            }
    |	NOT factor %prec NOT    {	Init_PD2 (&$$, "cond_NOT");
                                    $$->firstChild = $2;
                                    $$->sym = GenSym(boolean);
                                    GenQuad("!", $2->sym,NULL, $$->sym);
                                }
    |	MINUS factor %prec UMINUS   {	Init_PD2 (&$$, "NEG");
                                        $$->firstChild = $2;
                                        $$->sym = GenSym(integer);
                                        GenQuad("-", $2->sym, NULL, $$->sym);
                                    }
    |	literal		{	$$ = $1;
                    }
    |   ID OS expr_a CS {   Init_PD2(&$$, "array");
                            $$->firstChild = $1;
                            $1->nextSibling = $3;
                            $1->sym = getFindSym($1->lexeme, array);
                            $$->sym = GenSym(integer);
                            GenQuad("=", $1->sym, $3->sym, $$->sym);

                        }
    |	ID	{	Init_PD2(&$$, $1->PD2_type);
                $$->sym = getFindSym($1->lexeme, integer);
                //$$->firstChild = $1;
            }
    ;

literal :   int_literal	{	Init_PD2(&$$, $1->PD2_type);
                            $$->sym = getFindSym($1->lexeme, integer);
                        }
    |   string_literal  {   Init_PD2(&$$, $1->PD2_type);
                            $$->sym = getFindSym($1->lexeme, string);
                            //$$->firstChild = $1;
                        }
    |   char_literal    {   Init_PD2(&$$, $1->PD2_type);
                            $$->sym = getFindSym($1->lexeme, character);
                            //$$->firstChild = $1;
                        }
    |   bool_literal    {   Init_PD2(&$$, $1->PD2_type);
                            $$->sym = getFindSym($1->lexeme, boolean);
                            //$$->firstChild = $1;
                        }
    ;

M   :       {
            Init_PD2(&$$, "");
            $$->sym = InstallLabel();
    }
    ;
%%

#include "lex.yy.c"

//extern yydebug = 1;

int quadid = 1;

int IncLabel(){
    quadid ++;
    return quadid;
}

int GetLabel(){
    return quadid;
}

struct symbol* InstallLabel(){
    char label[256];
    sprintf(label, "L%d", GetLabel());
    return(AddSym(label, integer));
}

void Backpatch(struct backpatchList* l, struct symbol* s){
    struct backpatchList* b = l;
    while (b != NULL){
        //printf("backpatch L%d to %s\n", b->quad->idx, s->name);
        b->quad->dst = s;
        b = b->next;
    }
}//Backkpatch

void MergeBackpatch(struct backpatchList** x, struct backpatchList* y){
    if (*x == NULL) {  *x = y;  return; }
    struct backpatchList* b = *x;
    while (b->next != NULL){
        b = b->next;
    }

    b->next = y;
    //PrintList(*x);
}//MergeBackpatch

void InsertTarget(struct backpatchList** x, struct quadtab* y){
    if (*x == NULL){
        *x = (struct backpatchList*)malloc(sizeof(struct backpatchList));
        (*x)->quad = y;
        (*x)->next = NULL;
        //PrintList (*x);
        return;
    }
    struct backpatchList* z = (struct backpatchList*) malloc(sizeof(struct backpatchList));
    z->quad = y;
    z->next = *x;

    *x = z;
    //PrintList (*x);
}//InsertTarget

struct symbol* FindSymbol(char* lexeme, enum dataType ty){
    struct symtab* s = symStack;
    while (s != NULL) {
        struct symbol* sym = s->symbols;
        while (sym != NULL){
            if (strcmp(lexeme, sym->name) == 0 && ty == sym->type)
                return sym;
            sym = sym->next;
        }
        s = s->next;
    }
    return NULL;
}

void PrintQuads(){
    struct quadtab* q = quads;
    while (q != NULL){
        PrintQuad(q);
        q = q->next;
    }
    printf ("\n\n");
}//PrintQuads

void PrintQuad(struct quadtab* q) {
    if (strcmp(q->opcode, "=") == 0){
        if(q->src1->type == array)
            printf("L%d: %s = %s[%s]\n", q->idx, q->dst->name, q->src1->name, q->src2->name);
        else
            printf("L%d: %s = %s\n", q->idx, q->dst->name, q->src1->name);
    }
    else if (strcmp(q->opcode, "if") == 0)
        printf("L%d: if %s goto %s\n", q->idx, q->src1->name, q->dst->name);

    else if (strcmp(q->opcode, "ifFalse") == 0)
        printf("L%d: ifFalse %s goto %s\n", q->idx, q->src1->name, q->dst->name);

    else if (strcmp(q->opcode, "goto") == 0)
        printf("L%d: goto %s\n", q->idx, q->dst->name);

    else if (strcmp(q->opcode, "halt") == 0)
        printf("L%d: halt\n", q->idx);

    else if (q->src2 == NULL)
        printf("L%d: %s = %s %s\n", q->idx, q->dst->name, q->opcode, q->src1->name);

    else
        printf ("L%d: %s = %s %s %s\n", q->idx, q->dst->name, q->src1->name, q->opcode, q->src2->name);

}//PrintQuad

void PushSymTab() { //push new symbol table to symbol table stack
    struct symtab* s = (struct symtab*) malloc(sizeof( struct symtab));

    s->next = symStack;
    symStack = s;
}//PushSymTab

void PopSymTab() {//pop from symbol table stack
    symStack = symStack->next;
}//PopSymTab

struct symbol* AddSym (char* name, enum dataType ty){
    struct symbol* var = (struct symbol*) malloc(sizeof( struct symbol));
    strcpy(var->name, name);
    var->type = ty;
    var->next = symStack->symbols;
    symStack->symbols = var;
    return var;
}//AddSym

struct symbol* GenSym(enum dataType ty){
    static int tempid = 0;
    tempid ++;
    struct symbol* temp = (struct symbol*) malloc (sizeof( struct symbol));
    sprintf(temp->name, "t%d", tempid);
    temp->type = ty;
    temp->next = symStack->symbols;
    symStack->symbols = temp;
    return temp;
}//GenSym

struct quadtab* GenQuad(char* opcode, struct symbol* src1, struct symbol* src2, struct symbol* dst) {
    int quadid = GetLabel();
    struct quadtab* q = (struct quadtab*) malloc(sizeof( struct quadtab));
    strcpy(q->opcode, opcode);
    q->src1 = src1;
    q->src2 = src2;
    q->dst = dst;
    q->idx = quadid;
    q->next = NULL;

    if (quads == NULL){
        quads = q;
        quadTail = q;
    }
    else{
        quadTail->next = q;
        quadTail = q;
    }
    IncLabel();
    return q;
}//GenQuad

struct symbol* getFindSym(char* lexeme, enum dataType ty){
    struct symbol* s = FindSymbol (lexeme, ty);
    if (!s) {
            s = AddSym(lexeme, ty);
    }
    return s;
}

void rel_operation(char *op, struct info* SS, struct info* S1, struct info* S3){
    SS->sym = GenSym(boolean);
    GenQuad(op, S1->sym, S3->sym, SS->sym);
    struct quadtab* q1 = GenQuad("if", SS->sym, NULL, NULL);
    InsertTarget(&(SS->truelist), q1);
    struct quadtab* q2 = GenQuad("ifFalse", SS->sym, NULL, NULL);
    InsertTarget(&(SS->falselist), q2);
}

void PrintSymbols(){
    printf("SYMBOLS BEGIN:\n");

    struct symtab* s = symStack;
    while (s != NULL) {
        struct symbol* sym = s->symbols;
        while (sym != NULL){
            if (sym->type == integer)
                printf("%s integer\n", sym->name);
            if (sym->type == invalid)
                printf("%s invalid\n", sym->name);
            sym = sym->next;
        }
        s = s->next;
    }
    printf("SYMBOLS END\n");
} //PrintSymbols

void PrintList(struct backpatchList* l) {
    printf("*********************\n");
    while (l != NULL) {
        struct quadtab* q = l->quad;
        PrintQuad(q);
        l = l->next;
    }
    printf("*********************\n");
}//PrintList

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

struct info* Init_PD2 (struct info** x, char* type) {
    *x = (struct info*) malloc (sizeof(struct info));
    strcpy((*x)->PD2_type, type);
    (*x)->firstChild = NULL;
    (*x)->nextSibling = NULL;
    (*x)->sym = NULL;
    (*x)->type = invalid;
    strcpy((*x)->lexeme, "");
    (*x)->truelist = NULL;
    (*x)->falselist = NULL;
    (*x)->nextlist = NULL;
    return *x;
}//Init_PD2

void PrintTree2 (struct info* x) {
    printf("********************\n");
    Print (x, 0);
}

void PrintTree (struct info* x) {
    //printf("********************\n");
    //Print (x, 0);
}

void Print (struct info* x, int level) {
    if (x == NULL) return;

    int i = 0;
    if(x->PD2_type[0] != '\0'){
        for (i = 0; i < level; i ++) printf ("    ");
        printf("%s\n", x->PD2_type);
    }

    Print (x->firstChild, level + 1);

    Print (x->nextSibling, level);
}

int main(void){
    PushSymTab();
    yyparse();
    return 0;
}

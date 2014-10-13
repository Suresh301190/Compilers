%{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct info {
        char type[100];
        struct info* firstChild;
        struct info* nextSibling;
};

#define YYDEBUG 1
#define YYSTYPE struct info*

void yyerror (char const *s);

void Init(struct info** x, char* y);
void PrintTree (struct info* x);
void Print (struct info* x, int l);
void PrintTree2 (struct info* x);

%}

%debug

%token CLASS PROGRAM
%token IF FOR ID VOID INT BOOL CALLOUT BREAK CONTINUE ELSE
%token bool_literal char_literal string_literal int_literal
%token PLUS MINUS MUL DIV MOD
%token LT GT LE GE NE EQ
%token ASS PASS MASS
%token AND OR NOT
%token OP CP OB CB OS CS

%right ASS PASS MASS
%left OR
%left AND
%nonassoc NE EQ
%nonassoc LT GT GE LE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%right UMINUS


%%

program	: CLASS PROGRAM	block	{	Init (&$$, "program");
				                    $$->firstChild = $3;
				                    PrintTree2($$);
			                    }
	;

block   :   feild_decls method_decls    {   Init(&$$, "block");
                                            $$->firstChild = $1;
                                            $1->nextSibling = $2;
                                        }
    |   OB stmts CB	{	Init (&$$, "block");
			            $$->firstChild = $2;
			            PrintTree($$);
		            }
	;

feild_decls :   feild_decls feild_decl  {   Init(&$$, "feild_decl");
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

method_decls :   method_decls method_decl   {   Init(&$$, "method_decl");
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

feild_decl  :   INT ID ';'  {   Init(&$$, "int");
                                $$->firstChild = $2;
                            }
    |   INT ID ASS literal ';'  {   Init(&$$, "int");
                                    $$->firstChild = $3;
                                    $3->firstChild = $2;
                                    $3->nextSibling = $4;
                                }
    ;

method_decl :   VOID ID    {

    }
    ;

stmts	:	stmts stmt	{	Init (&$$, "stmts");
					        if ($1) {
						        $$->firstChild = $1;
						        $1->nextSibling = $2;
					        }
                            else
                                $$->firstChild = $2;
					        PrintTree($$);
				        }
	|			{	$$ = NULL;
					PrintTree($$);
				}
	;

stmt	:	expr_a ';'	{	Init (&$$, "eval");
							$$->firstChild = $1;
							PrintTree($$);
						}
	|	IF OP expr_a CP stmt    {   Init (&$$, "if");
							        $$->firstChild = $3;
							        $3->nextSibling = $5;
							        PrintTree($$);
						        }
	|	block	{	Init (&$$, "block");
					$$->firstChild = $1;
					PrintTree($$);
				}
	;

expr_a    :   expr_or   {   $$ = $1;
                        }
    |   ID ASS expr_or  {   Init(&$$, "assign_op");
                            $$->firstChild = $1;
                            $1->nextSibling = $3;
                        }
    |   ID PASS expr_or {   Init(&$$, "plus_eq");
                            $$->firstChild = $1;
                            $1->nextSibling = $3;
                        }
    |   ID MASS expr_or {   Init(&$$, "minus_eq");
                            $$->firstChild = $1;
                            $1->nextSibling = $3;
                        }
    ;

expr_or :   expr_and    {   $$ = $1;
                        }
    |   expr_or OR expr_and {   Init(&$$, "cond_OR");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    ;

expr_and :   expr_eq    {   $$ = $1;
                        }
    |   expr_and AND expr_eq    {   Init(&$$, "cond_AND");
                                    $$->firstChild = $1;
                                    $1->nextSibling = $3;
                                }
    ;

expr_eq :   expr_rel    {   $$ = $1;
                        }
    |   expr_eq EQ expr_rel {   Init(&$$, "EQUAL");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    |   expr_eq NE expr_rel {   Init(&$$, "NOT_EQUAL");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    ;

expr_rel :   expr_pm {   $$ = $1;
                    }
    |   expr_rel LT expr_pm {   Init(&$$, "LESS_THAN");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    |   expr_rel GT expr_pm {   Init(&$$, "GREATER_THAN");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    |   expr_rel LE expr_pm {   Init(&$$, "LESS_EQUAL");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    |   expr_rel GE expr_pm {   Init(&$$, "GREATER_EQUAL");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    ;

expr_pm :   expr_mdm    {   $$ = $1;
                        }
    |   expr_pm PLUS expr_mdm   {   Init(&$$, "plus");
                                        $$->firstChild = $1;
                                        $1->nextSibling = $3;
                                    }
    |   expr_pm MINUS expr_mdm  {   Init(&$$, "minus");
                                    $$->firstChild = $1;
                                    $1->nextSibling = $3;
                                }
    ;

expr_mdm    :   factor  {   $$ = $1;
                        }
    |   expr_mdm MUL factor {   Init(&$$, "mul");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    |   expr_mdm DIV factor {   Init(&$$, "div");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    |   expr_mdm MOD factor {   Init(&$$, "mod");
                                $$->firstChild = $1;
                                $1->nextSibling = $3;
                            }
    ;

factor  :	OP expr_a CP	{	$$ = $2;
				            }
    |	NOT factor %prec NOT    {	Init (&$$, "cond_NOT");
                                    $$->firstChild = $2;
                                }
    |	MINUS factor %prec UMINUS   {	Init (&$$, "NEG");
                                        $$->firstChild = $2;
                                    }
	|	literal		{	$$ = $1;
				    }
	|	ID	{	$$ = $1;
			}
    ;

literal :   int_literal	{	$$ = $1;
                        }
    |   string_literal  {   $$ = $1;
                        }
    |   char_literal    {   $$ = $1;
                        }
    |   bool_literal    {   $$ = $1;
                        }
    ;
%%

#include "lex.yy.c"

//yydebug = 1;

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

void Init (struct info** x, char* type) {
	*x = (struct info*) malloc (sizeof(struct info));
	strcpy((*x)->type, type);
	(*x)->firstChild = NULL;
	(*x)->nextSibling = NULL;
}//Init

void PrintTree2 (struct info* x) {
	printf("********************\n");
	Print (x, 0);
}

void PrintTree (struct info* x) {

}

void Print (struct info* x, int level) {
	if (x == NULL) return;

	int i = 0;
    if(x->type[0] != '\0'){
	    for (i = 0; i < level; i ++) printf ("    ");
        printf("%s\n", x->type);
    }

	Print (x->firstChild, level + 1);

	Print (x->nextSibling, level);
}

int main(void)
{

        yyparse();
        return 0;
}

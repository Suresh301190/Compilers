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

%token CLASS PROGRAM
%token IF FOR ID
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

block	:	OB stmts CB	{	Init (&$$, "block");
					            $$->firstChild = $2;
					            PrintTree($$);
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
	|	IF OP expr_a CP stmt{   Init (&$$, "if");
							    $$->firstChild = $3;
							    $3->nextSibling = $5;
							    PrintTree($$);
						    }
	|	block	{	Init (&$$, "block");
					$$->firstChild = $1;
					PrintTree($$);
				}
	;

expr_a    :   expr_c    {   $$ = $1;
                        }
    |   ID ASS expr_c  {    Init(&$$, "assign_op");
                            $$->firstChild = $1;
                            $$->nextSibling = $3;
                        }
    ;

expr_c  :   expr_r  {   $$ = $1;
                    }
    |   expr_c COND_OP expr_r   {   Init(&$$, "cond_op");
                                        $$->firstChild = $1;
                                        $$->nextSibling = $3;
                                    }
    ;

expr_r  :   expr_pm {   $$ = $1;
                    }
    |   expr_r REL_OP expr_pm   {   Init(&$$, "rel_op");
                                        $$->firstChild = $1;
                                        $$->nextSibling = $3;
                                    }
    |   expr_r EQ_OP expr_pm   {    Init(&$$, "eq_op");
                                    $$->firstChild = $1;
                                    $$->nextSibling = $3;
                                }
    ;

expr_pm :   expr_mdm    {   $$ = $1;
                        }
    |   expr_pm PLUS expr_mdm   {   Init(&$$, "plus");
                                        $$->firstChild = $1;
                                        $$->nextSibling = $3;
                                    }
    |   expr_pm MINUS expr_mdm  {   Init(&$$, "minus");
                                    $$->firstChild = $1;
                                    $$->nextSibling = $3;
                                }
    ;

expr_mdm    :   factor  {   $$ = $1;
                        }
    |   expr_mdm MUL factor {   Init(&$$, "mul");
                                $$->firstChild = $1;
                                $$->nextSibling = $3;
                            }
    |   expr_mdm DIV factor {   Init(&$$, "div");
                                $$->firstChild = $1;
                                $$->nextSibling = $3;
                            }
    |   expr_mdm MOD factor {   Init(&$$, "mod");
                                $$->firstChild = $1;
                                $$->nextSibling = $3;
                            }
    ;

factor  :	OP expr_a CP	{	$$ = $2;
					            PrintTree($$);
				            }
	|	int_literal		{	$$ = $1;
					        PrintTree($$);
				        }
    |   string_literal  {   $$ = $1;
                            PrintTree($$);
                        }
    |   char_literal    {   $$ = $1;
                            PrintTree($$);
                        }
	|	ID	{	$$ = $1;
				PrintTree($$);
			}
	;



%%

#include "lex.yy.c"

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

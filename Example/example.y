%{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct info {
        char type[100];
        struct info* firstChild;
        struct info* nextSibling;
};

#define YYSTYPE struct info*

void yyerror (char const *s);

void Init(struct info** x, char* y);
void PrintTree (struct info* x);
void Print (struct info* x, int l);
%}

%token IF WHILE DO ID NUM

%nonassoc '<'
%left '+'
%left '*'
%right UMINUS

%%

program	:	block	{	Init (&$$, "program");
				$$->firstChild = $1;
				PrintTree($$);
			}
	;

block	:	'{' stmts '}'	{	Init (&$$, "block");
					$$->firstChild = $2;
					PrintTree($$);
				}
	;

stmts	:	stmts stmt	{	Init (&$$, "stmts");
					if ($1) {
						$$->firstChild = $1;
						$1->nextSibling = $2;
					} else $$->firstChild = $2;
					PrintTree($$);
				}
	|			{	$$ = NULL;
					PrintTree($$);
				}
	;

stmt	:	expr ';'			{	Init (&$$, "eval");
							$$->firstChild = $1;
							PrintTree($$);
						}
	|	IF '(' expr ')' stmt		{	Init (&$$, "if");
							$$->firstChild = $3;
							$3->nextSibling = $5;
							PrintTree($$);
						}
	|	WHILE '(' expr ')' stmt		{	Init (&$$, "while");
							$$->firstChild = $3;
							$3->nextSibling = $5;
							PrintTree($$);
						}
	|	DO stmt WHILE '(' expr ')' ';'	{	Init (&$$, "do");
                                                        $$->firstChild = $2;
                                                        $3->nextSibling = $5;
							PrintTree($$);
						}
	|	block				{	Init (&$$, "block");
							$$->firstChild = $1;
							PrintTree($$);
						}
	;

expr	:	ID '=' expr 	{	Init (&$$, "assign");
					$$->firstChild = $1;
					$1->nextSibling = $3;
					PrintTree($$);
				}
	|	expr '<' expr	{	Init (&$$, "compare");
                                        $$->firstChild = $1;
                                        $1->nextSibling = $3;
					PrintTree($$);
                                }
	|	expr '+' expr	{       Init (&$$, "add");
                                        $$->firstChild = $1;
                                        $1->nextSibling = $3;
					PrintTree($$);
                                }
	|	expr '*' expr	{       Init (&$$, "mul");
                                        $$->firstChild = $1;
                                        $1->nextSibling = $3;
					PrintTree($$);
                                }
	|	'-' expr %prec UMINUS	{       Init (&$$, "neg");
                                        	$$->firstChild = $2;
						PrintTree($$);
                                }
	|	'(' expr ')'	{	$$ = $2;
					PrintTree($$);
				}
	|	NUM		{	$$ = $1;
					PrintTree($$);
				}
	|	ID		{	$$ = $1;
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

void PrintTree (struct info* x) {
	printf("********************\n");
	Print (x, 0);
}
void Print (struct info* x, int level) {
	if (x == NULL) return;

	int i = 0;
	for (i = 0; i < level; i ++) printf ("    ");
	printf("%s\n", x->type);

	level++;
	Print (x->firstChild, level);

	level--;
	Print (x->nextSibling, level);
}

int main(void)
{

        yyparse();
        return 0;
}

/*
 * Project Deliverable 1: Compilers
 * @author
 * Suresh Rangaswamy
 * MT13017
 * 15 September 2014
 *
 * Added some of my own operators as well like unary_op to match (++|--),
 * const keyword, and C Pointers as well, like const char *c.
 *
 * Usage: (1.a) $ flex sample.lex
 *        (1.b) $ gcc lex.yy.c -lfl
 *        (1.c) $ ./a.out
 *            stdin> whatever you like
 *	      stdin> Ctrl-D
 *        (2) $ ./a.out < input_file
 *        (3) $ ./run.sh it will run all three commands as stated above
 *  and input will be input.c file
 *
 * Sample input.c is included with the package.
 */

%{

#include "y.tab.h"
extern struct info* yylval;

/**
 * Macro to print the desired output to the screen, prints the
 * operation/literal with the matched text in the input
 */
#define TOKEN(op) { PRINT return yytext[0]; }
#define RET(op)   { PRINT return op; }
#define INIT(op)  { PRINT Init(&yylval, yytext); return op; }
#define PRINT     printf("%d. %s\n", counter++, yytext);
//#define PRINT

int counter = 1;

%}

/* An Alphabet */
alpha				[a-zA-Z]

/* A Digit */
digit 				[0-9]

/* Alphanumeric */
alpha_num			[{alpha}{digit}]

/* Represents hexadeciaml digit */
hex_digit			({digit}|[a-fA-F])

/* A literal to wrap a hex-Number */
hex_literal			(0[xX]{hex_digit}+)

/* A deciaml Number */
decimal_literal			{digit}+

/* A wrapper for decimal & hexadeciaml Number */
int_literal			({decimal_literal}|{hex_literal})

/* Boolean value */
bool_literal			(true|false)

/* how a charater is represented */
char_literal			\'.\'

/* how a string is represented */
string_literal			\".*\"

/* variable names, function names, Pointers */
id				\*?_*{alpha}[a-zA-Z0-9_]*

/* wrapper for int, char, boolean */
literal				({int_literal}|{char_literal}|{bool_literal})

/* Set of characters from the input which needs to be skipped */
skip				[ \t\n]

/* type of a variable or return type of a function */
type				(const{skip}+)?(int|bool)

/* comma in multiple declaration */
comma               ,

/**
 * Now below is a list of rules that will be applied in the order
 * given as below.
 * Each rule is just a matching of already constructed
 * Regular Expressions explained above.
 */
%%
{skip}+				/* skip these tokens */
";"			        RET(SEMCOL);
","                 RET(COMMA)
class               RET(CLASS);
Program             RET(PROGRAM);
if			        RET(IF);
for                 RET(FOR);
else                RET(ELSE);
continue            RET(CONTINUE);
break               RET(BREAK);
int                 RET(INT);
bool                RET(BOOL);
void                RET(VOID);
callout             RET(CALLOUT);
"("                 RET(OP);
")"                 RET(CP);
"{"                 RET(OB);
"}"                 RET(CB);
"["                 RET(OS);
"]"                 RET(CS);
{bool_literal}		INIT(bool_literal);
{char_literal}		INIT(char_literal);
{int_literal}       INIT(int_literal);
{string_literal}	INIT(string_literal);
{id}			    INIT(ID);
"="                 RET(ASS);
"+="                RET(PASS);
"-="                RET(MASS);
"&&"                RET(AND);
"||"                RET(OR);
"<"                 RET(LT);
"<="                RET(LE);
">"                 RET(GT);
">="                RET(GE);
"=="                RET(EQ);
"!="                RET(NE);
"+"                 RET(PLUS);
"-"                 RET(MINUS);
"*"                 RET(MUL);
"/"                 RET(DIV);
"%"                 RET(MOD);
"!"                 RET(NOT);

%%

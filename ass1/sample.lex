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
/**
 * Macro to print the desired output to the screen, prints the
 * operation/literal with the matched text in the input
 */
#define TOKEN(op) printf("%d %s %s\n", ++count, (op), yytext);

/**
 * Macro to print the desired output to the screen
 */
#define PRINT() printf("%d %s\n", ++count, yytext);
%}
    /**To keep track or counter in the output.*/
	int count = 0;
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
char_literal			'{alpha}'

/* how a string is represented */
string_literal			\".*\"

/* variable names, function names, Pointers */
id				\*?_*{alpha}[a-zA-Z0-9_]*

/* Conditional operators */
cond_op				("&&"|"||")

/* Equality operators */
eq_op				("=="|"!=")

/* relational operators */
rel_op				("<"|">"|"<="|">=")

/* arithamatic operators */
arith_op			("+"|"-"|"*"|"/"|"%")

/* assignment operators */
assign_op			("="|"+="|"-="|"*="|"/="|"%=")

/* wrapper for binary operators */
bin_op				({arith_op}|{rel_op}|{eq_op}|{cond_op})

/* wrapper for unary operators */
unary_op            ("++"|"--")

/* wrapper for int, char, boolean */
literal				({int_literal}|{char_literal}|{bool_literal})

/* opening and closing brackets */
block				[{}]

/* Set of characters from the input which needs to be skipped */
skip				[ \t\n]

/* type of a variable or return type of a function */
type				(const{skip}+)?(int|bool)

/* End of a line or expression */
expr_end			;

/* wrapper for statement types */
statement			("if"|"for"|"return"|"break"|"continue")

/* class Name if found */
class_name          {alpha}[{alpha_num}_]*

/* brackets in expressions and in loops */
bracket             [()]

/* comma in multiple declaration */
comma               ,

/* if a method is called */
method_call         "callout"

/* method return type */
method_decl         "void"|{type}

/* to match class Program */
program             (class{skip}+Program)

/**
 * Now below is a list of rules that will be applied in the order
 * given as below.
 * Each rule is just a matching of already constructed
 * Regular Expressions explained above.
 */
%%
{skip}+				/* skip these tokens */
{expr_end}			PRINT();
{statement}			PRINT();
{type}				TOKEN("type");
{block}				PRINT();
{bracket}           PRINT();
{comma}             PRINT();
{method_decl}       TOKEN("method_decl");
{method_call}       TOKEN("method_call");
{program}           TOKEN("program");
{bool_literal}			TOKEN("bool_literal");
{char_literal}			TOKEN("char_literal");
{decimal_literal}       TOKEN("decimal_literal");
{hex_literal}           TOKEN("hex_literal");
{string_literal}		TOKEN("string_literal");
{id}				TOKEN("id");
{unary_op}          TOKEN("unary_op")
{assign_op}			TOKEN("assign_op");
{rel_op}			TOKEN("rel_op");
{eq_op}				TOKEN("eq_op");
{cond_op}			TOKEN("cond_op");
{arith_op}			TOKEN("arith_op");

%%

main()
{
  yylex();
}

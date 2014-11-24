%{
extern struct info* yylval;
%}


delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
id1	{letter}({letter}|{digit}|_)*
id	(_)*{id1}
number	{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
stringl \"[^\"\n]*\"

%%

{ws}
if	{ return IF; }
while	{ return WHILE; }
do	{ return DO; }
callout { return CALLOUT; }
{id}	{ Init(&yylval); strcpy(yylval->lexeme, yytext); return ID;}
{number}	{ Init(&yylval); strcpy(yylval->lexeme, yytext); return NUM; }
{stringl}       {Init(&yylval); strcpy(yylval->lexeme, yytext);   return string_literal; }
"<"	{ return yytext[0];}
"+"	{ return yytext[0]; }
"*"	{ return yytext[0]; }
"-"	{ return yytext[0]; }
"="	{ return yytext[0]; }
"{"	{ return yytext[0]; }
"}"	{ return yytext[0]; }
"("	{ return yytext[0]; }
")"     { return yytext[0]; }
";"	{ return yytext[0]; }
","	{ return yytext[0]; }
%%



/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    hex_literal = 258,
    id = 259,
    string_literal = 260,
    char_literal = 261,
    decimal_literal = 262,
    bool_literal = 263,
    assign_op = 264,
    arith_op = 265,
    eq_op = 266,
    rel_op = 267,
    cond_op = 268,
    CLASS = 269,
    PROGRAM = 270,
    VOID = 271,
    IF = 272,
    ELSE = 273,
    FOR = 274,
    RETURN = 275,
    BREAK = 276,
    CONTINUE = 277,
    CALLOUT = 278,
    INT = 279,
    BOOL = 280,
    UMINUS = 281
  };
#endif
/* Tokens.  */
#define hex_literal 258
#define id 259
#define string_literal 260
#define char_literal 261
#define decimal_literal 262
#define bool_literal 263
#define assign_op 264
#define arith_op 265
#define eq_op 266
#define rel_op 267
#define cond_op 268
#define CLASS 269
#define PROGRAM 270
#define VOID 271
#define IF 272
#define ELSE 273
#define FOR 274
#define RETURN 275
#define BREAK 276
#define CONTINUE 277
#define CALLOUT 278
#define INT 279
#define BOOL 280
#define UMINUS 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

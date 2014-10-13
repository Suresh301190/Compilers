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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    PROGRAM = 259,
    IF = 260,
    FOR = 261,
    ID = 262,
    VOID = 263,
    INT = 264,
    BOOL = 265,
    CALLOUT = 266,
    BREAK = 267,
    CONTINUE = 268,
    ELSE = 269,
    bool_literal = 270,
    char_literal = 271,
    string_literal = 272,
    int_literal = 273,
    PLUS = 274,
    MINUS = 275,
    MUL = 276,
    DIV = 277,
    MOD = 278,
    LT = 279,
    GT = 280,
    LE = 281,
    GE = 282,
    NE = 283,
    EQ = 284,
    ASS = 285,
    PASS = 286,
    MASS = 287,
    AND = 288,
    OR = 289,
    NOT = 290,
    OP = 291,
    CP = 292,
    OB = 293,
    CB = 294,
    OS = 295,
    CS = 296,
    UMINUS = 297
  };
#endif
/* Tokens.  */
#define CLASS 258
#define PROGRAM 259
#define IF 260
#define FOR 261
#define ID 262
#define VOID 263
#define INT 264
#define BOOL 265
#define CALLOUT 266
#define BREAK 267
#define CONTINUE 268
#define ELSE 269
#define bool_literal 270
#define char_literal 271
#define string_literal 272
#define int_literal 273
#define PLUS 274
#define MINUS 275
#define MUL 276
#define DIV 277
#define MOD 278
#define LT 279
#define GT 280
#define LE 281
#define GE 282
#define NE 283
#define EQ 284
#define ASS 285
#define PASS 286
#define MASS 287
#define AND 288
#define OR 289
#define NOT 290
#define OP 291
#define CP 292
#define OB 293
#define CB 294
#define OS 295
#define CS 296
#define UMINUS 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

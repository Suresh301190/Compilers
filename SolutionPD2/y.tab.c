/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "gram.y" /* yacc.c:339  */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>



int yylex(void);
void yyerror(char *);

struct info
{
	int nChild;
	char label[256];
	struct info* children;
	struct info* tail; //points beyond to last child
	struct info* next; //siblings
	char lexeme[256];
	
};

#define YYSTYPE struct info*


void AddChildrenOf (struct info* root, struct info* child);
void AddChild (struct info* root, struct info* child);
void InitTree (struct info** root, char* label);
void PrintTree (struct info* root);	


#line 98 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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



/* Copy the second part of user declarations.  */

#line 198 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,     2,     2,     2,
      38,    39,    29,    27,    37,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,    26,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    52,    55,    64,    75,    84,    94,   103,
     112,   115,   119,   124,   128,   138,   147,   151,   156,   160,
     165,   170,   177,   186,   189,   193,   195,   199,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   217,   221,
     227,   233,   235,   239,   241,   245,   249,   251,   254,   260,
     261,   262,   263,   264,   265,   266,   269,   270,   271,   272,
     273,   276,   277,   278,   281,   282,   285,   286
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "hex_literal", "id", "string_literal",
  "char_literal", "decimal_literal", "bool_literal", "assign_op",
  "arith_op", "eq_op", "rel_op", "cond_op", "CLASS", "PROGRAM", "VOID",
  "IF", "ELSE", "FOR", "RETURN", "BREAK", "CONTINUE", "CALLOUT", "INT",
  "BOOL", "'='", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'{'", "'}'", "';'",
  "'['", "']'", "','", "'('", "')'", "'!'", "$accept", "program",
  "field_decls", "next_field_decls", "method_decls", "method_args",
  "next_method_args", "block", "var_decls", "next_ids", "statements",
  "statement", "method_call", "call_args", "next_call_args",
  "callout_args", "location", "expr", "bin_op", "literal", "int_literal",
  "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    61,    43,    45,    42,
      47,   281,   123,   125,    59,    91,    93,    44,    40,    41,
      33
};
# endif

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -12,    24,     0,   -72,   120,    30,   -72,   -72,     6,
      13,    51,    46,   -72,   -72,     3,    47,    80,    42,    89,
      47,    61,    59,    97,   -72,   -72,   -72,   -72,    70,   -72,
      77,    16,   104,   120,    87,   111,   120,   112,    42,   -72,
      87,   -72,   -72,    47,   120,    47,   -72,   -72,   -72,   124,
     125,   120,    95,   152,   -72,   158,   160,   120,   112,   -72,
      29,   128,   163,    14,   134,   136,   135,   -72,   139,    95,
     140,   167,   146,   155,   111,   -72,   -72,   -72,    62,    62,
      62,   151,    62,   -72,    62,    62,   -72,   -72,    63,   -72,
     -72,   -72,   189,   -72,   -72,   -72,    62,   191,   162,   -72,
     129,   159,   110,    68,    62,   179,    98,   175,   -72,   -72,
     -72,   -72,   -72,   -72,    62,   165,   141,   146,    47,   -72,
     -72,    62,   -72,    87,   118,   -72,   175,    54,   161,   -72,
     -72,   -72,   110,   181,    62,   165,   122,   -72,   -72,    87,
     169,   -72,   -72,   -72,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    10,     0,    66,    67,     0,
       0,     0,     0,     2,     3,    13,    18,     0,     0,     0,
      18,     0,     0,     0,    65,    62,    64,    63,     0,    61,
       0,    13,     0,    10,     0,    20,    10,    13,     0,    11,
       0,     4,     6,    23,    16,     0,    17,     8,     9,     0,
       0,    16,    27,     0,    15,     0,     0,    10,    13,    14,
      47,     0,     0,     0,     0,     0,     0,    37,     0,    27,
       0,     0,    25,     0,    20,     5,     7,    12,     0,    41,
       0,     0,     0,    33,     0,     0,    50,    49,     0,    55,
      35,    36,     0,    21,    26,    29,     0,     0,     0,    19,
       0,     0,    43,     0,     0,    51,     0,    53,    56,    59,
      58,    60,    57,    34,     0,    46,     0,    25,    23,    48,
      38,     0,    40,     0,     0,    54,    52,     0,     0,    28,
      24,    22,    43,    30,     0,    46,    46,    39,    42,     0,
       0,    44,    45,    31,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -10,   -27,   127,   184,   131,   -34,    88,    90,
     142,   -72,   -50,   -72,    76,   -11,   -25,   -71,   -72,   192,
      -3,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    21,    10,    22,    46,    67,    52,    98,
      68,    69,    86,   101,   122,   128,    87,    88,   114,    89,
      29,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    23,    70,     3,    39,    23,    51,   100,   102,   103,
      49,   105,    17,   106,   107,    30,     1,    24,    60,    70,
      25,    26,    27,    41,     4,   116,    47,    71,    53,    55,
      56,    77,     5,   124,    12,    50,    55,    66,    18,    13,
      19,    20,    82,   126,    71,    24,    14,    75,    83,    26,
     132,    38,    84,    19,    85,    15,   136,    24,    60,   135,
      25,    26,    27,   140,    78,    24,    60,    79,    25,    26,
      27,     7,     8,   108,   109,   110,   111,    66,   108,   109,
     110,   111,    82,    24,    16,    66,    25,    26,    27,   133,
      82,   112,    84,    31,    85,    33,   112,   113,    34,    60,
      84,    35,    85,    53,    36,   143,   144,   123,   108,   109,
     110,   111,    61,    37,    62,    63,    64,    65,    66,    43,
     108,   109,   110,   111,   141,   142,   112,    43,   108,   109,
     110,   111,   108,   109,   110,   111,     6,   125,   112,   108,
     109,   110,   111,    40,     7,     8,   112,   121,    45,    19,
     112,   108,   109,   110,   111,   134,    72,   112,    57,   127,
      42,    58,    73,    48,    74,   119,    80,    81,    90,   112,
      91,    54,    93,    92,    95,   129,    96,   104,    59,   108,
     109,   110,   111,    97,    76,   108,   109,   110,   111,   108,
     109,   110,   111,    20,   115,   117,   118,   112,   120,   139,
     137,    43,   127,   112,    32,    99,   131,   130,   138,    28,
       0,    94
};

static const yytype_int16 yycheck[] =
{
      34,    16,    52,    15,    31,    20,    40,    78,    79,    80,
      37,    82,     9,    84,    85,    18,    14,     3,     4,    69,
       6,     7,     8,    33,     0,    96,    36,    52,    43,    44,
      45,    58,    32,   104,     4,    38,    51,    23,    35,    33,
      37,    38,    28,   114,    69,     3,    33,    57,    34,     7,
     121,    35,    38,    37,    40,     4,   127,     3,     4,     5,
       6,     7,     8,   134,    35,     3,     4,    38,     6,     7,
       8,    24,    25,    10,    11,    12,    13,    23,    10,    11,
      12,    13,    28,     3,    38,    23,     6,     7,     8,   123,
      28,    28,    38,     4,    40,    34,    28,    34,    39,     4,
      38,     4,    40,   118,    34,   139,   140,    39,    10,    11,
      12,    13,    17,    36,    19,    20,    21,    22,    23,    32,
      10,    11,    12,    13,   135,   136,    28,    32,    10,    11,
      12,    13,    10,    11,    12,    13,    16,    39,    28,    10,
      11,    12,    13,    39,    24,    25,    28,    37,    37,    37,
      28,    10,    11,    12,    13,    37,     4,    28,    34,    37,
      33,    36,     4,    36,     4,    36,    38,     4,    34,    28,
      34,    44,    33,    38,    34,    34,     9,    26,    51,    10,
      11,    12,    13,    37,    57,    10,    11,    12,    13,    10,
      11,    12,    13,    38,     5,     4,    34,    28,    39,    18,
      39,    32,    37,    28,    20,    74,   118,   117,   132,    17,
      -1,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    42,    15,     0,    32,    16,    24,    25,    43,
      45,    62,     4,    33,    33,     4,    38,     9,    35,    37,
      38,    44,    46,    62,     3,     6,     7,     8,    60,    61,
      61,     4,    46,    34,    39,     4,    34,    36,    35,    44,
      39,    43,    45,    32,    48,    37,    47,    43,    45,    44,
      61,    48,    49,    62,    45,    62,    62,    34,    36,    45,
       4,    17,    19,    20,    21,    22,    23,    48,    51,    52,
      53,    57,     4,     4,     4,    43,    45,    44,    35,    38,
      38,     4,    28,    34,    38,    40,    53,    57,    58,    60,
      34,    34,    38,    33,    51,    34,     9,    37,    50,    47,
      58,    54,    58,    58,    26,    58,    58,    58,    10,    11,
      12,    13,    28,    34,    59,     5,    58,     4,    34,    36,
      39,    37,    55,    39,    58,    39,    58,    37,    56,    34,
      50,    49,    58,    48,    37,     5,    58,    39,    55,    18,
      58,    56,    56,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    44,    44,    44,    45,    45,    45,    46,    46,    47,
      47,    48,    49,    49,    50,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    60,    60,    60,    61,    61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     5,     5,     8,     5,     8,     6,     6,
       0,     3,     6,     0,     7,     7,     0,     3,     0,     4,
       0,     4,     5,     0,     3,     0,     2,     0,     4,     2,
       5,     7,     7,     2,     3,     2,     2,     1,     4,     5,
       2,     0,     3,     0,     3,     3,     0,     1,     4,     1,
       1,     2,     3,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 51 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "program"); AddChildrenOf((yyval), (yyvsp[-1])); PrintTree ((yyval)); }
#line 1385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "program"); AddChildrenOf((yyval), (yyvsp[-1])); PrintTree ((yyval)); }
#line 1391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 55 "gram.y" /* yacc.c:1646  */
    {	InitTree (&(yyval), "field_decls"); 
										struct info* field_decl = NULL;
										InitTree (&field_decl, "field_decl");
										AddChild(field_decl, (yyvsp[-4]));
										AddChild(field_decl, (yyvsp[-3]));
										AddChildrenOf(field_decl, (yyvsp[-2]));
										AddChild((yyval), field_decl);
										AddChildrenOf((yyval), (yyvsp[0]));
									}
#line 1405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 64 "gram.y" /* yacc.c:1646  */
    {	InitTree (&(yyval), "field_decls"); 
												struct info* field_decl = NULL;
												InitTree (&field_decl, "field_decl");
												AddChild(field_decl, (yyvsp[-7]));
												AddChild(field_decl, (yyvsp[-6]));
												AddChild(field_decl, (yyvsp[-4]));
												AddChildrenOf(field_decl, (yyvsp[-2]));
												AddChild((yyval), field_decl);
												AddChildrenOf((yyval), (yyvsp[0]));
											}
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 75 "gram.y" /* yacc.c:1646  */
    {	InitTree (&(yyval), "field_decls"); 
										struct info* field_decl = NULL;
										InitTree (&field_decl, "field_decl");
										AddChild(field_decl, (yyvsp[-4]));
										AddChild(field_decl, (yyvsp[-3]));
										AddChildrenOf(field_decl, (yyvsp[-2]));
										AddChild((yyval), field_decl);
										AddChildrenOf((yyval), (yyvsp[0]));
									}
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 84 "gram.y" /* yacc.c:1646  */
    {	InitTree (&(yyval), "field_decls"); 
												struct info* field_decl = NULL;
												InitTree (&field_decl, "field_decl");
												AddChild(field_decl, (yyvsp[-7]));
												AddChild(field_decl, (yyvsp[-6]));
												AddChild(field_decl, (yyvsp[-4]));
												AddChildrenOf(field_decl, (yyvsp[-2]));
												AddChild((yyval), field_decl);
												AddChildrenOf((yyval), (yyvsp[0]));
											}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "gram.y" /* yacc.c:1646  */
    {	InitTree (&(yyval), "field_decls");
														struct info* field_decl = NULL;
														InitTree (&field_decl, "field_decl");
														AddChild(field_decl, (yyvsp[-5]));
														AddChild(field_decl, (yyvsp[-4]));
														AddChild(field_decl, (yyvsp[-2]));
														AddChild((yyval), field_decl);
														AddChild((yyval), (yyvsp[0]));
													}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 103 "gram.y" /* yacc.c:1646  */
    {       InitTree (&(yyval), "field_decls");
                                                                                                                struct info *field_decl = NULL;
                                                                                                                InitTree (&field_decl, "field_decl");
                                                                                                                AddChild(field_decl, (yyvsp[-5]));
                                                                                                                AddChild(field_decl, (yyvsp[-4]));
                                                                                                                AddChild(field_decl, (yyvsp[-2]));
                                                                                                                AddChild((yyval), field_decl);
                                                                                                                AddChild((yyval), (yyvsp[0]));
                                                                                                        }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 112 "gram.y" /* yacc.c:1646  */
    {	InitTree (&(yyval), "field_decls"); }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 115 "gram.y" /* yacc.c:1646  */
    {	InitTree (&(yyval), "next_field_decls");
									AddChild((yyval), (yyvsp[-1]));
									AddChildrenOf((yyval), (yyvsp[0]));
								}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "gram.y" /* yacc.c:1646  */
    {	InitTree (&(yyval), "next_field_decls");
											AddChild((yyval), (yyvsp[-4]));
											AddChild((yyval), (yyvsp[-2]));
											AddChildrenOf((yyval), (yyvsp[0]));
										}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "gram.y" /* yacc.c:1646  */
    {	InitTree (&(yyval), "next_field_decls");	}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "method_decls");
										struct info* method_decl = NULL;
										InitTree(&method_decl, "method_decl");
										AddChild(method_decl, (yyvsp[-6]));
										AddChild(method_decl, (yyvsp[-5]));
										AddChildrenOf(method_decl, (yyvsp[-3]));
										AddChild(method_decl, (yyvsp[-1]));
										AddChild((yyval), method_decl);
										AddChildrenOf((yyval), (yyvsp[0]));
									}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 138 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "method_decls");
										struct info* method_decl = NULL;
										InitTree(&method_decl, "method_decl");
										AddChild(method_decl, (yyvsp[-5]));
										AddChildrenOf(method_decl, (yyvsp[-3]));
										AddChild(method_decl, (yyvsp[-1]));
										AddChild((yyval), method_decl);
										AddChildrenOf((yyval), (yyvsp[0]));
									}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 147 "gram.y" /* yacc.c:1646  */
    {    InitTree(&(yyval), "method_decls");	}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 151 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "method_args");
								AddChild((yyval), (yyvsp[-2]));
								AddChild((yyval), (yyvsp[-1]));
								AddChildrenOf((yyval), (yyvsp[0]));
							}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 156 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "method_args");	}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 160 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "next_method_args");
									AddChild((yyval), (yyvsp[-2]));
									AddChild((yyval), (yyvsp[-1]));
									AddChildrenOf((yyval), (yyvsp[0]));
								}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 165 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "next_method_args");	}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 170 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "block");
							AddChildrenOf((yyval), (yyvsp[-2]));
							AddChildrenOf((yyval), (yyvsp[-1]));
						}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 177 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "var_decls");
								struct info* var_decl = NULL;
								InitTree(&var_decl, "var_decl");
								AddChild(var_decl, (yyvsp[-4]));
								AddChild(var_decl, (yyvsp[-3]));
								AddChildrenOf(var_decl, (yyvsp[-2]));
								AddChild((yyval), var_decl);
								AddChildrenOf((yyval), (yyvsp[0]));
							}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 186 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "var_decls");	}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "next_ids");
						AddChild((yyval), (yyvsp[-1]));
						AddChildrenOf((yyval), (yyvsp[0]));
					}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 193 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "next_ids");	}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 195 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "statements");
							AddChild((yyval), (yyvsp[-1]));
							AddChildrenOf((yyval), (yyvsp[0]));
						}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 199 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "statements");	}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 204 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "assign_stmt"); AddChild((yyval), (yyvsp[-3])); AddChild((yyval), (yyvsp[-2])); AddChild((yyval), (yyvsp[-1]));	 }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 205 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "call_stmt"); AddChild((yyval), (yyvsp[-1])); 	}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 206 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "if_stmt"); AddChild((yyval), (yyvsp[-2])); AddChild((yyval), (yyvsp[0])); 	}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 207 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "if_stmt"); AddChild((yyval), (yyvsp[-4])); AddChild((yyval), (yyvsp[-2])); AddChild((yyval), (yyvsp[0]));	}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 208 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "for_stmt"); AddChild((yyval), (yyvsp[-5])); AddChild((yyval), (yyvsp[-2])); AddChild((yyval), (yyvsp[-1])); AddChild((yyval), (yyvsp[0]));	}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 209 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "ret_stmt"); }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 210 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "ret_stmt"); AddChild((yyval), (yyvsp[-1])); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 211 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "brk_stmt"); 	}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 212 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "cnt_stmt"); 	}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 213 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "blk_stmt"); AddChild((yyval), (yyvsp[0])); 	}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 217 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "method_call");
							AddChild((yyval), (yyvsp[-3]));
							AddChildrenOf((yyval), (yyvsp[-1]));
						}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 221 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "callout_call");
										AddChild((yyval), (yyvsp[-2]));
										AddChildrenOf((yyval), (yyvsp[-1]));  
										
									}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 227 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "call_args");
							AddChild((yyval), (yyvsp[-1]));
							AddChildrenOf((yyval), (yyvsp[0]));
						
						}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 233 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "call_args"); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 235 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "next_call_args");
								AddChild((yyval), (yyvsp[-1]));
								AddChildrenOf((yyval), (yyvsp[0]));
							}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 239 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "next_call_args");	 }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 241 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "callout_args");
								AddChild((yyval), (yyvsp[-1]));
								AddChildrenOf((yyval), (yyvsp[0]));
							}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 245 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "callout_args");
								AddChild((yyval), (yyvsp[-1]));
								AddChildrenOf((yyval), (yyvsp[0]));
							}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 249 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "callout_args"); }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 251 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "location");
					AddChild((yyval), (yyvsp[0]));
				}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 254 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "arr_loc");
						AddChild((yyval), (yyvsp[-3]));
						AddChild((yyval), (yyvsp[-1]));
					}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 260 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "loc_expr"); AddChild((yyval), (yyvsp[0]));	}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 261 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "call_expr"); AddChild((yyval), (yyvsp[0]));	}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 262 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "neg_expr"); AddChild((yyval), (yyvsp[0]));	}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 263 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "bin_expr"); AddChild((yyval), (yyvsp[-2]));	AddChild((yyval), (yyvsp[-1])); AddChild((yyval), (yyvsp[0])); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 264 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "not_expr"); AddChild((yyval), (yyvsp[0]));	}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 265 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "nest_expr"); AddChild((yyval), (yyvsp[-1]));	}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 266 "gram.y" /* yacc.c:1646  */
    {	InitTree(&(yyval), "literal_expr"); AddChild((yyval), (yyvsp[0]));	}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 269 "gram.y" /* yacc.c:1646  */
    {InitTree (&(yyval), "bin_arith"); AddChild((yyval), (yyvsp[0]));	}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 270 "gram.y" /* yacc.c:1646  */
    {InitTree (&(yyval), "bin_arith"); AddChild((yyval), (yyvsp[0]));	}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 271 "gram.y" /* yacc.c:1646  */
    {InitTree (&(yyval), "bin_rel"); AddChild((yyval), (yyvsp[0]));	}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 272 "gram.y" /* yacc.c:1646  */
    {InitTree (&(yyval), "bin_eq"); AddChild((yyval), (yyvsp[0]));	}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 273 "gram.y" /* yacc.c:1646  */
    {InitTree (&(yyval), "bin_cond"); AddChild((yyval), (yyvsp[0]));	}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 276 "gram.y" /* yacc.c:1646  */
    { InitTree (&(yyval), "int_const"); AddChild((yyval), (yyvsp[0])); }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 277 "gram.y" /* yacc.c:1646  */
    {InitTree (&(yyval), "char_const"); strcpy((yyval)->lexeme, (yyvsp[0])->lexeme); }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 278 "gram.y" /* yacc.c:1646  */
    { InitTree (&(yyval), "bool_const"); strcpy((yyval)->lexeme, (yyvsp[0])->lexeme); }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 281 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "decimal_int"); strcpy((yyval)->lexeme, (yyvsp[0])->lexeme);	}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 282 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "hex_int"); strcpy((yyval)->lexeme, (yyvsp[0])->lexeme);	}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 285 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "type"); strcpy((yyval)->lexeme, "int");}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 286 "gram.y" /* yacc.c:1646  */
    { InitTree(&(yyval), "type"); strcpy((yyval)->lexeme, "bool");}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1903 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 291 "gram.y" /* yacc.c:1906  */

#include "lex.yy.c"

void yyerror (char *s) 
{
   
}

void AddChildrenOf (struct info* root, struct info* child)
{
	if (child->children == NULL) return;

	if (root->tail == NULL)  {
		root->children = child->children;
		root->tail = child->tail;
		root->nChild += child->nChild;
		return;
	} else {
		root->tail->next = child->children;
		root->tail = child->tail;
		root->nChild += child->nChild;
		return;
	}

}

void AddChild (struct info* root, struct info* child)
{
	if (root->tail == NULL) {
		root->children = child;
		root->tail = child;
		root->nChild ++;
		return;
	} else {
		root->tail->next = child;
		root->tail = child;
		root->nChild ++;
		return;
	}

}

void InitTree (struct info** root, char* label)
{
	
	*root = (struct info*)malloc(sizeof(struct info));
	strcpy((*root)->label, label);
	strcpy((*root)->lexeme, "");
	(*root)->nChild = 0;
	(*root)->children = NULL;
	(*root)->tail = NULL;
	(*root)->next = NULL;
}

void PrintTree (struct info* root)
{
	Print(root, 0);
}

void Print (struct info* root, int level) {
	
	int l;
	for ( l = 0; l < level; l ++) {
		printf ("    ");
	}

	printf ("%s\n", root->label);
	if (strcmp (root->lexeme, "") != 0)
	{
		for ( l = 0; l < level; l ++) {
			printf ("    ");
		}
		printf( "\t%s\n", root->lexeme);
	}
	//printf (" %d\n", root->nChild);

	struct info* children = root->children;
	level++;
	while (children != NULL)
	{
		
		Print(children, level);
		children = children->next;
	}
}



int main(void) 
{
	//yylval = (char*) malloc(1024 * sizeof(char));

	yyparse();
	return 0;
}
















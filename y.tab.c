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
#line 1 "sample.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum dataType { integer, invalid, boolean, character, string, array, function, search, intArray, boolArray};
//invalid - symbols that do not have a type

struct symbol {
    char name[256];
    enum dataType type;
    struct symbol* arraySize;
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
    struct symbol* sym;
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
        struct backpatchList* typelist;
};

#define YYSTYPE struct info*

void yyerror (char const *s);

int IncLabel();

int GetLabel();

struct symbol* InstallLabel();

void Backpatch(struct backpatchList* l, struct symbol* s);

void MergeBackpatch(struct backpatchList** x, struct backpatchList* y);

void InsertTarget(struct backpatchList** x, struct quadtab* y);

void InsertTargetSym(struct backpatchList** x, struct symbol* s);

void PrintQuads();

void PushSymTab();

void PopSymTab();

struct symbol* AddSym (char* name, enum dataType ty);

void UpdateType(struct backpatchList* x, enum dataType ty);

struct symbol* GenSym(enum dataType ty);

struct quadtab* GenQuad(char* opcode, struct symbol* src1, struct symbol* src2, struct symbol* dst) ;

struct symbol* getFindSym(char* lexeme, enum dataType ty);

void PrintSymbols();

struct symbol* FindSymbol(char* lexeme);

struct symbol* FindSymbolBlock(char* lexeme);

void rel_operation(char *op, struct info* SS, struct info* S1, struct info* S3);

void PrintQuad (struct quadtab* q);

void PrintList (struct backpatchList* l) ;

struct info* Init_PD2(struct info** x, char* y);
void PrintTree (struct info* x);
void Print (struct info* x, int l);
void PrintTree2 (struct info* x);


#line 174 "y.tab.c" /* yacc.c:339  */

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
    RETURN = 270,
    bool_literal = 271,
    char_literal = 272,
    string_literal = 273,
    int_literal = 274,
    COMMA = 275,
    SEMCOL = 276,
    PLUS = 277,
    MINUS = 278,
    MUL = 279,
    DIV = 280,
    MOD = 281,
    LT = 282,
    GT = 283,
    LE = 284,
    GE = 285,
    NE = 286,
    EQ = 287,
    ASS = 288,
    PASS = 289,
    MASS = 290,
    AND = 291,
    OR = 292,
    NOT = 293,
    OP = 294,
    CP = 295,
    OB = 296,
    CB = 297,
    OS = 298,
    CS = 299,
    UMINUS = 300
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
#define RETURN 270
#define bool_literal 271
#define char_literal 272
#define string_literal 273
#define int_literal 274
#define COMMA 275
#define SEMCOL 276
#define PLUS 277
#define MINUS 278
#define MUL 279
#define DIV 280
#define MOD 281
#define LT 282
#define GT 283
#define LE 284
#define GE 285
#define NE 286
#define EQ 287
#define ASS 288
#define PASS 289
#define MASS 290
#define AND 291
#define OR 292
#define NOT 293
#define OP 294
#define CP 295
#define OB 296
#define CB 297
#define OS 298
#define CS 299
#define UMINUS 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 312 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   133,   141,   144,   158,   173,   179,   185,
     196,   200,   206,   212,   216,   220,   230,   234,   238,   242,
     246,   251,   258,   258,   272,   280,   284,   291,   297,   301,
     307,   318,   323,   324,   330,   338,   348,   354,   358,   360,
     362,   367,   373,   376,   379,   385,   387,   393,   400,   407,
     413,   415,   421,   425,   428,   432,   435,   437,   443,   445,
     451,   453,   458,   465,   467,   472,   477,   482,   489,   491,
     497,   505,   507,   513,   519,   527,   529,   534,   539,   541,
     549,   555,   558,   562,   566,   572
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "PROGRAM", "IF", "FOR", "ID",
  "VOID", "INT", "BOOL", "CALLOUT", "BREAK", "CONTINUE", "ELSE", "RETURN",
  "bool_literal", "char_literal", "string_literal", "int_literal", "COMMA",
  "SEMCOL", "PLUS", "MINUS", "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE",
  "NE", "EQ", "ASS", "PASS", "MASS", "AND", "OR", "NOT", "OP", "CP", "OB",
  "CB", "OS", "CS", "UMINUS", "$accept", "program", "feild_methods",
  "feild_method", "type", "ARR_IDS", "ARR_ID", "args", "args1", "arg",
  "block", "$@1", "var_decls", "var_decl", "vars", "var", "stmts", "stmt",
  "method_call", "Rexpr", "fexpr", "expr_a", "location", "expr_rec",
  "expr_rec2", "expr_or", "expr_and", "expr_eq", "expr_rel", "expr_pm",
  "expr_mdm", "factor", "literal", "M", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -137

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-137)))

#define YYTABLE_NINF -52

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,    20,    61,    22,  -137,  -137,     0,    66,  -137,  -137,
    -137,  -137,    73,    46,     2,    47,   100,    30,    47,    90,
      89,   104,   105,    74,    93,    72,    97,  -137,  -137,  -137,
    -137,    98,    78,    76,  -137,  -137,  -137,    80,    47,  -137,
     103,  -137,  -137,    80,    97,  -137,  -137,    93,    81,  -137,
     106,  -137,  -137,  -137,  -137,    47,   108,  -137,    82,   119,
     109,  -137,    21,  -137,   108,  -137,    92,   122,    35,    94,
     111,   113,    96,    48,    48,    65,  -137,  -137,   115,   116,
     -19,   101,   107,   -28,    62,   -11,    51,  -137,  -137,  -137,
      65,   112,   120,    65,    65,   121,  -137,  -137,    65,   123,
      99,  -137,  -137,   110,  -137,  -137,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,   114,    65,    65,   126,   117,   118,   124,   125,
    -137,    65,  -137,   101,   101,   101,   107,   -28,    62,    62,
     -11,   -11,   -11,   -11,    51,    51,  -137,  -137,  -137,  -137,
    -137,    80,    65,  -137,  -137,    64,  -137,  -137,   127,    80,
    -137,   126,  -137,   133,  -137,  -137,    80,  -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,    10,    11,
       2,     3,     0,     0,    13,    17,     0,     0,    17,     0,
       0,     0,     0,     0,    19,    14,    13,    84,    83,    82,
      81,     0,     0,     0,     8,    21,    20,     0,     0,    16,
       0,    12,     9,     0,    13,    22,     6,    19,     0,     5,
       0,    25,    18,    15,     7,    31,    28,    24,    85,     0,
       0,    23,     0,    29,    28,    26,     0,     0,    80,     0,
       0,     0,    43,     0,     0,     0,    32,    30,     0,     0,
       0,    45,    56,    58,    60,    63,    68,    71,    78,    27,
       0,     0,     0,    53,     0,     0,    38,    39,     0,     0,
      80,    77,    76,     0,    40,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
      37,     0,    75,    46,    47,    48,    57,    59,    62,    61,
      64,    65,    66,    67,    69,    70,    72,    73,    74,    85,
      44,     0,     0,    52,    49,    79,    41,    42,     0,     0,
      36,    55,    79,    34,    54,    85,     0,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,  -137,  -137,   -21,  -137,   130,   102,   -37,
     -43,  -137,  -137,  -137,    77,  -137,  -137,  -137,  -137,  -137,
    -137,   -73,  -137,  -137,   -10,    -6,    43,    45,   -81,   -20,
     -12,   -67,   136,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    11,    12,    20,    26,    23,    39,    24,
      46,    51,    55,    57,    60,    64,    58,    77,    78,    99,
      92,    79,    80,   126,   153,    81,    82,    83,    84,    85,
      86,    87,    88,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    47,   103,   111,   112,    41,   101,   102,     7,     8,
       9,   117,   118,   159,   106,   107,   108,   122,    56,    76,
     125,   127,    16,    50,     3,   129,    66,    67,    68,   166,
     138,   139,    69,    70,    71,    17,    72,    27,    28,    29,
      30,    18,    10,     1,    73,    19,    27,    28,    29,    30,
     150,   151,   146,   147,   148,   100,    21,    22,   158,    74,
      75,     4,    45,     5,    27,    28,    29,    30,   -50,   -50,
     -50,    73,    68,    13,    93,   119,   120,   121,    94,   161,
      14,    27,    28,    29,    30,    15,    74,    75,    73,   113,
     114,   115,   116,   140,   141,   142,   143,   -51,   -51,   -51,
     133,   134,   135,    74,    75,   144,   145,    25,   160,    33,
      34,    35,    36,    38,    37,    40,   163,    16,    43,    42,
      44,    45,    48,   167,    61,    53,    63,    54,    59,    91,
      65,    90,    96,    95,    97,    98,   104,   105,   109,   128,
     124,    89,   131,   110,   130,   123,   152,   165,    32,    52,
     132,   164,   136,    31,   149,   137,     0,   154,     0,     0,
       0,     0,   155,     0,   156,   157,     0,     0,     0,     0,
       0,   162
};

static const yytype_int16 yycheck[] =
{
      43,    38,    75,    31,    32,    26,    73,    74,     8,     9,
      10,    22,    23,   149,    33,    34,    35,    90,    55,    62,
      93,    94,    20,    44,     4,    98,     5,     6,     7,   165,
     111,   112,    11,    12,    13,    33,    15,    16,    17,    18,
      19,    39,    42,     3,    23,    43,    16,    17,    18,    19,
     123,   124,   119,   120,   121,     7,     9,    10,   131,    38,
      39,     0,    41,    41,    16,    17,    18,    19,    33,    34,
      35,    23,     7,     7,    39,    24,    25,    26,    43,   152,
       7,    16,    17,    18,    19,    39,    38,    39,    23,    27,
      28,    29,    30,   113,   114,   115,   116,    33,    34,    35,
     106,   107,   108,    38,    39,   117,   118,     7,   151,    19,
      21,     7,     7,    20,    40,    43,   159,    20,    40,    21,
      44,    41,    19,   166,    42,    44,     7,    21,    20,     7,
      21,    39,    21,    39,    21,    39,    21,    21,    37,    18,
      20,    64,    43,    36,    21,    33,    20,    14,    18,    47,
      40,   161,   109,    17,    40,   110,    -1,    40,    -1,    -1,
      -1,    -1,    44,    -1,    40,    40,    -1,    -1,    -1,    -1,
      -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    47,     4,     0,    41,    48,     8,     9,    10,
      42,    49,    50,     7,     7,    39,    20,    33,    39,    43,
      51,     9,    10,    53,    55,     7,    52,    16,    17,    18,
      19,    78,    53,    19,    21,     7,     7,    40,    20,    54,
      43,    51,    21,    40,    44,    41,    56,    55,    19,    56,
      51,    57,    54,    44,    21,    58,    55,    59,    62,    20,
      60,    42,    79,     7,    61,    21,     5,     6,     7,    11,
      12,    13,    15,    23,    38,    39,    56,    63,    64,    67,
      68,    71,    72,    73,    74,    75,    76,    77,    78,    60,
      39,     7,    66,    39,    43,    39,    21,    21,    39,    65,
       7,    77,    77,    67,    21,    21,    33,    34,    35,    37,
      36,    31,    32,    27,    28,    29,    30,    22,    23,    24,
      25,    26,    67,    33,    20,    67,    69,    67,    18,    67,
      21,    43,    40,    71,    71,    71,    72,    73,    74,    74,
      75,    75,    75,    75,    76,    76,    77,    77,    77,    40,
      67,    67,    20,    70,    40,    44,    40,    40,    67,    79,
      56,    67,    44,    56,    70,    14,    79,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      50,    50,    51,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    57,    56,    58,    58,    59,    60,    60,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    65,    65,    66,    67,    67,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    74,    75,    75,
      75,    76,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     0,     6,     6,     7,     4,     5,
       1,     1,     3,     0,     1,     4,     2,     0,     3,     0,
       2,     2,     0,     5,     2,     0,     3,     3,     0,     1,
       3,     0,     1,     2,     6,     9,     5,     3,     2,     2,
       2,     4,     3,     0,     3,     1,     3,     3,     3,     4,
       1,     4,     2,     0,     3,     0,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     2,     2,     1,     4,
       1,     1,     1,     1,     1,     0
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
#line 126 "sample.y" /* yacc.c:1646  */
    {	Init_PD2 (&(yyval), "program");
                                                (yyval)->firstChild = (yyvsp[-1]);
                                                PrintTree2((yyval));
                                                PrintQuads();
                                            }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 133 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "feild_methods");
                                                    if((yyvsp[-1])){
                                                        (yyval)->firstChild = (yyvsp[-1]);
                                                        (yyvsp[-1])->nextSibling = (yyvsp[0]);
                                                    }
                                                    else
                                                        (yyval)->firstChild = (yyvsp[0]);
                                                }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 141 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "");  }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 144 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "method_decl");
                                (yyval)->firstChild = (yyvsp[-4]);
                                if((yyvsp[-2])) {
                                    (yyvsp[-4])->nextSibling = (yyvsp[-2]);
                                    (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                }
                                else
                                    (yyvsp[-4])->nextSibling = (yyvsp[0]);

                                MergeBackpatch(&((yyval)->nextlist), (yyvsp[0])->nextlist);
                                struct symbol* s = InstallLabel();
                                GenQuad("halt", NULL, NULL, NULL);
                                Backpatch((yyval)->nextlist, s);
                            }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 158 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "method_decl");
                                        (yyval)->firstChild = (yyvsp[-4]);
                                        if((yyvsp[-2])) {
                                            (yyvsp[-4])->nextSibling = (yyvsp[-2]);
                                            (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                        }
                                        else
                                            (yyvsp[-4])->nextSibling = (yyvsp[0]);

                                        AddSym((yyvsp[-4])->lexeme, function);
                                        MergeBackpatch(&((yyval)->nextlist), (yyvsp[0])->nextlist);
                                        struct symbol* s = InstallLabel();
                                        GenQuad("halt", NULL, NULL, NULL);
                                        Backpatch((yyval)->nextlist, s);
                                    }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 173 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "array");
                                            (yyval)->firstChild = (yyvsp[-6]);
                                            (yyvsp[-6])->nextSibling = (yyvsp[-5]);
                                            (yyvsp[-5])->nextSibling = (yyvsp[-3]);
                                            (yyvsp[-3])->nextSibling = (yyvsp[-1]);
                                        }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 179 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "feild_decl");
                                    (yyval)->firstChild = (yyvsp[-3]);
                                    (yyvsp[-3])->nextSibling = (yyvsp[-2]);
                                    (yyvsp[-2])->nextSibling = (yyvsp[-1]);
                                    UpdateType((yyval)->nextlist, (yyvsp[-3])->type);
                                }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 185 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "feild_decl");
                                        (yyval)->firstChild = (yyvsp[-4]);
                                        (yyvsp[-4])->nextSibling = (yyvsp[-3]);
                                        (yyvsp[-3])->nextSibling = (yyvsp[-1]);
                                        //strcpy($3->PD2_type, "assign_op");
                                        (yyval)->sym = AddSym((yyvsp[-3])->lexeme, (yyvsp[-4])->type);
                                        (yyval)->type = (yyvsp[-4])->type;
                                        GenQuad("=", (yyvsp[-1])->sym, NULL, (yyval)->sym);
                                    }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 196 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "int");
                    (yyval)->type = integer;
                    //$$->firstChild = $1;
                }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 200 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "bool");
                    (yyval)->type = boolean;
                    //$$->firstChild = $1;
                }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 206 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "feild");
                                        (yyval)->firstChild = (yyvsp[-1]);
                                        (yyvsp[-1])->nextSibling = (yyvsp[0]);
                                        MergeBackpatch(&((yyval)->nextlist), (yyvsp[-1])->nextlist);
                                        MergeBackpatch(&((yyval)->nextlist), (yyvsp[0])->nextlist);
                                    }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 212 "sample.y" /* yacc.c:1646  */
    {   (yyval) = NULL;
            }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 216 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[0]);
                    (yyval)->sym = AddSym((yyvsp[0])->lexeme, invalid);
                    InsertTargetSym(&((yyval)->typelist), (yyval)->sym);
                }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 220 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "array");
                                    (yyval)->firstChild = (yyvsp[-3]);
                                    (yyvsp[-3])->nextSibling = (yyvsp[-1]);
                                    PrintTree((yyval));
                                    (yyval)->sym = AddSym((yyvsp[-3])->lexeme, array);
                                    (yyval)->sym->arraySize = (yyvsp[-1])->sym;
                                    InsertTargetSym(&((yyval)->typelist), (yyval)->sym);
                                }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 230 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "args");
                            (yyval)->firstChild = (yyvsp[-1]);
                            (yyvsp[-1])->nextSibling = (yyvsp[0]);
                        }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 234 "sample.y" /* yacc.c:1646  */
    {   (yyval) = NULL;
            }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 238 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "args");
                                (yyval)->firstChild = (yyvsp[-1]);
                                (yyvsp[-1])->nextSibling = (yyvsp[0]);
                            }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 242 "sample.y" /* yacc.c:1646  */
    {   (yyval) = NULL;
            }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 246 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "bool");
                    (yyval)->firstChild = (yyvsp[0]);
                    (yyval)->sym = AddSym((yyvsp[0])->lexeme, boolean);
                    (yyval)->type = boolean;
                }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 251 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "int");
                    (yyval)->firstChild = (yyvsp[0]);
                    (yyval)->sym = AddSym((yyvsp[0])->lexeme, integer);
                    (yyval)->type = integer;
                }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 258 "sample.y" /* yacc.c:1646  */
    { PushSymTab(); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 258 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "block");
                                        if((yyvsp[-2])){
                                            (yyval)->firstChild = (yyvsp[-2]);
                                            (yyvsp[-2])->nextSibling = (yyvsp[-1]);
                                        }
                                        else
                                            (yyval)->firstChild = (yyvsp[-1]);
                                        MergeBackpatch(&((yyval)->nextlist), (yyvsp[-2])->nextlist);
                                        MergeBackpatch(&((yyval)->nextlist), (yyvsp[-1])->nextlist);
                                        //PrintSymbols();
                                        PopSymTab();
                                    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 272 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "var_decls");
                                        if((yyvsp[-1])){
                                            (yyval)->firstChild = (yyvsp[-1]);
                                            (yyvsp[-1])->nextSibling = (yyvsp[0]);
                                        }
                                        else
                                            (yyval)->firstChild = (yyvsp[0]);
                                    }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 280 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "");
            }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 284 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "var_decl");
                                    (yyval)->firstChild = (yyvsp[-2]);
                                    (yyvsp[-2])->nextSibling = (yyvsp[-1]);
                                    UpdateType((yyvsp[-1])->typelist, (yyvsp[-2])->sym->type);
                                }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 291 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "var");
                                (yyval)->firstChild = (yyvsp[-1]);
                                (yyvsp[-1])->nextSibling = (yyvsp[0]);
                                MergeBackpatch(&((yyval)->typelist), (yyvsp[-1])->typelist);
                                MergeBackpatch(&((yyval)->typelist), (yyvsp[0])->typelist);
                            }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 297 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "");
            }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 301 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[0]);
                (yyvsp[0])->sym = AddSym((yyvsp[0])->lexeme, invalid);
                InsertTargetSym(&((yyval)->typelist), (yyvsp[0])->sym);
            }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 307 "sample.y" /* yacc.c:1646  */
    {	Init_PD2 (&(yyval), "stmts");
                            if ((yyvsp[-2])) {
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                            }
                            else
                                (yyval)->firstChild = (yyvsp[0]);
                            PrintTree((yyval));
                            Backpatch((yyvsp[-2])->nextlist, (yyvsp[-1])->sym);
                            MergeBackpatch(&((yyval)->nextlist), (yyvsp[0])->nextlist);
                        }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 318 "sample.y" /* yacc.c:1646  */
    {	Init_PD2(&(yyval), "");
                    PrintTree((yyval));
                }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 323 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[0]); }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 324 "sample.y" /* yacc.c:1646  */
    {	Init_PD2 (&(yyval), "eval");
                            (yyval)->firstChild = (yyvsp[-1]);
                            PrintTree((yyval));
                            MergeBackpatch(&((yyval)->nextlist), (yyvsp[-1])->truelist);
                            MergeBackpatch(&((yyval)->nextlist), (yyvsp[-1])->falselist);
                        }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 330 "sample.y" /* yacc.c:1646  */
    {   Init_PD2 (&(yyval), "if");
                                    (yyval)->firstChild = (yyvsp[-3]);
                                    (yyvsp[-3])->nextSibling = (yyvsp[0]);
                                    PrintTree((yyval));
                                    Backpatch((yyvsp[-3])->truelist, (yyvsp[-1])->sym);
                                    MergeBackpatch(&((yyval)->nextlist), (yyvsp[-3])->falselist);
                                    MergeBackpatch(&((yyval)->nextlist), (yyvsp[0])->nextlist);
                                }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 338 "sample.y" /* yacc.c:1646  */
    {   Init_PD2 (&(yyval), "if");
                                    (yyval)->firstChild = (yyvsp[-6]);
                                    (yyvsp[-6])->nextSibling = (yyvsp[-3]);
                                    (yyvsp[-3])->nextSibling = (yyvsp[0]);
                                    PrintTree((yyval));
                                    Backpatch((yyvsp[-6])->truelist, (yyvsp[-4])->sym);
                                    Backpatch((yyvsp[-6])->falselist, (yyvsp[-1])->sym);
                                    MergeBackpatch(&((yyval)->nextlist), (yyvsp[-3])->nextlist);
                                    MergeBackpatch(&((yyval)->nextlist), (yyvsp[0])->nextlist);
                                }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 348 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "for");
                                        (yyval)->firstChild = (yyvsp[-3]);
                                        (yyvsp[-3])->nextSibling = (yyvsp[-1]);
                                        (yyvsp[-1])->nextSibling = (yyvsp[0]);
                                        PrintTree((yyval));
                                    }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 354 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "return");
                            (yyval)->firstChild = (yyvsp[-2]);
                            (yyvsp[-2])->nextSibling = (yyvsp[-1]);
                        }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 358 "sample.y" /* yacc.c:1646  */
    {  (yyval) = (yyvsp[-1]);
                }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 360 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[-1]);
                }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 362 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "method_call");
                        (yyval)->firstChild = (yyvsp[-1]);
    }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 367 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "callout");
                                                    (yyval)->firstChild = (yyvsp[-1]);
                                                    (yyvsp[-1])->nextSibling = (yyvsp[0]);
        }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 373 "sample.y" /* yacc.c:1646  */
    {  (yyval) = (yyvsp[-1]);

                            }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 376 "sample.y" /* yacc.c:1646  */
    {   (yyval) = NULL;  }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 379 "sample.y" /* yacc.c:1646  */
    { Init_PD2(&(yyval), "assign");
                            (yyval)->firstChild = (yyvsp[-2]);
                            (yyvsp[-2])->nextSibling = (yyvsp[0]);
                        }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 385 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[0]);
                        }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 387 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "assign_op");
                            (yyval)->firstChild = (yyvsp[-2]);
                            (yyvsp[-2])->nextSibling = (yyvsp[0]);
                            (yyval)->sym = FindSymbol((yyvsp[-2])->lexeme);
                            GenQuad("=", (yyvsp[0])->sym, NULL, (yyval)->sym);
                        }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 393 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "plus_eq");
                            (yyval)->firstChild = (yyvsp[-2]);
                            (yyvsp[-2])->nextSibling = (yyvsp[0]);
                            (yyval)->sym = FindSymbol((yyvsp[-2])->lexeme);
                            GenQuad("+", (yyval)->sym, (yyvsp[0])->sym, (yyval)->sym);
                            //GenQuad("=", $3->sym, NULL, $$->sym);
                        }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 400 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "minus_eq");
                            (yyval)->firstChild = (yyvsp[-2]);
                            (yyvsp[-2])->nextSibling = (yyvsp[0]);
                            (yyval)->sym = FindSymbol((yyvsp[-2])->lexeme);
                            GenQuad("-", (yyval)->sym, (yyvsp[0])->sym, (yyval)->sym);
                            //GenQuad("=", $3->sym, NULL, $$->sym);
                        }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 407 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "method_call");
                                (yyval)->firstChild = (yyvsp[-3]);
                                (yyvsp[-3])->nextSibling = (yyvsp[-1]);
                            }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 413 "sample.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);
    }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 415 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "array");
                            (yyval)->firstChild = (yyvsp[-3]);
                            (yyvsp[-3])->nextSibling = (yyvsp[-1]);
    }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 421 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "args");
                                        (yyval)->firstChild = (yyvsp[-1]);
                                        (yyvsp[-1])->nextSibling = (yyvsp[0]);
                                    }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 425 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), ""); }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 428 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "args");
                                            (yyval)->firstChild = (yyvsp[-1]);
                                            (yyvsp[-1])->nextSibling = (yyvsp[0]);
    }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 432 "sample.y" /* yacc.c:1646  */
    {   (yyval) = NULL;  }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 435 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[0]);
                        }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 437 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "cond_OR");
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                            }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 443 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[0]);
                        }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 445 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "cond_AND");
                                    (yyval)->firstChild = (yyvsp[-2]);
                                    (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 451 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[0]);
                        }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 453 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "EQUAL");
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                rel_operation("==", (yyval), (yyvsp[-2]), (yyvsp[0]));
                            }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 458 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "NOT_EQUAL");
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                rel_operation("!=", (yyval), (yyvsp[-2]), (yyvsp[0]));
                            }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 465 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[0]);
                    }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 467 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "LESS_THAN");
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                rel_operation("<", (yyval), (yyvsp[-2]), (yyvsp[0]));
                            }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 472 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "GREATER_THAN");
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                rel_operation(">", (yyval), (yyvsp[-2]), (yyvsp[0]));
                            }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 477 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "LESS_EQUAL");
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                rel_operation("<=", (yyval), (yyvsp[-2]), (yyvsp[0]));
                            }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 482 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "GREATER_EQUAL");
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                rel_operation(">=", (yyval), (yyvsp[-2]), (yyvsp[0]));
                            }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 489 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[0]);
                        }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 491 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "plus");
                                        (yyval)->firstChild = (yyvsp[-2]);
                                        (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                        (yyval)->sym = GenSym(integer);
                                        GenQuad("+", (yyvsp[-2])->sym, (yyvsp[0])->sym, (yyval)->sym);
                                    }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 497 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "minus");
                                    (yyval)->firstChild = (yyvsp[-2]);
                                    (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                    (yyval)->sym = GenSym(integer);
                                    GenQuad("-", (yyvsp[-2])->sym, (yyvsp[0])->sym, (yyval)->sym);
                                }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 505 "sample.y" /* yacc.c:1646  */
    {   (yyval) = (yyvsp[0]);
                        }
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 507 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "mul");
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                (yyval)->sym = GenSym(integer);
                                GenQuad("*", (yyvsp[-2])->sym, (yyvsp[0])->sym, (yyval)->sym);
                            }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 513 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "div");
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                (yyval)->sym = GenSym(integer);
                                GenQuad("/", (yyvsp[-2])->sym, (yyvsp[0])->sym, (yyval)->sym);
                            }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 519 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "mod");
                                (yyval)->firstChild = (yyvsp[-2]);
                                (yyvsp[-2])->nextSibling = (yyvsp[0]);
                                (yyval)->sym = GenSym(integer);
                                GenQuad("%", (yyvsp[-2])->sym, (yyvsp[0])->sym, (yyval)->sym);
                            }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 527 "sample.y" /* yacc.c:1646  */
    {	(yyval) = (yyvsp[-1]);
                            }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 529 "sample.y" /* yacc.c:1646  */
    {	Init_PD2 (&(yyval), "cond_NOT");
                                    (yyval)->firstChild = (yyvsp[0]);
                                    (yyval)->sym = GenSym(boolean);
                                    GenQuad("!", (yyvsp[0])->sym,NULL, (yyval)->sym);
                                }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 534 "sample.y" /* yacc.c:1646  */
    {	Init_PD2 (&(yyval), "NEG");
                                        (yyval)->firstChild = (yyvsp[0]);
                                        (yyval)->sym = GenSym(integer);
                                        GenQuad("-", (yyvsp[0])->sym, NULL, (yyval)->sym);
                                    }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 539 "sample.y" /* yacc.c:1646  */
    {	(yyval) = (yyvsp[0]);
                    }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 541 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), "array");
                            (yyval)->firstChild = (yyvsp[-3]);
                            (yyvsp[-3])->nextSibling = (yyvsp[-1]);
                            (yyvsp[-3])->sym = FindSymbol((yyvsp[-3])->lexeme);
                            (yyval)->sym = GenSym((yyvsp[-3])->sym->type);
                            GenQuad("=", (yyvsp[-3])->sym, (yyvsp[-1])->sym, (yyval)->sym);

                        }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 549 "sample.y" /* yacc.c:1646  */
    {	Init_PD2(&(yyval), (yyvsp[0])->PD2_type);
                (yyval)->sym = FindSymbol((yyvsp[0])->lexeme);
                //$$->firstChild = $1;
            }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 555 "sample.y" /* yacc.c:1646  */
    {	Init_PD2(&(yyval), (yyvsp[0])->PD2_type);
                            (yyval)->sym = AddSym((yyvsp[0])->lexeme, integer);
                        }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 558 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), (yyvsp[0])->PD2_type);
                            (yyval)->sym = AddSym((yyvsp[0])->lexeme, string);
                            //$$->firstChild = $1;
                        }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 562 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), (yyvsp[0])->PD2_type);
                            (yyval)->sym = AddSym((yyvsp[0])->lexeme, character);
                            //$$->firstChild = $1;
                        }
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 566 "sample.y" /* yacc.c:1646  */
    {   Init_PD2(&(yyval), (yyvsp[0])->PD2_type);
                            (yyval)->sym = AddSym((yyvsp[0])->lexeme, boolean);
                            //$$->firstChild = $1;
                        }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 572 "sample.y" /* yacc.c:1646  */
    {
            Init_PD2(&(yyval), "");
            (yyval)->sym = InstallLabel();
    }
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2314 "y.tab.c" /* yacc.c:1646  */
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
#line 577 "sample.y" /* yacc.c:1906  */


#include "lex.yy.c"

int DEBUG_MODE = 1;

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

void InsertTargetSym(struct backpatchList** x, struct symbol* s){
    if (*x == NULL){
        *x = (struct backpatchList*) malloc(sizeof(struct backpatchList));
        (*x)->quad = (struct quadtab* ) malloc(sizeof (struct quadtab));
        (*x)->sym = s;
        (*x)->next = NULL;
        //PrintList (*x);
        return;
    }
    else {
        struct backpatchList* z = (struct backpatchList*) malloc(sizeof(struct backpatchList));
        z->sym = s;
        z->next = *x;
        *x = z;
    }
    //PrintList (*x);
}//InsertTarget

void UpdateType(struct backpatchList* x, enum dataType ty){
    if(x == NULL) return;
    struct backpatchList* toPatch = x;
    while(toPatch != NULL){
        struct symbol* s = toPatch->sym;
        printf("%s %d->%d \n", s->name, s->type, ty);
        if(s->type == array){
            if(ty == integer)
                s->type = intArray;
            else
                s->type = boolArray;
        }
        else
            s->type = ty;
        toPatch = toPatch->next;
    }
}

struct symbol* FindSymbol(char* lexeme){
    struct symtab* s = symStack;
    while (s != NULL) {
        struct symbol* sym = s->symbols;
        while (sym != NULL){
            if (strcmp(lexeme, sym->name) == 0)
                return sym;
            sym = sym->next;
        }
        s = s->next;
    }
    printf("undefined variable/function %s\n", lexeme);
    if(!DEBUG_MODE){
        exit(0);
    }
    return NULL;
}

struct symbol* FindSymbolBlock(char* lexeme){
    struct symbol* sym = symStack->symbols;
    while (sym != NULL) {
        if (strcmp(lexeme, sym->name) == 0)
            return sym;
        sym = sym->next;
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
    else if (strcmp(q->opcode, "if") == 0){
        if(q->dst->name)
            printf("L%d: if %s goto %s\n", q->idx, q->src1->name, q->dst->name);
    }
    else if (strcmp(q->opcode, "ifFalse") == 0){
        if(q->dst->name)
            printf("L%d: ifFalse %s goto %s\n", q->idx, q->src1->name, q->dst->name);
    }
    else if (strcmp(q->opcode, "goto") == 0)
        printf("L%d: goto %s\n", q->idx, q->dst->name);

    else if (strcmp(q->opcode, "halt") == 0)
        printf("L%d: halt\n", q->idx);

    else if(strcmp(q->opcode, "function") == 0)
        printf("%s %s starts\n", q->opcode, q->dst->name);

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
    if(name[0] >= '1' && name[0] <= '9'){
        struct symbol* sym = FindSymbol(name);
        if(sym != NULL)
            return sym;

    }
    else if(FindSymbolBlock(name) != NULL) {
        printf("Syntax Error Redeclaration of variable/function %s\n", name);
        if(!DEBUG_MODE)
            exit(0);
    }
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
    if(lexeme[0] < '0' || lexeme[0] > '9')
        printf("%s %d\n", lexeme, ty);
    struct symbol* s = FindSymbol (lexeme);
    if (!s) {
        s = AddSym(lexeme, ty);
        if(lexeme[0] < '0' || lexeme[0] > '9')
            printf("undefined variable/function %s\n", lexeme);
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
            if (sym->type == boolean)
                printf("%s boolean\n", sym->name);
            if (sym->type == intArray)
                printf("%s intArray\n", sym->name);
            if (sym->type == boolArray)
                printf("%s boolArray\n", sym->name);
            if (sym->type == string)
                printf("%s string\n", sym->name);
            if (sym->type == function)
                printf("%s function\n", sym->name);
            if (sym->type == character)
                printf("%s character\n", sym->name);
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

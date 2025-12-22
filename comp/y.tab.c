/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "csua.y"

#include <stdio.h>
#define YYDEBUG 1
#include "csua.h"    

int yyerror(char const *str);
int yylex();

#line 80 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LP = 258,                      /* LP  */
    RP = 259,                      /* RP  */
    LC = 260,                      /* LC  */
    RC = 261,                      /* RC  */
    COMMA = 262,                   /* COMMA  */
    LOGICAL_AND = 263,             /* LOGICAL_AND  */
    LOGICAL_OR = 264,              /* LOGICAL_OR  */
    EQ = 265,                      /* EQ  */
    ASSIGN_T = 266,                /* ASSIGN_T  */
    NE = 267,                      /* NE  */
    GT = 268,                      /* GT  */
    GE = 269,                      /* GE  */
    LE = 270,                      /* LE  */
    LT = 271,                      /* LT  */
    SEMICOLON = 272,               /* SEMICOLON  */
    COLON = 273,                   /* COLON  */
    ADD = 274,                     /* ADD  */
    SUB = 275,                     /* SUB  */
    MUL = 276,                     /* MUL  */
    DIV = 277,                     /* DIV  */
    MOD = 278,                     /* MOD  */
    ADD_ASSIGN_T = 279,            /* ADD_ASSIGN_T  */
    SUB_ASSIGN_T = 280,            /* SUB_ASSIGN_T  */
    MUL_ASSIGN_T = 281,            /* MUL_ASSIGN_T  */
    DIV_ASSIGN_T = 282,            /* DIV_ASSIGN_T  */
    MOD_ASSIGN_T = 283,            /* MOD_ASSIGN_T  */
    INCREMENT = 284,               /* INCREMENT  */
    DECREMENT = 285,               /* DECREMENT  */
    EXCLAMATION = 286,             /* EXCLAMATION  */
    DOT = 287,                     /* DOT  */
    INT_LITERAL = 288,             /* INT_LITERAL  */
    DOUBLE_LITERAL = 289,          /* DOUBLE_LITERAL  */
    IDENTIFIER = 290,              /* IDENTIFIER  */
    IF = 291,                      /* IF  */
    ELSE = 292,                    /* ELSE  */
    ELSIF = 293,                   /* ELSIF  */
    WHILE = 294,                   /* WHILE  */
    FOR = 295,                     /* FOR  */
    RETURN = 296,                  /* RETURN  */
    BREAK = 297,                   /* BREAK  */
    CONTINUE = 298,                /* CONTINUE  */
    TRUE_T = 299,                  /* TRUE_T  */
    FALSE_T = 300,                 /* FALSE_T  */
    BOOLEAN_T = 301,               /* BOOLEAN_T  */
    INT_T = 302,                   /* INT_T  */
    DOUBLE_T = 303,                /* DOUBLE_T  */
    STRING_T = 304,                /* STRING_T  */
    LOWER_THAN_ELSE = 305          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LP 258
#define RP 259
#define LC 260
#define RC 261
#define COMMA 262
#define LOGICAL_AND 263
#define LOGICAL_OR 264
#define EQ 265
#define ASSIGN_T 266
#define NE 267
#define GT 268
#define GE 269
#define LE 270
#define LT 271
#define SEMICOLON 272
#define COLON 273
#define ADD 274
#define SUB 275
#define MUL 276
#define DIV 277
#define MOD 278
#define ADD_ASSIGN_T 279
#define SUB_ASSIGN_T 280
#define MUL_ASSIGN_T 281
#define DIV_ASSIGN_T 282
#define MOD_ASSIGN_T 283
#define INCREMENT 284
#define DECREMENT 285
#define EXCLAMATION 286
#define DOT 287
#define INT_LITERAL 288
#define DOUBLE_LITERAL 289
#define IDENTIFIER 290
#define IF 291
#define ELSE 292
#define ELSIF 293
#define WHILE 294
#define FOR 295
#define RETURN 296
#define BREAK 297
#define CONTINUE 298
#define TRUE_T 299
#define FALSE_T 300
#define BOOLEAN_T 301
#define INT_T 302
#define DOUBLE_T 303
#define STRING_T 304
#define LOWER_THAN_ELSE 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "csua.y"

    int                  iv;
    double               dv;
    char                *name;
    Expression          *expression;
    Statement           *statement;
    FunctionDeclaration *function_declaration;
    AssignmentOperator   assignment_operator;
    CS_BasicType         type_specifier;

#line 244 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LP = 3,                         /* LP  */
  YYSYMBOL_RP = 4,                         /* RP  */
  YYSYMBOL_LC = 5,                         /* LC  */
  YYSYMBOL_RC = 6,                         /* RC  */
  YYSYMBOL_COMMA = 7,                      /* COMMA  */
  YYSYMBOL_LOGICAL_AND = 8,                /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 9,                 /* LOGICAL_OR  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_ASSIGN_T = 11,                  /* ASSIGN_T  */
  YYSYMBOL_NE = 12,                        /* NE  */
  YYSYMBOL_GT = 13,                        /* GT  */
  YYSYMBOL_GE = 14,                        /* GE  */
  YYSYMBOL_LE = 15,                        /* LE  */
  YYSYMBOL_LT = 16,                        /* LT  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 18,                     /* COLON  */
  YYSYMBOL_ADD = 19,                       /* ADD  */
  YYSYMBOL_SUB = 20,                       /* SUB  */
  YYSYMBOL_MUL = 21,                       /* MUL  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_MOD = 23,                       /* MOD  */
  YYSYMBOL_ADD_ASSIGN_T = 24,              /* ADD_ASSIGN_T  */
  YYSYMBOL_SUB_ASSIGN_T = 25,              /* SUB_ASSIGN_T  */
  YYSYMBOL_MUL_ASSIGN_T = 26,              /* MUL_ASSIGN_T  */
  YYSYMBOL_DIV_ASSIGN_T = 27,              /* DIV_ASSIGN_T  */
  YYSYMBOL_MOD_ASSIGN_T = 28,              /* MOD_ASSIGN_T  */
  YYSYMBOL_INCREMENT = 29,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 30,                 /* DECREMENT  */
  YYSYMBOL_EXCLAMATION = 31,               /* EXCLAMATION  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_INT_LITERAL = 33,               /* INT_LITERAL  */
  YYSYMBOL_DOUBLE_LITERAL = 34,            /* DOUBLE_LITERAL  */
  YYSYMBOL_IDENTIFIER = 35,                /* IDENTIFIER  */
  YYSYMBOL_IF = 36,                        /* IF  */
  YYSYMBOL_ELSE = 37,                      /* ELSE  */
  YYSYMBOL_ELSIF = 38,                     /* ELSIF  */
  YYSYMBOL_WHILE = 39,                     /* WHILE  */
  YYSYMBOL_FOR = 40,                       /* FOR  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 43,                  /* CONTINUE  */
  YYSYMBOL_TRUE_T = 44,                    /* TRUE_T  */
  YYSYMBOL_FALSE_T = 45,                   /* FALSE_T  */
  YYSYMBOL_BOOLEAN_T = 46,                 /* BOOLEAN_T  */
  YYSYMBOL_INT_T = 47,                     /* INT_T  */
  YYSYMBOL_DOUBLE_T = 48,                  /* DOUBLE_T  */
  YYSYMBOL_STRING_T = 49,                  /* STRING_T  */
  YYSYMBOL_LOWER_THAN_ELSE = 50,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_translation_unit = 52,          /* translation_unit  */
  YYSYMBOL_definition_or_statement = 53,   /* definition_or_statement  */
  YYSYMBOL_function_definition = 54,       /* function_definition  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_declaration_statement = 56,     /* declaration_statement  */
  YYSYMBOL_block = 57,                     /* block  */
  YYSYMBOL_statement_list = 58,            /* statement_list  */
  YYSYMBOL_if_statement = 59,              /* if_statement  */
  YYSYMBOL_type_specifier = 60,            /* type_specifier  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_assignment_expression = 62,     /* assignment_expression  */
  YYSYMBOL_assignment_operator = 63,       /* assignment_operator  */
  YYSYMBOL_logical_or_expression = 64,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 65,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 66,       /* equality_expression  */
  YYSYMBOL_relational_expression = 67,     /* relational_expression  */
  YYSYMBOL_additive_expression = 68,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 69, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 70,          /* unary_expression  */
  YYSYMBOL_postfix_expression = 71,        /* postfix_expression  */
  YYSYMBOL_primary_expression = 72         /* primary_expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    87,    91,    98,   108,   114,   124,   125,
     126,   130,   134,   141,   145,   152,   156,   163,   167,   174,
     175,   176,   180,   190,   191,   197,   198,   199,   200,   201,
     202,   206,   207,   210,   211,   215,   216,   217,   221,   222,
     223,   224,   225,   229,   230,   231,   235,   236,   237,   238,
     242,   243,   244,   248,   249,   250,   251,   255,   256,   257,
     258,   259,   260
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LP", "RP", "LC", "RC",
  "COMMA", "LOGICAL_AND", "LOGICAL_OR", "EQ", "ASSIGN_T", "NE", "GT", "GE",
  "LE", "LT", "SEMICOLON", "COLON", "ADD", "SUB", "MUL", "DIV", "MOD",
  "ADD_ASSIGN_T", "SUB_ASSIGN_T", "MUL_ASSIGN_T", "DIV_ASSIGN_T",
  "MOD_ASSIGN_T", "INCREMENT", "DECREMENT", "EXCLAMATION", "DOT",
  "INT_LITERAL", "DOUBLE_LITERAL", "IDENTIFIER", "IF", "ELSE", "ELSIF",
  "WHILE", "FOR", "RETURN", "BREAK", "CONTINUE", "TRUE_T", "FALSE_T",
  "BOOLEAN_T", "INT_T", "DOUBLE_T", "STRING_T", "LOWER_THAN_ELSE",
  "$accept", "translation_unit", "definition_or_statement",
  "function_definition", "statement", "declaration_statement", "block",
  "statement_list", "if_statement", "type_specifier", "expression",
  "assignment_expression", "assignment_operator", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "primary_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-19)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     123,    12,    71,    12,    12,   -19,   -19,   -19,     6,   -19,
     -19,   -19,   -19,   -19,    18,   -19,   -19,   -19,   -19,   -19,
     -19,   -18,    22,   -19,    26,    40,    30,    13,    11,   -10,
     -19,   136,   -19,    16,   -19,   -19,    77,    15,   -19,     4,
     -19,    12,   -19,   -19,     5,   -19,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    51,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,    12,   -19,
     -19,   -19,     8,    57,    63,    12,   -19,    40,    30,    13,
      13,    11,    11,    11,    11,   -10,   -10,   -19,   -19,   -19,
     -19,   -19,   123,    56,    62,    44,   -19,   -19,   123,   -19
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    59,    60,    58,     0,    61,
      62,    19,    20,    21,     0,     2,     4,     5,     8,     9,
      10,     0,     0,    22,    23,    31,    33,    35,    38,    43,
      46,    50,    53,     0,    14,    15,     0,     0,    51,    50,
      52,     0,     1,     3,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,    55,    56,     0,    57,
      13,    16,     0,     0,     0,     0,    11,    32,    34,    36,
      37,    39,    40,    42,    41,    44,    45,    47,    48,    49,
      54,    24,     0,     0,     0,    17,     6,    12,     0,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -19,   -19,    74,   -19,     1,   -19,   -19,   -19,   -19,    10,
       3,    21,   -19,   -19,    48,    43,    36,    19,    32,     2,
       0,   -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    14,    15,    16,    17,    18,    19,    36,    20,    37,
      22,    23,    68,    24,    25,    26,    27,    28,    29,    30,
      39,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,    31,    31,    35,    33,    38,    40,    59,    74,    41,
      21,    56,    57,    58,    31,     1,    75,    44,    42,    75,
      69,     1,    76,     2,    21,    76,    50,    51,    52,    53,
      54,    55,     3,    66,    67,    46,    31,    71,     3,    45,
      48,    31,    49,     4,    73,     5,     6,     7,    47,     4,
      72,     5,     6,     7,     8,    90,     9,    10,    87,    88,
      89,    92,     9,    10,    11,    12,    13,    93,    31,    81,
      82,    83,    84,    96,     1,    31,     2,    34,    94,    97,
       1,    98,     2,    70,    79,    80,    85,    86,    43,    91,
      78,     3,    31,    95,    77,     0,     0,     3,    31,    99,
       0,     0,     4,     0,     5,     6,     7,     8,     4,     0,
       5,     6,     7,     8,     0,     9,    10,    11,    12,    13,
       0,     9,    10,    11,    12,    13,     1,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
       0,     0,     0,     3,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     4,     0,     5,     6,     7,     8,
      61,    62,    63,    64,    65,    66,    67,     9,    10,    11,
      12,    13
};

static const yytype_int8 yycheck[] =
{
       0,     1,     2,     2,     1,     3,     4,     3,     3,     3,
       0,    21,    22,    23,    14,     3,    11,    35,     0,    11,
       4,     3,    17,     5,    14,    17,    13,    14,    15,    16,
      19,    20,    20,    29,    30,     9,    36,    36,    20,    17,
      10,    41,    12,    31,    41,    33,    34,    35,     8,    31,
      35,    33,    34,    35,    36,     4,    44,    45,    56,    57,
      58,     4,    44,    45,    46,    47,    48,     4,    68,    50,
      51,    52,    53,    17,     3,    75,     5,     6,    75,    17,
       3,    37,     5,     6,    48,    49,    54,    55,    14,    68,
      47,    20,    92,    92,    46,    -1,    -1,    20,    98,    98,
      -1,    -1,    31,    -1,    33,    34,    35,    36,    31,    -1,
      33,    34,    35,    36,    -1,    44,    45,    46,    47,    48,
      -1,    44,    45,    46,    47,    48,     3,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    34,    35,    36,
      24,    25,    26,    27,    28,    29,    30,    44,    45,    46,
      47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    20,    31,    33,    34,    35,    36,    44,
      45,    46,    47,    48,    52,    53,    54,    55,    56,    57,
      59,    60,    61,    62,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    61,     6,    55,    58,    60,    70,    71,
      70,     3,     0,    53,    35,    17,     9,     8,    10,    12,
      13,    14,    15,    16,    19,    20,    21,    22,    23,     3,
      11,    24,    25,    26,    27,    28,    29,    30,    63,     4,
       6,    55,    35,    61,     3,    11,    17,    65,    66,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    70,
       4,    62,     4,     4,    61,    55,    17,    17,    37,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    55,    55,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      70,    70,    70,    71,    71,    71,    71,    72,    72,    72,
      72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     5,     2,     1,     1,
       1,     3,     5,     3,     2,     1,     2,     5,     7,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     1,     3,     2,     2,     3,     1,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 4: /* definition_or_statement: function_definition  */
#line 92 "csua.y"
        {
           CS_Compiler* compiler = cs_get_current_compiler();
           if (compiler) {
               compiler->func_list = cs_chain_function_declaration_list(compiler->func_list, (yyvsp[0].function_declaration));
           }
        }
#line 1387 "y.tab.c"
    break;

  case 5: /* definition_or_statement: statement  */
#line 99 "csua.y"
        {
           CS_Compiler* compiler = cs_get_current_compiler();
           if (compiler) {
               compiler->stmt_list = cs_chain_statement_list(compiler->stmt_list, (yyvsp[0].statement));
           }
        }
#line 1398 "y.tab.c"
    break;

  case 6: /* function_definition: type_specifier IDENTIFIER LP RP SEMICOLON  */
#line 108 "csua.y"
                                                    { (yyval.function_declaration) = cs_create_function_declaration((yyvsp[-4].type_specifier), (yyvsp[-3].name));}
#line 1404 "y.tab.c"
    break;

  case 7: /* statement: expression SEMICOLON  */
#line 115 "csua.y"
        {
    /*
           CS_Compiler* compiler = cs_get_current_compiler();
           if (compiler) {
               compiler->expr_list = cs_chain_expression_list(compiler->expr_list, $1);
           }
     */
            (yyval.statement) = cs_create_expression_statement((yyvsp[-1].expression));
        }
#line 1418 "y.tab.c"
    break;

  case 8: /* statement: declaration_statement  */
#line 124 "csua.y"
                                { /*printf("declaration_statement\n"); */}
#line 1424 "y.tab.c"
    break;

  case 11: /* declaration_statement: type_specifier IDENTIFIER SEMICOLON  */
#line 131 "csua.y"
        { 
            (yyval.statement) = cs_create_declaration_statement((yyvsp[-2].type_specifier), (yyvsp[-1].name), NULL); 
        }
#line 1432 "y.tab.c"
    break;

  case 12: /* declaration_statement: type_specifier IDENTIFIER ASSIGN_T expression SEMICOLON  */
#line 135 "csua.y"
        {
            (yyval.statement) = cs_create_declaration_statement((yyvsp[-4].type_specifier), (yyvsp[-3].name), (yyvsp[-1].expression)); 
        }
#line 1440 "y.tab.c"
    break;

  case 13: /* block: LC statement_list RC  */
#line 142 "csua.y"
        {
            (yyval.statement) = cs_create_block_statement((yyvsp[-1].statement));
        }
#line 1448 "y.tab.c"
    break;

  case 14: /* block: LC RC  */
#line 146 "csua.y"
        {
            (yyval.statement) = cs_create_block_statement(NULL);
        }
#line 1456 "y.tab.c"
    break;

  case 15: /* statement_list: statement  */
#line 153 "csua.y"
        {
            (yyval.statement) = cs_create_statement_list((yyvsp[0].statement));
        }
#line 1464 "y.tab.c"
    break;

  case 16: /* statement_list: statement_list statement  */
#line 157 "csua.y"
        {
            (yyval.statement) = cs_chain_statement_list((yyvsp[-1].statement), (yyvsp[0].statement));
        }
#line 1472 "y.tab.c"
    break;

  case 17: /* if_statement: IF LP expression RP statement  */
#line 164 "csua.y"
        {
            (yyval.statement) = cs_create_if_statement((yyvsp[-2].expression), (yyvsp[0].statement), NULL);
        }
#line 1480 "y.tab.c"
    break;

  case 18: /* if_statement: IF LP expression RP statement ELSE statement  */
#line 168 "csua.y"
        {
            (yyval.statement) = cs_create_if_statement((yyvsp[-4].expression), (yyvsp[-2].statement), (yyvsp[0].statement));
        }
#line 1488 "y.tab.c"
    break;

  case 19: /* type_specifier: BOOLEAN_T  */
#line 174 "csua.y"
                    { (yyval.type_specifier) = CS_BOOLEAN_TYPE; }
#line 1494 "y.tab.c"
    break;

  case 20: /* type_specifier: INT_T  */
#line 175 "csua.y"
                    { (yyval.type_specifier) = CS_INT_TYPE;     }
#line 1500 "y.tab.c"
    break;

  case 21: /* type_specifier: DOUBLE_T  */
#line 176 "csua.y"
                    { (yyval.type_specifier) = CS_DOUBLE_TYPE;  }
#line 1506 "y.tab.c"
    break;

  case 22: /* expression: assignment_expression  */
#line 181 "csua.y"
         { 
             Expression* expr = (yyvsp[0].expression);
//             printf("type = %d\n", expr->kind);
             (yyval.expression) = (yyvsp[0].expression);
         }
#line 1516 "y.tab.c"
    break;

  case 24: /* assignment_expression: postfix_expression assignment_operator assignment_expression  */
#line 192 "csua.y"
        {
          (yyval.expression) = cs_create_assignment_expression((yyvsp[-2].expression), (yyvsp[-1].assignment_operator), (yyvsp[0].expression));
        }
#line 1524 "y.tab.c"
    break;

  case 25: /* assignment_operator: ASSIGN_T  */
#line 197 "csua.y"
                          { (yyval.assignment_operator) = ASSIGN;     }
#line 1530 "y.tab.c"
    break;

  case 26: /* assignment_operator: ADD_ASSIGN_T  */
#line 198 "csua.y"
                          { (yyval.assignment_operator) = ADD_ASSIGN; }
#line 1536 "y.tab.c"
    break;

  case 27: /* assignment_operator: SUB_ASSIGN_T  */
#line 199 "csua.y"
                          { (yyval.assignment_operator) = SUB_ASSIGN; }
#line 1542 "y.tab.c"
    break;

  case 28: /* assignment_operator: MUL_ASSIGN_T  */
#line 200 "csua.y"
                          { (yyval.assignment_operator) = MUL_ASSIGN; }
#line 1548 "y.tab.c"
    break;

  case 29: /* assignment_operator: DIV_ASSIGN_T  */
#line 201 "csua.y"
                          { (yyval.assignment_operator) = DIV_ASSIGN; }
#line 1554 "y.tab.c"
    break;

  case 30: /* assignment_operator: MOD_ASSIGN_T  */
#line 202 "csua.y"
                          { (yyval.assignment_operator) = MOD_ASSIGN; }
#line 1560 "y.tab.c"
    break;

  case 32: /* logical_or_expression: logical_or_expression LOGICAL_OR logical_and_expression  */
#line 207 "csua.y"
                                                                  { (yyval.expression) = cs_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression));  }
#line 1566 "y.tab.c"
    break;

  case 34: /* logical_and_expression: logical_and_expression LOGICAL_AND equality_expression  */
#line 211 "csua.y"
                                                                  { (yyval.expression) = cs_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression));  }
#line 1572 "y.tab.c"
    break;

  case 36: /* equality_expression: equality_expression EQ relational_expression  */
#line 216 "csua.y"
                                                       { (yyval.expression) = cs_create_binary_expression(EQ_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression));  }
#line 1578 "y.tab.c"
    break;

  case 37: /* equality_expression: equality_expression NE relational_expression  */
#line 217 "csua.y"
                                                       { (yyval.expression) = cs_create_binary_expression(NE_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression));  }
#line 1584 "y.tab.c"
    break;

  case 39: /* relational_expression: relational_expression GT additive_expression  */
#line 222 "csua.y"
                                                       { (yyval.expression) = cs_create_binary_expression(GT_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1590 "y.tab.c"
    break;

  case 40: /* relational_expression: relational_expression GE additive_expression  */
#line 223 "csua.y"
                                                       { (yyval.expression) = cs_create_binary_expression(GE_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1596 "y.tab.c"
    break;

  case 41: /* relational_expression: relational_expression LT additive_expression  */
#line 224 "csua.y"
                                                       { (yyval.expression) = cs_create_binary_expression(LT_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1602 "y.tab.c"
    break;

  case 42: /* relational_expression: relational_expression LE additive_expression  */
#line 225 "csua.y"
                                                       { (yyval.expression) = cs_create_binary_expression(LE_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1608 "y.tab.c"
    break;

  case 44: /* additive_expression: additive_expression ADD multiplicative_expression  */
#line 230 "csua.y"
                                                             { (yyval.expression) = cs_create_binary_expression(ADD_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1614 "y.tab.c"
    break;

  case 45: /* additive_expression: additive_expression SUB multiplicative_expression  */
#line 231 "csua.y"
                                                             { (yyval.expression) = cs_create_binary_expression(SUB_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1620 "y.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression MUL unary_expression  */
#line 236 "csua.y"
                                                         { (yyval.expression) = cs_create_binary_expression(MUL_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1626 "y.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression DIV unary_expression  */
#line 237 "csua.y"
                                                         { (yyval.expression) = cs_create_binary_expression(DIV_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1632 "y.tab.c"
    break;

  case 49: /* multiplicative_expression: multiplicative_expression MOD unary_expression  */
#line 238 "csua.y"
                                                         { (yyval.expression) = cs_create_binary_expression(MOD_EXPRESSION, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1638 "y.tab.c"
    break;

  case 51: /* unary_expression: SUB unary_expression  */
#line 243 "csua.y"
                                        { (yyval.expression) = cs_create_minus_expression((yyvsp[0].expression)); }
#line 1644 "y.tab.c"
    break;

  case 52: /* unary_expression: EXCLAMATION unary_expression  */
#line 244 "csua.y"
                                        { (yyval.expression) = cs_create_logical_not_expression((yyvsp[0].expression)); }
#line 1650 "y.tab.c"
    break;

  case 54: /* postfix_expression: postfix_expression LP RP  */
#line 249 "csua.y"
                                       { (yyval.expression) = cs_create_function_call_expression((yyvsp[-2].expression), NULL); }
#line 1656 "y.tab.c"
    break;

  case 55: /* postfix_expression: postfix_expression INCREMENT  */
#line 250 "csua.y"
                                       { (yyval.expression) = cs_create_inc_dec_expression((yyvsp[-1].expression), INCREMENT_EXPRESSION);}
#line 1662 "y.tab.c"
    break;

  case 56: /* postfix_expression: postfix_expression DECREMENT  */
#line 251 "csua.y"
                                       { (yyval.expression) = cs_create_inc_dec_expression((yyvsp[-1].expression), DECREMENT_EXPRESSION);}
#line 1668 "y.tab.c"
    break;

  case 57: /* primary_expression: LP expression RP  */
#line 255 "csua.y"
                           { (yyval.expression) = (yyvsp[-1].expression);}
#line 1674 "y.tab.c"
    break;

  case 58: /* primary_expression: IDENTIFIER  */
#line 256 "csua.y"
                           { (yyval.expression) = cs_create_identifier_expression((yyvsp[0].name)); }
#line 1680 "y.tab.c"
    break;

  case 59: /* primary_expression: INT_LITERAL  */
#line 257 "csua.y"
                           { (yyval.expression) = cs_create_int_expression((yyvsp[0].iv)); }
#line 1686 "y.tab.c"
    break;

  case 60: /* primary_expression: DOUBLE_LITERAL  */
#line 258 "csua.y"
                           { (yyval.expression) = cs_create_double_expression((yyvsp[0].dv)); }
#line 1692 "y.tab.c"
    break;

  case 61: /* primary_expression: TRUE_T  */
#line 259 "csua.y"
                           { (yyval.expression) = cs_create_boolean_expression(CS_TRUE); }
#line 1698 "y.tab.c"
    break;

  case 62: /* primary_expression: FALSE_T  */
#line 260 "csua.y"
                           { (yyval.expression) = cs_create_boolean_expression(CS_FALSE); }
#line 1704 "y.tab.c"
    break;


#line 1708 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 262 "csua.y"

int
yyerror(char const *str)
{
    extern char *yytext;
    CS_Compiler* compiler = cs_get_current_compiler();
    if (compiler) {
        fprintf(stderr, "line %d :", compiler->current_line);
    }
    
    fprintf(stderr, "parser error near %s\n", yytext);
    return 0;
}

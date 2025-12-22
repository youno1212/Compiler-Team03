/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 178 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

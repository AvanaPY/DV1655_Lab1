/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    INTEGER_LITERAL = 258,
    IDENTIFIER = 259,
    END = 260,
    CLASS = 261,
    PUBLIC = 262,
    STATIC = 263,
    VOID = 264,
    MAIN = 265,
    EXTENDS = 266,
    STRING = 267,
    RETURN = 268,
    LENGTH = 269,
    IF = 270,
    ELSE = 271,
    WHILE = 272,
    SYS_PRINTLN = 273,
    T_Int = 274,
    T_Bool = 275,
    T_True = 276,
    T_False = 277,
    PLUSOP = 278,
    MINOP = 279,
    MULOP = 280,
    DIVOP = 281,
    AND = 282,
    OR = 283,
    EQ = 284,
    LT = 285,
    GT = 286,
    THIS = 287,
    NEW = 288
  };
#endif
/* Tokens.  */
#define INTEGER_LITERAL 258
#define IDENTIFIER 259
#define END 260
#define CLASS 261
#define PUBLIC 262
#define STATIC 263
#define VOID 264
#define MAIN 265
#define EXTENDS 266
#define STRING 267
#define RETURN 268
#define LENGTH 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define SYS_PRINTLN 273
#define T_Int 274
#define T_Bool 275
#define T_True 276
#define T_False 277
#define PLUSOP 278
#define MINOP 279
#define MULOP 280
#define DIVOP 281
#define AND 282
#define OR 283
#define EQ 284
#define LT 285
#define GT 286
#define THIS 287
#define NEW 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

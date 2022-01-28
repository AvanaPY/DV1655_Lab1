%top{
    #include "parser.tab.hh"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "Node.h"
    extern int lineno;
}

%option noyywrap nounput batch noinput
%%


"class"             { return yy::parser::make_CLASS(); }
"public"            { return yy::parser::make_PUBLIC(); }
"static"            { return yy::parser::make_STATIC(); }
"void"              { return yy::parser::make_VOID(); }
"main"              { return yy::parser::make_MAIN(); }
"String"            { return yy::parser::make_STRING(); }
"return"            { return yy::parser::make_RETURN(); }
"length"            { return yy::parser::make_LENGTH(); }
"extends"           { return yy::parser::make_EXTENDS(); }

"int"               { return yy::parser::make_T_Int(yytext); }
"boolean"           { return yy::parser::make_T_Bool(yytext); }
"true"              { return yy::parser::make_T_True(yytext); }
"false"             { return yy::parser::make_T_False(yytext); }

"if"                { return yy::parser::make_IF(); }
"else"              { return yy::parser::make_ELSE(); }
"while"             { return yy::parser::make_WHILE(); }

"this"              { return yy::parser::make_THIS(); }
"new"               { return yy::parser::make_NEW(); }

"System.out.println" { return yy::parser::make_SYS_PRINTLN(); }

"+"                 { return yy::parser::make_PLUSOP(); }
"-"                 { return yy::parser::make_MINOP(); }
"*"                 { return yy::parser::make_MULOP(); }
"/"                 { return yy::parser::make_DIVOP(); }
"="                 { return yytext[0]; }

"."                 { return yy::parser::make_DOT(); }

"&&"                { return yy::parser::make_AND(); }
"||"                { return yy::parser::make_OR(); }
"=="                { return yy::parser::make_EQ(); }
"<"                 { return yy::parser::make_LT(); }
">"                 { return yy::parser::make_GT(); }
"!"                 { return yy::parser::make_NOT(); }

"("                 { return yy::parser::make_LP(); }
")"                 { return yy::parser::make_RP(); }
"["                 { return yy::parser::make_LHKP(); }
"]"                 { return yy::parser::make_RHKP(); }

[\{\}\(\)\[\]\,\.\;] { return yytext[0]; }
[ \t]+               {}
\/\/.+               { }
"\n"                 { lineno++;}
[a-zA-Z_]+[0-9]*     { return yy::parser::make_IDENTIFIER(yytext); }
0|[1-9][0-9]*        { return yy::parser::make_INTEGER_LITERAL(yytext); }

.                   { return yytext[0]; }
%%
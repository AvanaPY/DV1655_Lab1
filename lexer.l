%top{
    #include "y.tab.h"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "Node.h"
}
%option noyywrap nounput batch noinput stack
%%

0|[1-9][0-9]*    { return INTEGER_LITERAL; }
[{}()[,.;]]      { return yytext[0]; }
\/\/.+\n         {}
[ \t]+           {}

"class"             { return CLASS; }
"public"            { return PUBLIC; }
"static"            { return STATIC; }
"void"              { return VOID; }
"main"              { return MAIN; }
"string"            { return STRING; }
"return"            { return RETURN; }
"length"            { return LENGTH; }

"int"               { return T_Int; }
"boolean"           { return T_Bool; }
"true"              { return T_True; }
"false"             { return T_False; }

"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }

"this"              { return THIS; }
"new"               { return NEW; }

"System.out.println" { return SYS_PRINTLN; }

"+"                 { return PLUSOP; }
"-"                 { return MINOP; }
"*"                 { return MULOP; }
"/"                 { return DIVOP; }

"&&"                { return AND; }
"||"                { return OR; }
"=="                { return EQ; }
"<"                 { return LT; }
">"                 { return GT; }

[a-zA-Z\-]+               { return IDENTIFIER; }
"\n"             {}
<<EOF>>          return EOF;
%%
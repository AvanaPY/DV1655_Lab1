%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
}
%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  
}
// definition of set of tokens. All tokens are of type string
%token INTEGER_LITERAL IDENTIFIER END

%token CLASS  
%token PUBLIC  
%token STATIC  
%token VOID    
%token MAIN    
%token EXTENDS
%token STRING
%token RETURN
%token LENGTH

%token IF ELSE WHILE
%token SYS_PRINTLN

%token T_Int T_Bool T_True T_False

%token PLUSOP MINOP MULOP DIVOP 
%token AND OR EQ LT GT 

%token THIS NEW
// definition of the production rules. All production rules are of type Node
// %type <Node *> expression  addExpression multExpression factor

%%
Goal                : MainClass ClassDeclaration END
                    ;

MainClass           : CLASS Identifier '{' PUBLIC STATIC VOID MAIN '(' STRING '[' ']' Identifier ')' '{' Statement '}' '}'
                    ;

ClassDeclaration    : CLASS Identifier '{' VarDeclaration MethodDeclaration  '}'
                    | CLASS Identifier EXTENDS Identifier '{' VarDeclaration MethodDeclaration '}'
                    ;

VarDeclaration      : VarDeclaration Type Identifier ';'
                    | Type Identifier ';'
                    ;

MethodDeclaration   : MethodDeclaration PUBLIC Type Identifier '(' MethodArgumentDeclaration ')' '{' MethodVarDeclaration MethodStatementDeclaration RETURN Expression ';' '}'
                    | 
                    ;

MethodArgumentDeclaration   : Type Identifier
                            | MethodArgumentDeclaration ',' Type Identifier
                            |
                            ;

MethodVarDeclaration        : MethodVarDeclaration VarDeclaration
                            | VarDeclaration
                            |
                            ;

MethodStatementDeclaration  : MethodStatementDeclaration Statement
                            | Statement
                            |
                            ;

Type                : T_Int '[' ']'
                    | T_Bool
                    | T_Int
                    | Identifier
                    ;
                    
Statement           : '{' Statement Statement '}'
                    | '{' Statement '}'
                    | IF '(' Expression ')' Statement ELSE Statement
                    | WHILE '(' Expression ')' Statement
                    | SYS_PRINTLN '(' Expression ')' ';'
                    | Identifier '=' Expression ';'
                    | Identifier '[' Expression ']' '=' Expression ';'
                    ;

Expression          : Expression AND Expression
                    | Expression OR Expression
                    | Expression LT Expression
                    | Expression GT Expression
                    | Expression EQ Expression
                    | Expression PLUSOP Expression
                    | Expression MINOP Expression
                    | Expression MULOP Expression
                    | Expression DIVOP Expression
                    | Expression '[' Expression ']'
                    | Expression '.' LENGTH
                    | Expression '.' Identifier '(' ')'
                    | INTEGER_LITERAL
                    | T_True
                    | T_False
                    | Identifier
                    | THIS
                    | NEW T_Int '[' Expression ']'
                    | NEW Identifier '(' FunctionCallDeclaration ')'
                    | '!' Expression 
                    | '(' Expression ')'
                    ;

FunctionCallDeclaration : FunctionCallDeclaration ',' Expression
                        | Expression
                        |
                        ;
                        
Identifier          : IDENTIFIER
                    ;
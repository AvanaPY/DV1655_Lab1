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
%token <std::string> INTEGER_LITERAL 
%token <std::string> IDENTIFIER 

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
%token <std::string> T_Int T_Bool T_True T_False
%token PLUSOP MINOP MULOP DIVOP 
%token THIS NEW
%token AND OR EQ LT GT 

%left PLUSOP 
%left MINOP
%left MULOP 
%left DIVOP


%type <Node *> Goal MainClass ClassDeclaration VarDeclaration MethodDeclaration MethodBodyDeclaration MethodArgumentDeclaration MethodVarDeclaration MethodStatementDeclaration Type Statement Expression FunctionCallDeclaration Identifier
// definition of the production rules. All production rules are of type Node

%%
Goal                : MainClass ClassDeclaration {
                                        $$ = new Node("Program", "");
                                        $$->children.push_back($1);
                                        $$->children.push_back($2);
                                        root = $$;
                                        printf("r1 ");
                                    }
                    ;

MainClass           : CLASS Identifier '{' PUBLIC STATIC VOID MAIN '(' STRING '[' ']' Identifier ')' '{' Statement '}' '}' {
                                                                    $$ = new Node("MainClass", $2->type);
                                                                    Node* n = new Node("Method", "Main");
                                                                    n->children.push_back($15);
                                                                    $$->children.push_back(n);
                                                                    printf("r2 ");
                                                                }
                    ;

ClassDeclaration    : CLASS Identifier '{' VarDeclaration MethodDeclaration '}' {
                                            $$ = new Node("Class", $2->type);
                                            $$->children.push_back($4);
                                            $$->children.push_back($5);
                                            printf("r5 ");
                                        }
                    | CLASS Identifier EXTENDS Identifier '{' VarDeclaration MethodDeclaration '}'{
                                            $$ = new Node("Class", $2->type);

                                            $$->children.push_back(new Node("Class Extends", $4->type));
                                            $$->children.push_back($6);
                                            $$->children.push_back($7);
                                            printf("r6 ");
                                        }
                    ;

VarDeclaration      : VarDeclaration Type Identifier ';' {
                                            $$ = new Node("Variable", "");
                                            $$->children.push_back($2);
                                            $$->children.push_back($3);
                                            $$->children.push_back($1);
                                            printf("r7 ");
                                        }
                    | Type Identifier ';' {
                                            $$ = new Node("Variable", "");
                                            $$->children.push_back($2);
                                            $$->children.push_back($1);
                                            printf("r8 ");
                                        }
                    |
                    ;

MethodDeclaration   : MethodDeclaration PUBLIC Type Identifier '(' MethodArgumentDeclaration ')' '{' MethodBodyDeclaration '}' {
                                $$ = new Node("Method", $4->type);
                                $$->children.push_back($6);
                                $$->children.push_back($9);
                                printf("r9 ");
                            }
                    | PUBLIC Type Identifier '(' MethodArgumentDeclaration ')' '{' MethodBodyDeclaration '}' {
                                $$ = new Node("Method", "");
                                $$->children.push_back($3);
                                $$->children.push_back($5);
                                $$->children.push_back($8);
                                printf("r9.2 ");
                            }
                    |
                    ;

MethodBodyDeclaration       : MethodBodyDeclaration MethodVarDeclaration {
                                $$ = new Node("Variable", "");
                                $$->children.push_back($1);
                                $$->children.push_back($2);
                                printf("r10 ");
                            }
                            | MethodBodyDeclaration MethodStatementDeclaration   {
                                $$ = new Node("Statement", "");
                                $$->children.push_back($1);
                                $$->children.push_back($2);
                                printf("r11 ");
                            }
                            | MethodVarDeclaration{
                                $$ = new Node("Variable", "");
                                $$->children.push_back($1);
                                printf("r12 ");
                            }
                            | MethodStatementDeclaration {
                                $$ = new Node("Statement", "");
                                $$->children.push_back($1);
                                printf("r14 ");
                            }
                            ;

MethodArgumentDeclaration   : MethodArgumentDeclaration ',' Type Identifier
                            | Type Identifier{
                                            $$ = new Node("Argument", "");
                                            $$->children.push_back($1);
                                            $$->children.push_back($2);
                                            printf("r16 ");
                                        }
                            ;

MethodVarDeclaration        : MethodVarDeclaration VarDeclaration
                            | VarDeclaration {
                                            $$ = new Node("Variable", "");
                                            $$->children.push_back($1);
                                            printf("r19 ");
                                        }
                            ;

MethodStatementDeclaration  : MethodStatementDeclaration Statement
                            | Statement {
                                            $$ = new Node("Method Statement Declaration", "");
                                            $$->children.push_back($1);
                                            printf("r21 ");
                                        }
                            ;

Type                : T_Int {
                                $$ = new Node("Int", "");
                                printf("r22 ");
                            }
                    | T_Int '[' ']' {
                                $$ = new Node("Int[]", "");
                                printf("r23 ");
                            }
                    | T_Bool {
                                $$ = new Node("Bool", "");
                                printf("r24 ");
                            }
                    | VOID {
                                $$ = new Node("VOID", "");
                                printf("r25 ");
                            }
                    | Identifier {
                                $$ = new Node("IDENTIFIER", "");
                                $$->children.push_back($1);
                                printf("r26 ");
                            }
                    ;
                    
Statement           : Statement Statement ';' {
                                    $$ = new Node("Statement", "");
                                    $$->children.push_back($1);
                                    $$->children.push_back($2);
                                    printf("r27 ");
                                    }
                    | Statement ';' {
                                $$ = new Node("Statement", "");
                                $$->children.push_back($1);
                                printf("r28 ");
                            }
                    | IF '(' Expression ')' '{' Statement '}' ELSE '{' Statement '}' {
                                $$ = new Node("IF", "");
                                $$->children.push_back($3);
                                $$->children.push_back($6);
                                $$->children.push_back($10);
                                printf("r29 ");
                            }
                    | WHILE '(' Expression ')'  '{' Statement '}' {
                                $$ = new Node("While", "");
                                $$->children.push_back($3);
                                $$->children.push_back($6);
                                printf("r30 ");
                            }
                    | SYS_PRINTLN '(' Expression ')' {
                                $$ = new Node("SYS_PRINTLN", $3->value);
                                printf("r31 ");
                            }
                    | Identifier '=' Expression {
                                $$ = new Node("Assign", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r32 ");
                            }
                    | Identifier '[' Expression ']' '=' Expression{
                                $$ = new Node("Assign[]", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                $$->children.push_back($6);
                                printf("r33 ");
                            }
                    ;

Expression          : Expression AND Expression {
                                $$ = new Node("AND", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r34 ");
                            }
                    | Expression OR Expression {
                                $$ = new Node("OR", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r35 ");
                            }
                    | Expression LT Expression {
                                $$ = new Node("LESS THAN", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r36 ");
                            }
                    | Expression GT Expression {
                                $$ = new Node("GREATER THAN", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r37 ");
                            }
                    | Expression EQ Expression {
                                $$ = new Node("EQUALS", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r38 ");
                            }
                    | Expression PLUSOP Expression {
                                $$ = new Node("PLUS", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r39 ");
                            }
                    | Expression MINOP Expression {
                                $$ = new Node("MINUS", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r40 ");
                            }
                    | Expression MULOP Expression {
                                $$ = new Node("MULT", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r41 ");
                            }
                    | Expression DIVOP Expression {
                                $$ = new Node("DIV", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r42 ");
                            }
                    | Expression '[' Expression ']' {
                                $$ = new Node("Indexing", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r42 ");
                            }
                    | Expression '.' LENGTH{
                                $$ = new Node("LENGTH", "");
                                $$->children.push_back($1);
                                printf("r43 ");
                            }
                    | Expression '.' Identifier '(' FunctionCallDeclaration ')'{
                                $$ = new Node("Function Call", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                $$->children.push_back($5);
                                printf("r44 ");
                            }
                    | INTEGER_LITERAL{
                                $$ = new Node("Integer", $1);
                                printf("r45 ");
                            }
                    | T_True{
                                $$ = new Node("True", $1);
                                printf("r46 ");
                            }
                    | T_False {
                                $$ = new Node("False", $1);
                                printf("r47 ");
                            }
                    | Identifier {
                                $$ = new Node("Identifier", $1->type);
                                printf("r48 ");
                            }
                    | THIS {
                                $$ = new Node("THIS", "");
                                printf("r49 ");
                            }
                    | NEW T_Int '[' Expression ']'{
                                $$ = new Node("new[]", $2);
                                $$->children.push_back($4);
                                printf("r50 ");
                            }
                    | NEW Identifier '(' ')'{
                                $$ = new Node("new()", "");
                                $$->children.push_back($2);
                                printf("r51 ");
                            }
                    | '!' Expression {
                                $$ = new Node("Negate", "");
                                $$->children.push_back($2);
                                printf("r52 ");
                            }
                    | '(' Expression ')'{
                                $$ = new Node("Statement", "");
                                $$->children.push_back($2);
                                printf("r53 ");
                            }
                    ;

FunctionCallDeclaration : FunctionCallDeclaration ',' Expression
                        | Expression{
                                $$ = new Node("Function Call Expression", "");
                                $$->children.push_back($1);
                                printf("r54 ");
                            }
                        ;
                        
Identifier          : IDENTIFIER{
                                $$ = new Node($1, "");
                                printf("r55 ");
                            }
                    | MAIN {
                                $$ = new Node("MAIN", "");
                                printf("r56 ");
                            }
                    ;
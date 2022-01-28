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
    Node* classes;
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
%token DOT

%left PLUSOP 
%left MINOP
%left MULOP 
%left DIVOP


%type <Node *> Goal MainClass 
OptionalClassList ClassDeclaration 
VarList VarDeclaration 
MethodList MethodDeclaration MethodBodyDeclaration 
MethodParameterList MethodParameterDecl
Type Statement Expression 
FunctionArgumentList Identifier
// definition of the production rules. All production rules are of type Node

%%
Goal                : MainClass OptionalClassList {
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

OptionalClassList   : OptionalClassList ClassDeclaration {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            $1->children.push_back($2);
                            $$ = $1;
                            
                        }
                    | ClassDeclaration {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            classes->children.push_back($1);
                            $$ = classes;
                        }
                    ;

ClassDeclaration    : CLASS Identifier '{' VarList MethodList '}' {
                                            $$ = new Node("Class", $2->type);
                                            $$->children.push_back($4);
                                            $$->children.push_back($5);
                                            printf("r5 ");
                                        }
                    | CLASS Identifier EXTENDS Identifier '{' VarList MethodList '}'{
                                            $$ = new Node("Class", $2->type);

                                            $$->children.push_back(new Node("Class Extends", $4->type));
                                            $$->children.push_back($6);
                                            $$->children.push_back($7);
                                            printf("r6 ");
                                        }
                    ;

VarList             :   VarList VarDeclaration {
                            $1->children.push_back($2);
                            $$=$1;
                            printf("r7.2 ");
                        }
                    |   VarDeclaration {
                            $$ = new Node("Variable List", "");
                            $$->children.push_back($1);
                            printf("r7.1 ");
                        }
                    ;

VarDeclaration      : Type Identifier ';' {
                            $$ = new Node("Variable", "");
                            $$->children.push_back($2);
                            $$->children.push_back($1);
                            printf("r8 ");
                        }
                    ;

MethodList          :   MethodList MethodDeclaration {
                            $1->children.push_back($2);
                            $$=$1;
                            printf("r8.1 ");
                        }
                    |   MethodDeclaration{
                            $$ = new Node("Method List", "");
                            $$->children.push_back($1);
                            printf("r8.2 ");
                        }
                    ;

MethodDeclaration   :   PUBLIC Type Identifier '(' MethodParameterList ')' '{' MethodBodyDeclaration '}' {
                            $$ = new Node("Method", $3->type);
                            $$->children.push_back($5);
                            $$->children.push_back($8);
                            printf("r9.2 ");
                        }
                    ;

MethodBodyDeclaration       : MethodBodyDeclaration Statement {
                                $$ = new Node("Variable", "");
                                $$->children.push_back($1);
                                $$->children.push_back($2);
                                printf("r10 ");
                            }
                            | VarList {
                                printf("r12 ");
                                $$ = $1;
                            }
                            | Statement {
                                $$ = new Node("Statement List", "");
                                $$->children.push_back($1);
                                printf("r14 ");
                            }
                            ;

MethodParameterList :  MethodParameterList ',' MethodParameterDecl{
                            $1->children.push_back($3);
                            $$=$1;
                            printf("r16 ");
                        }
                    | MethodParameterDecl {
                            $$ = new Node("Parameter List", "");
                            $$->children.push_back($1);
                            printf("r16.1 ");
                        }
                    |  %empty {
                            $$ = new Node("Arguments", "None");
                            printf("r16.2 ");
                        }
                    ;

MethodParameterDecl :   Type Identifier{
                            $$ = new Node("Parameter", "");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            printf("r16 ");
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
                    ;
                    
Statement           : Statement Statement {
                                    $$ = new Node("Statement", "");
                                    $$->children.push_back($1);
                                    $$->children.push_back($2);
                                    printf("r27 ");
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
                    | SYS_PRINTLN '(' Expression ')' ';' {
                                $$ = new Node("SYS_PRINTLN", $3->value);
                                printf("r31 ");
                            }
                    | Identifier '=' Expression ';' { 
                                $$ = new Node("Assign", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r32 ");
                            }
                    | Identifier '[' Expression ']' '=' Expression ';' {
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
                    | Expression DOT LENGTH {
                                $$ = new Node("LENGTH", "");
                                $$->children.push_back($1);
                                printf("r43 ");
                            }
                    | Expression DOT Identifier '(' FunctionArgumentList ')'{
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

FunctionArgumentList : FunctionArgumentList ',' Expression {
                                $$ = new Node("Function Call Expression", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                printf("r54 ");
                            }
                        | Expression{
                                $$ = new Node("Function Call Expression", "");
                                $$->children.push_back($1);
                                printf("r55 ");
                            }
                        ;
                        
Identifier          : IDENTIFIER {
                                $$ = new Node($1, "");
                                printf("r56 ");
                            }
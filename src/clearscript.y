%{
#include <string.h>
#include <cstdio>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include "include/AssignNode.h"
#include "include/AstNode.h"
#include "include/BinaryOpNode.h"
#include "include/BuiltinFunCallNode.h"
#include "include/ClassAttrNode.h"
#include "include/ClassMethodNode.h"
#include "include/ClassNode.h"
#include "include/ConcatOpNode.h"
#include "include/CondNode.h"
#include "include/DivNode.h"
#include "include/FunCallNode.h"
#include "include/FuncArgNode.h"
#include "include/FuncNode.h"
#include "include/IdentifierNode.h"
#include "include/IfNode.h"
#include "include/LogAndOpNode.h"
#include "include/LogNotOpNode.h"
#include "include/LogOrOpNode.h"
#include "include/ModNode.h"
#include "include/MulNode.h"
#include "include/SubNode.h"
#include "include/SumNode.h"
#include "include/VarDeclNode.h"
#include "include/WhileNode.h"

extern int yylineno;

void yyerror(char* s, ...)
{
	va_list ap;
	va_start(ap, s);
	
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

extern "C"
{
	int yyparse(void);
	int yylex(void);
}

%}


%union {
	long i;
	double f;
	char s[4096];
	ConditionType cmp;
	BuiltinFunction fun;
	AstNode* a;
}

%token <f> FLOAT_CONST
%token <i> INTEGER_CONST
%token <fun> BUILTIN_FUN
%token <s> STRING_CONST IDENTIFIER T_INTEGER T_LONG T_FLOAT T_DOUBLE T_BOOLEAN T_STRING T_VOID
%token IF DO ELSE WHILE
%token AND OR
%token MAIN PUBLIC PROTECTED CLASS METHOD FUNCTION CONSTRUCTOR DOES

%nonassoc <cmp> CMP
%right '='
%left '+' '-'
%left '*' '/'
%nonassoc '!'

%type <s> builtin_type
%type <a> value expr simple_declaration assign if while func_call func_declaration

/* @TODO Adicionar tipo de cada nó */
%start calclist

%%

builtin_type:
  T_VOID
| T_INTEGER
| T_LONG
| T_FLOAT
| T_DOUBLE
| T_BOOLEAN
| T_STRING {
	strcpy($$, $1);
}
;


value:
  IDENTIFIER
| FLOAT_CONST
| INTEGER_CONST
| STRING_CONST
;


expr:
  value
| expr '+' expr
| expr '-' expr
| expr '/' expr
| expr '%' expr
| expr OR expr
| expr AND expr
| expr CMP expr
| '!' expr
| '(' expr ')'
| func_call
;

simple_declaration:
 builtin_type IDENTIFIER {
	printf("Declaração tipo predefinido: %s %s\n", $1, $2);
}
| IDENTIFIER IDENTIFIER {
	printf("Declaração: %s %s\n", $1, $2);
}
;

assign_declaration:
  simple_declaration '=' expr {
 	printf("Atribuição com valor");
}
;

assign:
	IDENTIFIER '=' expr { printf("Atribuição"); }
;

declaration:
| assign_declaration
| simple_declaration
;

stmt:
  declaration ';'
| assign ';'
| '{' op_stmt '}'
| if
| while
| func_call ';'
;

arg_list:
| expr
| expr ',' arg_list
;

func_call:
  BUILTIN_FUN '(' arg_list ')' { printf("Chamada de função predefinida"); }
| IDENTIFIER '(' arg_list ')' { printf("Chamada de função"); }
;

op_stmt:
| stmt
;

if:
  IF '(' expr ')' DO stmt
| IF '(' expr ')' DO stmt ELSE stmt
;

while:
  WHILE '(' expr ')' DO stmt
;

arg_def_list:
| simple_declaration
| simple_declaration ',' arg_def_list
;

func_declaration:
  simple_declaration '(' arg_def_list ')' DOES '{' func_body '}' {
	printf("Declaração de função");
}
;

func_body:
| stmt func_body
;

calclist:
| func_declaration calclist
| MAIN DOES '{' func_body '}' { /* TODO Chamar eval no func_body*/exit(0); }
;
%%

main(int argc, char **argv)
{
    yyparse();
}

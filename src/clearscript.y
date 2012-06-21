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
#include "include/LongConstNode.h"
#include "include/DoubleConstNode.h"
#include "include/StringConstNode.h"
#include "include/StmtListNode.h"
#include "include/ArgList.h"

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
	int cmp;
	BuiltinFunction fun;
	AstNode* a;
	ArgList* al;
}

%token <f> FLOAT_CONST
%token <i> INTEGER_CONST
%token <fun> BUILTIN_FUN
%token <s> STRING_CONST IDENTIFIER T_INTEGER T_LONG T_FLOAT T_DOUBLE T_BOOLEAN T_STRING T_VOID
%token IF DO ELSE WHILE
%token AND OR
%token MAIN PUBLIC PROTECTED CLASS METHOD FUNCTION CONSTRUCTOR DOES CONCAT_OP

%nonassoc <cmp> CMP
%right '='
%left '+' '-'
%left '*' '/'
%nonassoc '!'

%type <s> builtin_type
%type <a> value expr simple_declaration declaration assign if while func_call func_declaration stmt stmt_list
%type <al> arg_list

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
  IDENTIFIER { $$ = new IdentifierNode(yylval.s); }
| FLOAT_CONST { $$ = new DoubleConstNode(yylval.f); }
| INTEGER_CONST { $$ = new LongConstNode(yylval.i); }
| STRING_CONST { $$ = new StringConstNode(yylval.s); }
;


expr:
  value { $$ = $1; }
| expr '+' expr { $$ = new SumNode($1, $3); }
| expr '-' expr { $$ = new SubNode($1, $3); }
| expr '/' expr { $$ = new DivNode($1, $3); }
| expr '%' expr { $$ = new ModNode($1, $3); }
| expr OR expr { $$ = new LogOrOpNode($1, $3); }
| expr AND expr { $$ = new LogAndOpNode($1, $3); }
| expr CMP expr { $$ = new CondNode($1, $3, (ConditionType)$2); }
| expr CONCAT_OP expr { $$ = new ConcatOpNode($1, $3); }
| '!' expr { $$ = new LogNotOpNode($2); }
| '(' expr ')' { $$ = $2; }
| func_call { $$ = $1; }
;

simple_declaration:
 builtin_type IDENTIFIER {
	$$ = new VarDeclNode($1, $2);
}
| IDENTIFIER IDENTIFIER {
	$$ = new VarDeclNode($1, $2);
}
;

assign:
  IDENTIFIER '=' expr {
	$$ = new AssignNode(new IdentifierNode($1), $3);
}
;

declaration:
{ $$ = NULL; }
| simple_declaration { $$ = $1; }
;

stmt:
  declaration ';' { $$ = $1; }
| assign ';' { $$ = $1; }
| if { $$ = $1; }
| while { $$ = $1; }
| func_call ';' { $$ = $1; }
;

stmt_list:
{ $$ = NULL; }
|  stmt stmt_list { $$ = new StmtListNode($1, $2); }
;

arg_list:
{ $$ = NULL; }
| expr { $$ = new ArgList($1, NULL); }
| expr ',' arg_list { $$ = new ArgList($1, $3); }
;

func_call:
  BUILTIN_FUN '(' arg_list ')' { /* @TODO Verificar porque valor de fun está incorreto */ $$ = new BuiltinFunCallNode(BF_PRINT, $3->get()); }
| IDENTIFIER '(' arg_list ')' { $$ = new FunCallNode($1, $3->get()); }
;

if:
  IF '(' expr ')' DO '{' stmt_list '}' { $$ = new IfNode($3, $7, NULL); }
| IF '(' expr ')' DO '{' stmt_list '}' ELSE '{' stmt_list '}' { $$ = new IfNode($3, $7, $11); }
;

while:
  WHILE '(' expr ')' DO '{' stmt_list '}' { $$ = new WhileNode($3, $7); }
;

arg_def_list:
| simple_declaration
| simple_declaration ',' arg_def_list
;

func_declaration:
  simple_declaration '(' arg_def_list ')' DOES '{' stmt_list '}' {
	printf("Declaração de função");
}
;

calclist:
| func_declaration calclist
| MAIN DOES '{' stmt_list '}' { if ($4 != NULL) { $4->eval(); } exit(0); }
;
%%

main(int argc, char **argv)
{
    yyparse();
}

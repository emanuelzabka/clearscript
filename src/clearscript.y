%{
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
%}

%union {
	AstNode* node;
	long i;
	double f;
	std::string s;
	ConditionType cmp;
}

%token <i> INTEGER_CONST
%token <f> FLOAT_CONST;
%token <s> STRING;

%token IF THEN ELSE WHILE
%token AND OR
%token PUBLIC
%token PROTECTED
%token CLASS
%token METHOD
%token FUNCTION
%token CONSTRUCTOR
%token DOES
%token T_INTEGER
%token T_LONG
%token T_FLOAT
%token T_DOUBLE
%token T_BOOLEAN
%token T_STRING

%nonassoc <cmp> CMP
%right '='
%left '+' '-'
%left '*' '/'
%nonassoc '!'

/* @TODO Adicionar tipo de cada nó */
%start calclist

%%


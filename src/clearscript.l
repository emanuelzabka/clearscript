/* Linguagem ClearScript */

%option nodefault noyywrap yylineno
%x COMMENT
%x STRING

%{
	#include <string>
	#include "include/CondNode.h"
	// Declarações
	// Escape de string
	bool escape = false;

%}

EXP ([Ee][-+]?[0-9]+)

%%
 /* Comentários. Criados com estados para não haver problemas com buffer de
 entrada*/
"/*" {BEGIN(COMMENT);}
<COMMENT>"*/" {BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|.
<COMMENT><<EOF>> {printf("Comentário não terminado. Linha: %d.\n", yylineno); return 0;}
"//".*\n
 /* Modificadores */
"public" {return PUBLIC;}
"protected" {return PROTECTED;}
"class" {return CLASS;}
"method" {return METHOD;}
"function" {return FUNCTION;}
"constructor" {return CONSTRUCTOR;}
"does" {return DOES;}
 /* Estruturas de controle e laço */
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"do" {return DO;}
 /* Tipos primitivos */
"int" {return T_INTEGER;}
"long" {return T_LONG;}
"float" {return T_FLOAT;}
"double" {return T_DOUBLE;}
"bool" {return T_BOOLEAN;}
"string" { return T_STRING; }
 /* Delimitadores de início e fim */
";" |
"," |
":" |
"{" |
"}" |
"(" |
")" |
"[" |
"]" |
"!" |
"%" |
"+" |
"-" |
"/" |
"*" |
// Operador de atribuiçao
"=" {return yytext[0];}
"||" {return OR;}
"&&" {return AND;}
"<" {  yylval.cmp = CT_LT;  return CMP;}
">" { yylval.cmp = CT_GT; return CMP;}
"<=" { yylval.cmp = CT_LTE; return CMP;}
">=" { yylval.cmp = CT_GTE; return CMP;}
"==" { yylval.cmp = CT_EQUAL return CMP;}
"!=" { yylval.cmp = CT_NEQUAL; return CMP; }
 /* Identificadores */
[_a-zA-Z][_a-zA-Z0-9]* { yylval.s = yyval; }
 /* Strings */
"\"" {BEGIN(STRING); yylval.s = ""; }
<STRING>"\\" {
	if (escape) {
		yylval.s += yytext[0];
	}
	escape = !escape;
}
<STRING>"n" {
	if (escape) {
		yylval.s += "\n";
	}
}
<STRING>"\"" {
	if (escape) {
		yylval.s += yytext[0];
		escape = false;
	} else {
		/* @TODO Fim da string */
		BEGIN(INITIAL);
		return STRING;
	}
}
<STRING>. { yylval.s += yytext[0]; }
 /* Constantes numéricas */
[0-9]+ { yylval.i = std::atoi(yytext); return INTEGER_CONST;}
[0-9]+"."[0-9]*{EXP}? 
"."?[0-9]+{EXP}? {yylval.f = std::atof(yytext); return FLOAT_CONST; }
 /* Ignora restante */
.|\n {}

%%


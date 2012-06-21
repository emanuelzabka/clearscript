/* Linguagem ClearScript */

%option nodefault noyywrap yylineno
%x COMMENT
%x STRING

%{
	extern "C"
	{
		int yylex(void);
	}
	#include <string.h>
	#include "include/ArgList.h"
	#include "include/CondNode.h"
	#include "include/BuiltinFunCallNode.h"
	#include "clearscript.tab.h"

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
"main" {return MAIN; }
"print" { yylval.fun = BF_PRINT; return BUILTIN_FUN; }
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
"void" { strcpy(yylval.s, yytext); return T_VOID; }
"int" { strcpy(yylval.s, yytext); return T_INTEGER; }
"long" { strcpy(yylval.s, yytext); return T_LONG; }
"float" { strcpy(yylval.s, yytext); return T_FLOAT; }
"double" { strcpy(yylval.s, yytext); return T_DOUBLE; }
"bool" { strcpy(yylval.s, yytext); return T_BOOLEAN; }
"string" { strcpy(yylval.s, yytext); return T_STRING; }
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
 /* Operador de atribuiçao */
"=" {return yytext[0];}
"++" { return CONCAT_OP; }
"||" {return OR;}
"&&" {return AND;}
"<" {  yylval.cmp = (int)CT_LT;  return CMP;}
">" { yylval.cmp = (int)CT_GT; return CMP;}
"<=" { yylval.cmp = (int)CT_LTE; return CMP;}
">=" { yylval.cmp = (int)CT_GTE; return CMP;}
"==" { yylval.cmp = (int)CT_EQUAL; return CMP;}
"!=" { yylval.cmp = (int)CT_NEQUAL; return CMP; }
 /* Identificadores */
[_a-zA-Z][_a-zA-Z0-9]* { strcpy(yylval.s, yytext); return IDENTIFIER; }
 /* Strings */
"\"" {BEGIN(STRING); yylval.s[0] = '\0'; }
<STRING>"\\" {
	if (escape) {
		strcat(yylval.s, "\\");
	}
	escape = !escape;
}
<STRING>"n" {
	if (escape) {
		strcat(yylval.s, "\n");
		escape = false;
	}
	else
	{
		strcat(yylval.s, yytext);
	}
}
<STRING>"\"" {
	if (escape) {
		strcat(yylval.s, yytext);
		escape = false;
	} else {
		BEGIN(INITIAL);
		return STRING_CONST;
	}
}
<STRING>. { strcat(yylval.s, yytext); }
 /* Constantes numéricas */
-?[0-9]+ { yylval.i = atoi(yytext); return INTEGER_CONST;}
-?[0-9]+"."[0-9]*{EXP}? |
-?"."?[0-9]+{EXP}? {yylval.f = atof(yytext); return FLOAT_CONST; }
 /* Ignora restante */
.|\n {}

%%


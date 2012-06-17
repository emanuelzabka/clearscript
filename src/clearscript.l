/* Linguagem ClearScript */

%option nodefault noyywrap yylineno
%x COMMENT
%x STRING

%{
	// Declarações
	bool escape = false;
%}

%%
 /* Comentários. Criados com estados para não haver problemas com buffer de
 entrada*/
"/*" {BEGIN(COMMENT);}
<COMMENT>"*/" {BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|.
<COMMENT><<EOF>> {printf("Comentário não terminado. Linha: %d.\n", yylineno); return 0;}
"//".*\n
 /* Modificadores */
"public" {return MOD_PUBLIC;}
"protected" {return MOD_PROTECTED;}
"class" {return CLASS;}
"method" {return METHOD;}
"constructor" {return CONSTRUCTOR;}
"does" {return DOES;}
 /* Número sem sinal */
"unsigned" {return UNSIGNED;}
 /* Estruturas de controle e laço */
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"do" {return DO;}
 /* Tipos primitivos */
"char" {return T_CHAR;}
"byte" {return T_BYTE;}
"int" {return T_INTEGER;}
"short" {return T_SHORT;}
"long" {return T_LONG;}
"float" {return T_FLOAT;}
"double" {return T_DOUBLE;}
"bool" {return T_BOOLEAN;}
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
"*" {return yytext[0];}
"||" {return OR;}
"&&" {return AND;}
"<" {return LT;}
">" {return GT;}
"<=" {return LT_OR_EQ;}
">=" {return GT_OR_EQ;}
"==" {return EQUALS;}
"=" {return ATTRIBUTION;}
 /* Identificadores */
 /* @TODO Character Name, página 58 */
[_a-zA-Z][_a-zA-Z0-9]* {/* @TODO Identificador */}
 /* Strings */
"\"" {BEGIN(STRING); /* @TODO Início string */}
<STRING>"\\" {
	if (escape) {
		/* @TODO Adiciona / ao resultado */
	}
	escape = !escape;
}
<STRING>"\"" {
	if (escape) {
		/* @TODO Adiciona " ao resultado */
		escape = false;
	} else {
		/* @TODO Fim da string */
		BEGIN(INITIAL);
	}
}
<STRING>. {/* @TODO adiciona à string */}
 /* Constantes numéricas */
[0-9]+ { /* @TODO armazenar número */ return INTEGER_CONST;}
 /* @TODO Integer Length, página 58 */
[0-9]*\.[0-9]+ { /* @TODO armazenar número */ return FLOAT_CONST; }
 /* @TODO Float Exponent, página 58 */
 /* @TODO Hex float, página 61 */
 /* Ignora restante */
.|\n {}

%%


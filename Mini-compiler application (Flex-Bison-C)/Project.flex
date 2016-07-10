%{
#include<stdlib.h>
#include "Project.tab.h"
extern YYSTYPE yylval;
%}
lettre [a-zA-Z]
chiffre [0-9]
id {lettre}({lettre}|{chiffre})*
nb {chiffre}+
blancs   [ \n\t]+
com "(*"[^"(*"]*"*)"
pf "."
%%
{blancs}|{com} {}
"program" return (PROGRAM);
"var" return(VAR);
"Int" return (INT);
"LongInt" return (LONGINT);
"func" return (FUNC);
"proc" return (PROC);
"if" return (IF);
"then" return (THEN);
"repeat" return (REPEAT);
"until" return (UNTIL);
"not" return (NOT);
"(" return (PO);
")" return (PF);
"{" return (AO);
"}" return (AF);
";" return (PV);
"," return (VIRGULE);
":" return (DP);
":=" return (OPAFFECT);
"**" return (PUISSANCE);
"="|"<="|">="|"<"|">"|"<>" return (OPREL);
"div"|"mod"|"and"|"*"|"/" return (OPMUL);
"or"|"+"|"-" return (OPADD);
{nb} {yylval = atoi(yytext);return (NB);}
{id} return (ID);
{pf} return(FIN);
%%

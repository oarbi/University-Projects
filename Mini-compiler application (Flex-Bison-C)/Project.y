
%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
%}
%token NB
%token PROGRAM ID VAR FUNC PROC 
%token INT LONGINT
%token IF THEN REPEAT UNTIL
%token NOT OPAFFECT OPREL OPMUL OPADD PUISSANCE 
%token PO PF AO AF
%token PV VIRGULE DP 
%token FIN

%left OPAFFECT
%left OPREL
%left OPADD
%left OPMUL
%left PUISSANCE
%left NOT

%start programme
%%

programme : PROGRAM ID PV declarations declaration_sous_programmes instruction_compose FIN
;

liste_identificateurs : ID 
                      | liste_identificateurs VIRGULE ID 
;
declarations : VAR declaration 
             | /*vide*/
;
declaration : liste_identificateurs DP type PV declaration 
            | liste_identificateurs DP type PV 
;
type : INT 
     | LONGINT 
;
declaration_sous_programmes :declaration_sous_programmes declaration_sous_programme PV 
                            | /*vide*/
; 
declaration_sous_programme : entete_sous_programmes declarations instruction_compose
;
entete_sous_programmes : FUNC ID arguments DP type PV 
                       | PROC ID arguments PV 
;
arguments : PO liste_parametres PF 
          | /*vide*/
;
liste_parametres : liste_identificateurs DP type 
                 | liste_parametres PV liste_identificateurs DP type 
;
instruction_compose : AO  instruction_optionnelles  AF 
;
instruction_optionnelles : liste_instructions 
                         | /*vide*/ 
;
liste_instructions : instruction 
                   | liste_instructions PV  instruction 
;                  
instruction : variable OPAFFECT expression 
            | instruction_proc 
            | instruction_compose 
            | IF expression THEN AO instruction AF
            | IF expression THEN AO instruction AF AO instruction AF 
            | REPEAT instruction UNTIL expression 
;
variable : ID 
;
instruction_proc : ID 
                 | ID PO liste_expressions PF 
;
liste_expressions : expression
                  | liste_expressions VIRGULE expression 
;
expression : expression_simple 
           | expression_simple OPREL expression_simple 
;
expression_simple : terme 
                  | signe terme 
                  | expression_simple OPADD terme 
;
terme : facteur 
      | terme OPMUL facteur
      | facteur PUISSANCE terme 
;
facteur : ID 
        | ID PO liste_expressions PF 
        | NB 
	| PO expression PF 
	| NOT facteur 
;
signe : '+' 
      | '-' 
;	
%%
int yyerror(char *s) {printf("\n%s\n" ,s);}
int yywrap() {return 1;}
int main()
{
yyin =fopen("Source.txt", "r");
if (yyparse()==0) 
    printf("\nLe programme est just !!\n");
else printf("\nLe programme est faux !!\n");
return 0;
}
 

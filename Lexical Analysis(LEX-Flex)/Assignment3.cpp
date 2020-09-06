[11:38 PM, 9/3/2020] Ambrish Iit: %{
	//for Q2 of exercise
	#include <stdio.h>
	#define error -1
	#define id 1
	#define relop 2
	#define number 3
	#define If 4
	#define Else 5
	#define Then 6
	int line_number=1;
%}
letter [A-Za-z]
letters {letter}+
digit [0-9]
digits {digit}+
number {digits}(\.{digits})?(E[+-]?{digits})?
If if
Else else
Then then
identifier {letters}({digit}|{letter})*
delim [ \t]
ws {delim}+
relationalop "<="|">="|"<"|">"|"="|"<>"
%%
{ws} {}
{If} { return If;}
{Else} { return Else;}
{Then} { return Then;}
{identifier} { return id;}
{relationalop} {  return relop;}
{number} {  return number;}
\n {line_number++;}
. {return error;}

%%
int yywrap(){
	return 1;
}
int main(){

	int token;
	yyin=fopen("myfile2.txt" , "r");

	while((token=yylex())!=0){
		printf("%d     %s \n", token, yytext);
	}
	printf("lines %d\n", line_number);
	return 0;
}
[11:39 PM, 9/3/2020] Ambrish Iit: %{
	//for Q3 of exercise
	#include <stdio.h>
	#define error -1
	#define id 1
	#define uop 2
	#define bop 3
	#define relop 4
	#define number 5
	#define assgnop 6
	#define openbrack 7
	#define closebrack 8
	#define If 9
	#define Else 10
	#define Elseif 11
	#define For 12
	#define While 13
	#define Int 14
	#define Float 15
	#define sep 16
	#define REad 17
	#define PRint 18
	#define Return 19
	#define comma 20
	#define pmopen 21
	#define pmclose 22
	int line_number=1;
%}
letter [A-Za-z]
letters {letter}+
digit [0-9]
digits {digit}+
number {digits}(\.{digits})?(E[+-]?{digits})?
If if
Else else
ElseIf elseif
For for
While while 
Int int
Float float
Return return
comma ,
print print
read read
identifier {letters}({digit}|{letter})*
delim [ \t]
ws {delim}+
unaryop "++"|"--"
binaryarithmatic "+"|"-"|"*"|"/"
relationalop "<="|">="|"<"|">"|"||"|"=="|"!="
seperator ";"
assignmentop "="
openbracket "{"
closebracket "}"
openpm "("
closepm ")"
%%
{ws} {}
{If} { return If;}
{Else} { return Else;}
{ElseIf} {return Elseif;}
{For} { return For;}
{While} {return While;}
{Float} {return Float;}
{comma} {return comma;}
{Return} {return Return;}
{print} {return PRint;}
{read} { return REad;}
{Int} { return Int;}
{identifier} { return id;}
{unaryop} { return uop;}
{binaryarithmatic} { return bop;}
{relationalop} {  return relop;}
{number} {  return number;}
{assignmentop} {  return assgnop; }
{seperator} { return sep;}
{openbracket} { return openbrack;}
{closebracket} { return closebrack;}
{openpm} { return pmopen;}
{closepm} { return pmclose;}
\n {line_number++;}
. {return error;}

%%
int yywrap(){
	return 1;
}
int main(){

	int token;
	yyin=fopen("myfile.txt" , "r");

	while((token=yylex())!=0){
		printf("%d     %s \n", token, yytext);
	}
	printf("lines %d\n", line_number);
	return 0;
}

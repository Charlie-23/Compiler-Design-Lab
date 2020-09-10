%{
    #include<stdio.h>
	#include<string.h>
	void find(char *str);
%}
delim [ \t\n]
whitespace {delim}+
digit [0-9]
number ({digit}+)
l_or_d ({letter}|{digit}|[_])
letter [a-zA-Z]
word ({letter}{l_or_d}*)
%%
{whitespace} {}
{word} {find(yytext);}
{number} {printf("%s NUMBER \n",yytext);}
"==" {printf("%s RELOP \n",yytext);}
"<=" {printf("%s RELOP \n",yytext);}
">=" {printf("%s RELOP \n",yytext);}
"<>" {printf("%s RELOP \n",yytext);}
"<" {printf("%s RELOP \n",yytext);}
"=" {printf("%s RELOP \n",yytext);}
">" {printf("%s RELOP \n",yytext);}
. {printf("%s UNIDENTIFIED\n",yytext);}
%%
int yywrap(void){
}
int main() {
yylex();
return 0;
}

void find(char*string){
	if (strcmp(string,"if")==0)
		printf ("if IF \n");
	else if (strcmp(string,"else")==0)
		printf ("else ELSE \n");
	else if (strcmp(string,"then")==0)
		printf ("then THEN \n");
	else
		printf("%s ID \n",string);	
}
%{
	#include<stdio.h>
	#include<string.h>
	void find(char *str);
	int line=1;
%}
%%

[0-9]+([.][0-9]+)?([E][+-]?[0-9]+)? {printf("%s NUMBER\n",yytext);}
[a-zA-z]([a-zA-z]|[0-9][_])* 		{find(yytext);}
[=]									{printf("%s ASSIGNMENT\n",yytext);}
[;]									{printf("%s SEPARATOR\n",yytext);}
([+][=]|[+][+]|[-][=]|[*][=])		{printf("%s COMPOUND ASSIGNMENT\n",yytext);}
([+]|[-]|[*]|[/])					{printf("%s OPERATOR\n",yytext);}
([<]|[>]|[<][=]|[=][=]|[>][=])      {printf("%s RELOP\n",yytext);}
["("")""()""{}"]					{printf("%s %s\n",yytext,yytext);}
[" ""\t"] 							{}
["\n"] 								{line++;}
.									{printf("UNIDENTIFIED\n");}
%%


int yywrap(void) 
{
	return 1;
}

int main(){
	extern FILE *yyin; 
	yyin = fopen("my_code.txt", "r");
	printf("***Output***\n");
	yylex();
	printf("Number of Lines: %d\n",line);	
	return 0;
}
void find(char *str)
{
	if(strcasecmp(str,"if")==0)
	{
		printf("%s IF\n",yytext);
	}
	else if(strcasecmp(str,"main")==0)
	{
		printf("%s MAIN\n",yytext);
	}
	else if(strcasecmp(str,"else")==0)
	{
		printf("%s ELSE\n",yytext);
	}
	else if(strcasecmp(str,"then")==0)
	{
		printf("%s THEN\n",yytext);
	}
	else if(strcasecmp(str,"for")==0)
	{
		printf("%s FOR\n",yytext);
	}
	else if(strcasecmp(str,"while")==0)
	{
		printf("%s WHILE\n",yytext);
	}
	else if(strcasecmp(str,"print")==0)
	{
		printf("%s PRINT\n",yytext);
	}
	else if(strcasecmp(str,"INT")==0 || strcasecmp(str,"int")==0)
	{
		printf("%s INT\n",yytext);
	}
	else if(strcasecmp(str,"FLOAT")==0 || strcasecmp(str,"float")==0)
	{
		printf("%s FLOAT\n",yytext);
	}
	else if(strcasecmp(str,"read")==0)
	{
		printf("%s READ\n",yytext);
	}
	else
	{
		printf("%s ID\n",yytext);
	}
}
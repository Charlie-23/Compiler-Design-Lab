%{

%}

%%
(00|11|(01|10)(00|11)*(10|01))* {printf("Even 1's and Even 0's");}
.* {printf("doesn't have even 0's and even 1's");}
%%
int yywrap(void) {return 1;}
int main() {
yylex();
return 0;
}
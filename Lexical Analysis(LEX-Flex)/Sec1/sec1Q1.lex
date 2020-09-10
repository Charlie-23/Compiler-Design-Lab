%{

%}

%%
(1|(01*0))* {printf("Even 0's");}
.* {printf("Odd 0's");}
%%
int yywrap(void) {return 1;}
int main() {
yylex();
return 0;
}
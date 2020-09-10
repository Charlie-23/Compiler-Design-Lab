%{

%}

%%
(0|1(01*0)*1)* {printf("Divisible by 3");}
.* {printf("not divisible by 3");}
%%
int yywrap(void) {return 1;}
int main() {
yylex();
return 0;
}
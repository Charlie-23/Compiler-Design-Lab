##SEC3: Lexical analyser for a simple c program with given constraints

##commands for linux
-- flex sec3.lex
-- gcc lex.yy.c
-- ./a.out

##'my_code.txt' contains the program to be passed to the lexical analyser

Considerations:
1. keywords: [if,else,then,main,for,while,print,read,int,float]
	a. For all the keywords(small and capital) value returned is the same in the capitalised format
2. identifier: any word that starts with a letter and contains digits|letters|'_'
	a. 'ID' is the returned value
3. 'ASSIGNMENT' for '='
4. 'SEPARATOR' for ';'
5. 'NUMBER' is returned for all numbers	
6. 'OPERATOR' for [+,-,/,*]
7. 'RELOP' for [==,<=,>=,<,>,<>]
8. 'COMPOUND ASSIGNMENT' for ['++','+=','-=','*=']
9. For Paranthesis and braces the same is returned so that the parser may check for the syntax
10. AT the end the number of lines in the code is also printed

##OUTPUT for given code:
main MAIN
( (
) )
{ {
INT INT
i ID
= ASSIGNMENT
0 NUMBER
; SEPARATOR
INT INT
sum ID
= ASSIGNMENT
0 NUMBER
; SEPARATOR
INT INT
count ID
; SEPARATOR
read READ
( (
count ID
) )
; SEPARATOR
for FOR
( (
i ID
= ASSIGNMENT
0 NUMBER
; SEPARATOR
i ID
< RELOP
10 NUMBER
; SEPARATOR
i ID
++ COMPOUND ASSIGNMENT
) )
{ {
read READ
( (
x ID
) )
; SEPARATOR
sum ID
+= COMPOUND ASSIGNMENT
x ID
; SEPARATOR
} }
print PRINT
( (
sum ID
) )
; SEPARATOR
} }
Number of Lines: 16
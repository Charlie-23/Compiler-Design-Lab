##SEC2: Lexical Analyser for given grammar


##commands in ubuntu
-- flex sec2.lex
-- gcc lex.yy.c
-- ./a.out

//For all keywords the same is returned in capitals
//'NUMBER' is returned for all numbers
//'ID' for all identifiers
//'RELOP' for [<,>,=,==,<=,>=,<>]
Examples:

INPUT:
if else xyz > 10 yz <= 99

OUTPUT:
if IF
else ELSE
xyz ID
> RELOP
10 NUMBER
yz ID
<= RELOP
99 NUMBER

INPUT:
if 1x8 x_y x1_00u x_**

OUTPUT:
if IF
1 NUMBER
x8 ID
x_y ID
x1_00u ID
x_ ID
* UNIDENTIFIED
* UNIDENTIFIED
# Expression.cpp
COMP 376: Advanced UNIX Programming
C++ Programming Assignment 4
Fall 2020

Due:  Thursday, December 10, 2020  (Electronically submitted by 10:00 PM)
Use the C++ Standard Template Library’s stack class to write a program for processing a file of postfix expressions. 

Recall that in a postfix expression, a binary operator comes after its two operands.  Thus the infix expression (w + x) * (y – z) becomes w x + y z – * in postfix.  

A postfix expression can be efficiently evaluated using a stack as follows.
1.	Read the expression from the left to the right.
2.	When an operand is encountered, push it on the stack.
3.	When an operator is encountered, pop the top two elements from the stack, perform the operation, and then push the result.
4.	There should be exactly one element on the stack at the end and this element is the value of the expression.
For example, if the expression 20 5 – 3 * is entered, the evaluation should proceed as follows.
 

Symbol read
20
5
–
3
*
 

Actions taken
Push 20
Push 5
Pop 5, Pop 20, Push 20 – 5
Push 3
Pop 3, Pop 15, Push 15 * 3
 
The result of 45 should then be output.

Your program should ask the user for the name of an input file.  The input file will contain postfix expressions one per line.  The program should open the file and evaluate the postfix expressions in the file.  Your program should give the user the option of writing the results to an output file or to the screen.

Your program should also check the entered postfix expression for validity.  A postfix expression is invalid if there is more than one element on the stack at the end of the evaluation or if ever there are not enough operands on the stack when an operation is performed.

 
E.g.  If the input file contained:

20  5  –  3  * 
100  50  60  +  + 
3  4  5  + 
3  4  +  + 
3  4  ? 
 
The output would be:

45
210
Too few operators.
Too many operators.
Illegal operation
 

Limit your postfix expression to the arithmetic operations of +, –, *, and / on integer values.

Be sure to keep a back-up copy of all files you submit for this class!!

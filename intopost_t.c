/*
Design, Develop and Implement a Program in C for converting an Infix Expression to Postfix
Expression. Program should support for both parenthesized and free parenthesized
expressions with the operators: +, -, *, /, %(Remainder), ^(Power) and alphanumeric operands.
*/

#include<stdio.h>
#include<ctype.h>


void convert();
int prior(char);

char exp[25];
char stack[25];
int top=-1;

void push(char ele)
{	stack[++top]=ele;}

char pop()
{	return(stack[top--]);}





void convert(char exp[])
{
	int i=0;
	while(exp[i]!='\0')
	{
		if(isalnum(exp[i]))
		{
			printf("%c",exp[i]);
		}		
	
		else if(exp[i]==')')
			{	while(stack[top]!='(')
					printf("%c",pop());

				pop();
			}		
		else
		{
			if(prior(exp[i])>prior(stack[top]))
				push(exp[i]);
			
			


			else
			{
				while(prior(exp[i])<prior(stack[top]))
					printf("%c",pop());
				push(exp[i]);
			}


	
		}


		i++;
	}

	while(stack[top]!='#')
		printf("%c",pop());

}


int prior(char x)
{
	switch(x)
	{
		case '#': return(-1);break;
	
		case '(':return(0);break;
				
		case '+':
		case '-':return(1);break;

		case '%':
		case '*':
		case '/':return(2);break;

		case '^':return(3);break;



	}


}


void main()
{

	printf("Enter the expression:");

	scanf ("%s",exp);
	
	push('#');

	convert(exp);
	
	//printf("%s",exp);



}

/*
Design, Develop and Implement a Program in C for the following Stack Applications
a. Evaluation of Suffix exprression with single digit operands and operators: +, -, *, /, %,
^
Ex-
I/P => AB+
o/P => A+B

*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>

char expr[25];
char stack[25];
int top=-1;
int res=0;

int eval(int ,char, int);

void push(char ele)
{	stack[++top]=ele;}

char pop()
{	return(stack[top--]);}

void convert(char expr[])
{
	int i=0;int op1,op2;char opr;
	while(expr[i]!='\0')
	{
		if(isalnum(expr[i]))
		{
			push(expr[i]-'0');
		}

		else
		{	
			op1=pop();
			op2=pop();
			opr=expr[i];
			res=eval(op1,opr,op2);
			push(res);		
		}	

	i++;
	}


}

int eval(int a, char s,int b)
{
	switch(s)
	{
		case '+':return(a+b);
		case '-':return(a-b);
		case '*':return(a*b);
		case '/':return(a/b);
		case '%':return(fmod(a,b));
		case '^':return(pow(a,b));
	}

}

void main()
{

	printf("Enter the exprression:");

	scanf ("%s",expr);
	convert(expr);
	printf("\n\n%d\n",pop());
	//printf("%s",expr);



}


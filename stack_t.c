/*
Design, Develop and Implement a menu driven Program in C for the following operations on
STACK of Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element on the Stack
b. Pop an Element from the Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 3

int stack[MAX],top=-1;

//Prototypes
void push(int);
int pop();
int is_pali();
void display();



void main()
{	int opt,ele;
	while(1)
		{
		printf("\n\t\tMENU\n");
		printf("\t1.Push\n\t2.Pop\n\t3.Palinodrome\n\t4.Display\n\t5.EXIT\n");

		printf("Enter Option number : ");
		scanf("%d",&opt);

		switch(opt)
		{
			case 1: printf("Enter ele: ");
				scanf("%d",&ele);
				push(ele);
				break;

			case 2: ele=pop();
				printf("Poped element is %d \n",ele);
				break;

			case 3:if(is_pali()) printf("Is PALINDROME\n"); else printf("NOT PALINDROME\n"); break;
	
			case 4: display();break;

			case 5: exit(0);

			default: printf("Invalid Option Re-enter option number.");
		}
	
		}
}



void push(int ele)
{
	if(top==MAX-1)
	{	printf("Stack is FULL.");return;}
	if(top>=MAX)
	{	printf("Overflows\n");return;}
	else
	{
		stack[++top]=ele;
	}
	
}

int pop()
{
	if(top==0)
	{	printf("Stack is now EMPTY\n");
		return(stack[top--]);
	}
	
	if(top==-1)
	{	printf("Underflow!\n");return(0);}
	else
	{
		return(stack[top--]);
	}

}

int is_pali()
{
	int flag=0;int *temp;
	temp=stack;
	for(int i=0;i<MAX;i++)
	{
		if(*temp == pop())
			flag=1;
		temp+=1;
	}

	return(flag);

}

void display()
{
	printf("Contents of the stack are :\n");
	for(int i=0;i<MAX;i++)
		printf("%d \n",stack[i]);
}



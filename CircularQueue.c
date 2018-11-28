/*Circular Queue */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 5


/*Function Prototypes*/
int insert(char ele);
char delete();
void display();

/*Global Variables*/
char Q[MAX];
int front=-1,rear=-1;


int insert(char ele)
{
	

	if( (front==0 && rear==MAX-1)||(front==(rear+1)) )
	{
		/*OVERFLOW*/
		printf("Queue is full!! Can not insert \n");
		return(0);
	}	
	
	if(front==-1 && rear==-1)
	{	/*Initial condition*/
		front=0;
	}
	rear=(rear+1)%MAX;
	Q[rear]=ele;


	


}



char delete()
{
	char ele;
	//Checking underflow
	if(front==-1)
		printf("UNDERFLOW!\n");


	if(front==rear)//Ultimate case
	{	
		ele=Q[(front+1)%MAX];
		printf("Queue is EMPTY!\n");
		front=rear=-1;
	}

	else
	{	//General Case
		ele=Q[front];	
		front=(front+1)%MAX;	
		

	}

	return(ele);

}


void display()
{	int i;
	for(i=front;i!=rear;i=(i+1)%MAX)
	{
		printf(" %c \n",Q[i]);

	}
	printf(" %c",Q[i]);

}


void main()
{	int opt;
	char ele;

	while(1)	
	{	
		printf("\t\t\tMENU\n");
		printf("\t1.Insert\n");
		printf("\t2.Delete\n");
		printf("\t3.Display\n");
		printf("\t4.EXIT\n");

		printf("Enter option no : ");

		scanf("%d",&opt);


		
		switch(opt)
		{

			case 1:
				printf("Enter Element to insert:");
				scanf(" %c",&ele);//ele=getchar();//
				insert(ele);break;
			case 2:
				ele=delete();
				printf("Deleted Element is %c \n",ele);
				break;
		
			case 3:

				display();break;

			case 4:
				exit(0);

			default : printf("INVALID CHOICE\n");break;
		}


	}


}

/*
Design, Develop and Implement a menu driven Program in C for the following operations on
Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem, PhNo
a. Creating a SLL of N Students Data by using front insertion
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL (Demonstration of stack)
e. Exit
*/


#include<stdio.h>
#include<stdlib.h>

struct student
{
  char name[20];
  char usn[10];
  char branch[5];
  char phno[12];
  int sem;

  struct student *link ;

};

typedef struct student *node;


node start=NULL;


node create_node()
{
    node nn;
    //node temp;

    nn=(node)malloc(sizeof(struct student));
    if(nn==NULL)
    {
      printf("\n MEM NOT ALLOCATED!!!");

    }
    printf("Enter Name : ");
    scanf("%s",nn->name);

    printf("Enter USN : ");
    scanf("%s",nn->usn);

    printf("Enter Branch : ");
    scanf("%s",nn->branch);

    printf("Enter Ph No :");
    scanf("%s",nn->phno);

    printf("Enter Sem : ");
    scanf("%d",&nn->sem);

    nn->link=NULL;


    return(nn);
}



void front_insert()
{
  node n=create_node();
  if(start==NULL)
    start=n;
  else
  {
    n->link=start;
    start=n;
  }
}


void end_insert()
{
  node temp,new_node;
  new_node=create_node();
  if(start==NULL)
  {
    start=new_node;
  }
  else
  { temp=start;
    while(temp->link != NULL)
    {
      temp=temp->link;
    }

    temp->link=new_node;
    new_node->link=NULL;
  }
}



void front_del()
{
  node temp;
  temp=start;
  if(temp==NULL)
    printf("List is empty");//start=NULL;
  else
  {
    temp=start;
    start=start->link;
    free(temp);
  }
}

void end_del()
{
  node temp,prev;

  temp=start;

  if(temp==NULL)
  {
    printf("\n LIST IS EMPTY");
  }
  else if(temp->link==NULL)
  {
    printf ( "\nThe deleted student usn is %s", temp->usn );
    free ( temp );
    start = NULL;

  }

  else
  {
      while(temp->link!=NULL)
      {
        prev=temp;
        temp=temp->link;
      }
      printf("\nThe deleted student usn is %s ",temp->usn);
      free(temp);
      prev->link=NULL;
  }
}

void display_status()
{
  node temp=start;
  int ctr=1;
  if (start==NULL)
  {  printf("\nLIST EMPTY!!!!!\n");
  }
  else
  {
    while(temp!=NULL)
    {
      printf("\nNAME : %s\n",temp->name);
      printf("\nUSN : %s\n",temp->usn);
      printf("\nBRANCH : %s\n",temp->branch);
      printf("\nPhone No : %s\n",temp->phno);
      printf("\nSemester : %d\n",temp->sem);
      ctr+=1;
      temp=temp->link;

    }
    printf("TOTAL NO OF NODES IN THE LIST IS : %d",ctr-1);
  }
}

void create_list()
{
  int no,i;
  node n;

  printf("Enter no of students: ");
  scanf("%d",&no);

  for (i=0;i<no;i++)
  {
    n=create_node();

    if(start==NULL)
    {
      start=n;
    }

    else
    {
      n->link=start;
      start=n;

    }
  }
}
//stack_ops

int stack_ops()
{
  while(1)
  {
    printf("\n====STACK MENU======\n");

    printf("\n1.PUSH");
    printf("\n2.POP");
    printf("\n3.EXIT");
    int c;
    printf("\nEnter choice : ");
    scanf("%d",&c);
    switch(c)
    {
      case 1:end_insert();display_status();break;
      case 2:end_del();display_status();break;
      case 3:return(0);
      default:printf("Re-Enter \n");break;
    }
  }
}






void main()
{

  int n;int ch;
  printf("Input the number of Students:");
  scanf("%d",&n);

  while(1)
  {
    printf("\n\t\t\t MENU\n");
    printf("0.DISPLAY\n");
    printf("1.Create LL.\n");
    printf("2.Insert from front\n");
    printf("3.Delete from front\n");
    printf("4.Insert from end\n");
    printf("5.Delete from end\n");
    printf("6.Stack Ops\n");
    printf("7.EXIT\n");
    printf("Enter option no:");

    scanf("%d",&ch);

    switch(ch)
    {
      case 0: display_status();break;
      case 1: for(int i=0;i<n;i++)
                  front_insert();
              break;

      case 2:front_insert();break;
      case 3:front_del();break;
      case 4:end_insert();break;
      case 5:end_del();break;
      case 6:stack_ops();break;
      case 7:exit(0);

    }


  }
}

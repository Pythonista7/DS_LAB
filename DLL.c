/*
Design, Develop and Implement a menu driven Program in C for the following operations on
Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation,
Sal, PhNo
a. Creating a DLL of N Employees Data by using end insertion
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of DLL
d. Perform Insertion / Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue
f. Exit
*/
#include<stdio.h>
#include<stdlib.h>

struct Employee
{
  char SSN[20];
  char name[20];
  char dept[5];
  char desg[20];
  char sal[20];
  char phno[15];

  struct Employee* ll;
  struct Employee* rl;
};

typedef struct Employee* emp;

emp start=NULL;



emp create_node()
{
  emp node=malloc(sizeof(struct Employee));
  if(node==NULL)
    printf("Memory allocation failed.");
  else
  {
    printf("Enter SSN:");
    scanf("%s",node->SSN);

    printf("Enter Name:");
    scanf("%s",node->name);

    printf("Enter Dept:");
    scanf("%s",node->dept);

    printf("Enter Designation:");
    scanf("%s",node->desg);

    printf("Enter Sal:");
    scanf("%s",node->sal);

    printf("Enter PhNo:");
    scanf("%s",node->phno);

    node->ll=NULL;
    node->rl=NULL;

    return(node);

  }

}

//End Insertion
void end_insert()
{
  emp nn=create_node();
  emp temp=start;
  if(start==NULL)
    start=nn;
  else
  {
    while(temp->rl != NULL)
      temp=temp->rl;

    temp->rl=nn;
    nn->ll=temp;
    nn->rl=NULL;
  }

}

//Display and Count
void display()
{
  emp temp=start;
  int ctr=1;
  while(temp!=NULL)
  {
    printf("\n\ncount %d\n",ctr);
    printf("\nSSN:%s",temp->SSN);
    printf("\nName:%s",temp->name);
    printf("\nDept:%s",temp->dept);
    printf("\nSalary:%s",temp->sal);
    printf("\nDesignation:%s",temp->desg);
    printf("\nPhone Number:%s\n\n",temp->phno);
    temp=temp->rl;
    ctr++;
  }
  printf("\nTotal Count: %d",ctr-1);
}

//Delete at end
void end_delete()
{
  emp temp=start;
  while(temp->rl != NULL)
  {temp=temp->rl;
  }
  temp->ll->rl=NULL;
  free(temp);

}


//Insert at Front
void front_insert()
{
  emp nn=create_node();
  emp temp=start;
  temp->ll=nn;
  nn->rl=temp;
  nn->ll=NULL;
  start=nn;
}


//Delete at front
void front_delete()
{
  emp temp=start;
  start=temp->rl;
  free(temp);
}

//Demo Queue
int queue_ops()
{

  while(1)
  {
    printf("\n====QUEUE MENU======\n");

    printf("\n1.Enqueue front");
    printf("\n2.Dequeue front");
    printf("\n3.Enqueue back");
    printf("\n4.Dequeue back");
    printf("\n5.EXIT");
    int c;
    scanf("%d",&c);
    switch(c)
    {
      case 1:front_insert();display();break;
      case 2:front_delete();display();break;
      case 3:end_insert();display();break;
      case 4:end_delete();display();break;
      case 5:return(0);
      default:printf("Re-Enter \n");break;
    }
  }

}




void main()
{


  int n;int ch;
  printf("Input the number of Employees:");
  scanf("%d",&n);

  while(1)
  {
    printf("\t\t\t MENU\n");
    printf("0.DISPLAY\n");
    printf("1.Create DLL.\n");
    printf("2.Insert from front\n");
    printf("3.Delete from front\n");
    printf("4.Insert from end\n");
    printf("5.Delete from end\n");
    printf("6.Queue Ops\n");
    printf("7.EXIT\n");
    printf("Enter option no:");

    scanf("%d",&ch);

    switch(ch)
    {
      case 0: display();break;
      case 1: for(int i=0;i<n;i++)
                  end_insert();
              break;

      case 2:front_insert();break;
      case 3:front_delete();break;
      case 4:end_insert();break;
      case 5:end_delete();break;
      case 6:queue_ops();break;
      case 7:exit(0);

    }
  }
}

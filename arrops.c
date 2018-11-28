#include<stdio.h>
#include<stdlib.h>

int a[100];int n;
void input()
{	
	printf("Enter the no of elements :");
	scanf("%d",&n);
	//int a[n];
	for(int i=0;i<n;i++)
	{	
		printf("Enter the array element: \t ");
		scanf("%d",&a[i]);

	}
       

}


void display()
{
        for(int i=0;i<n;i++)
                printf("%d \t",a[i]);

}

void insert()
{
        int pos,ele;
        printf("Enter the element to insert");
        scanf("%d",&ele);

        printf("Enter the position of element to insert");
        scanf("%d",&pos);
	
	pos-=1;n++;
	
        for(int i=n-1;i>=pos;i--)
        { a[i]=a[i-1]; }

        a[pos]=ele;
        printf("The array after insertion is as follows\n");
        display();
 
}


void delete()
{
	int pos;
	printf("Enter the pos to delete:");
	scanf("%d ",&pos);pos-=1;
	for(int i=pos+1;i<=n;i++)
		a[i-1]=a[i];
	n--;
	printf("The array after deletions is as follows\n");
        display();
}

void main()
{	while(1)
	{
	printf("\n\nMenu\n\n");
	printf("1.Create\n");
	printf("2.Display\n");
	printf("3.Insert\n");
	printf("4.Delete\n");
	printf("5.Exit\n");
	
	int op;
	scanf("%d",&op);
	switch(op)
	{
		case 1:input();break;
		case 2:display();break;
		case 3: insert();break;
		case 4: delete();break;
		case 5: exit(0);break;

	}
	}
}	

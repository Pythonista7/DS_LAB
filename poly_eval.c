/*
Design, Develop and Implement a Program in C for the following operations on Singly
Circular Linked List (SCLL) with header nodes

Represent and Evaluate a Polynomial P(x,y,z) = 6x 2 y 2 z – 4yz 5 + 3x 3 yz + 2xy 5 z – 2xyz 3

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Polynomial
{
  int x_pow,y_pow,z_pow;
  int coeff;
  struct Polynomial *link ;

};


typedef struct Polynomial *node;



//malloc(sizeof(struct Polynomial));



node create_poly()
{
    node nn;
    //node temp;

    nn=(node)malloc(sizeof(struct Polynomial));
    if(nn==NULL)
    {
      printf("\n MEM NOT ALLOCATED!!!");
      return(nn);
    }
    
    //nn->link=NULL;


    return(nn);
}

node insert_poly(node head,int x_pow,int y_pow,int z_pow,int coeff)
{

    node nn=create_poly();
    node temp;

    nn->x_pow=x_pow;
    
    nn->y_pow=y_pow;
    
    nn->z_pow=z_pow;

    nn->coeff=coeff;

    nn->link=NULL;

    temp=head->link;
/*
    if(head->link==head)
    {   printf("First HEAD\n");
        head=nn;
        return(head);
    }
*/
    while(temp->link!=head)
        temp=temp->link;
    
    temp->link=nn;
    nn->link=head;
    
    
    return(head);

}

node input_poly(node head)
{
    int x_pow,y_pow,z_pow,coeff;char ch;
    while(1)
    {
    printf("Enter x_pow: ");
    scanf("%d",&x_pow);

    printf("Enter y_pow: ");    
    scanf("%d",&y_pow);

    printf("Enter z_pow: ");    
    scanf("%d",&z_pow);

    printf("Enter coefficient: ");    
    scanf("%d",&coeff);

    head=insert_poly(head,x_pow,y_pow,z_pow,coeff);

    printf("End of polynomial?(y/n)");
    
    scanf(" %c",&ch);



    if(ch=='y')
        break;
    
    }
    
    return(head);
}

/*Function definition to display the list.*/
void display ( node head )
{
        node temp;
        
        if ( head->link == head )
        {
                printf ( "\nPolynomial doesnt exist!!!" );
                return;
        }
        
        temp = head->link;
        
        while ( temp != head )
        {
                printf ( "%d (x %d   y%d   z%d ) +", temp->coeff, temp->x_pow, temp->y_pow, temp->z_pow );
                temp = temp->link;
        }
}

int poly_eval(node head, int x , int y, int z)
{
    int res=0;
    node temp=head->link;
    while(temp!=head)
    {   printf("xp=%d , yp=%d , zp=%d ",temp->x_pow,temp->y_pow,temp->z_pow);
        res+=(pow(x,temp->x_pow) * pow(y,temp->y_pow) * pow(z,temp->z_pow) * temp->coeff );
        temp=temp->link;
        printf("\nLOOP DONE %d\n",res);
    }

    return(res);

}


void main()
{
    
    printf("\nEnter the polynomial expression:");
    node head;
    head=create_poly();
    head->link=head;        
    head=input_poly(head);
    
    int x,y,z;
    printf("Enter the values of x ");
    scanf("%d",&x);
    printf("Enter the values of y ");
    scanf("%d",&y);
    printf("Enter the values of z ");
    scanf("%d",&z);
    
    int res;
    res=poly_eval(head,x,y,z);
    printf("Result=%d\n",res);
    display(head);

}
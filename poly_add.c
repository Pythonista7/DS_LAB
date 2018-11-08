/* 

In addition of any two Polynomial, Compare the power of X,Y and Z if they are equal, add their Coefficients.

Consider poly1=5x2y3z2+3x2yz2+4xyz and  poly2 = 5x2y3z2 + 4xyz + 10x2yz2. if we add poly1 and poly2 then resultant poly3=10x2y3z2+13x2yz2+8xyz.    

Find the sum of two polynomial POLY1(x,y,z) and POLY2(x,y,z) and store the result in POLYSUM(x,y,z)
Support the program with appropriate functions for each of the above operations

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
    //printf("Going to Insert");


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
                printf ( "%d (x^%d   y^%d   z^%d ) +", temp->coeff, temp->x_pow, temp->y_pow, temp->z_pow );
                temp = temp->link;
        }
}

node poly_add(node h1,node h2,node res)
{
    
    
    node ctr1=h1->link,ctr2=h2->link;
    int flag;int xp,yp,zp,cval;
    while(ctr1!=h1)
    {   ctr2=h2->link;flag=0;
        while(ctr2!=h2)
        {
            if(ctr1->x_pow == ctr2->x_pow && ctr1->y_pow == ctr2->y_pow && ctr1->z_pow == ctr2->z_pow)
            {  
                
                xp=ctr1->x_pow;
                yp=ctr1->y_pow;
                zp=ctr1->z_pow;
                cval=ctr1->coeff +ctr2->coeff;
                res=insert_poly(res,xp,yp,zp,cval);
                flag=1;
                break;
            
            }
            ctr2=ctr2->link;

        }
        if(flag==0)
        {
            xp=ctr1->x_pow;
            yp=ctr1->y_pow;
            zp=ctr1->z_pow;
            cval=ctr1->coeff;
            res=insert_poly(res,xp,yp,zp,cval);
        }
        ctr1=ctr1->link;
        
    }
    while(ctr1!= h1)
    {    res=insert_poly(res,ctr1->x_pow,ctr1->y_pow,ctr1->z_pow,ctr1->coeff);
         ctr1=ctr1->link;
    }

    while(ctr2!= h2)

    {   res=insert_poly(res,ctr2->x_pow,ctr2->y_pow,ctr2->z_pow,ctr2->coeff);
        ctr2=ctr2->link;
    }



    return(res);
}




void main()
{   node poly1,poly2,poly_res;
   
    poly1=create_poly();poly1->link=poly1;
    poly2=create_poly();poly2->link=poly2;
    poly_res=create_poly();poly_res->link=poly_res;
   
   
    printf("\nPolynomial 1 :\n ");
    poly1=input_poly(poly1);
    display(poly1);
    printf("\nPolynomial 2 :\n ");
    poly2=input_poly(poly2);
    display(poly2);
    //poly_res=create_poly();

    poly_res=poly_add(poly1,poly2,poly_res);
    printf("\nRESULT!!!!!!!!\n");
    display(poly_res);




}
/*
Given a File of N employee records with a set K of Keys(4-digit) which uniquely determine
the records in file F. Assume that file F is maintained in memory by a Hash Table(HT) of m
memory locations with L as the set of memory addresses (2-digit) of locations in HT. Let the
keys in K and addresses in L are Integers. Design and develop a Program in C that uses Hash
function H: K ®L as H(K)=K mod m (remainder method), and implement hashing technique
to map a given key K to the address space L. Resolve the collision (if any) using linear
probing
*/






#include<stdio.h>
#include<stdlib.h>



#define MAX 10

FILE *fp;

int f[MAX];
int HT[MAX]={0};

//void display();
void probe(int , int );


void main()
{	
	int i;int L;
	fp=fopen("data.txt","r");
	for(i=0;i<MAX;i++)
		fscanf(fp,"%d",&f[i]);
	printf("FILE CONTENTS\n");
	for(i=0;i<MAX;i++)
		printf("%d==> %d\n",i,f[i]);

	for(i=0;i<MAX;i++)
	{
		L=f[i]%MAX;
		if(HT[L]==0)	
			HT[L]=f[i];
		else
			probe(f[i]+1,f[i]);

	}

	printf("\n\n\nHASH TABLE :\n");
	for(i=0;i<MAX;i++)
		printf("%d==> %d\n",i,HT[i]);

}

void probe(int k,int key)
{

	int L,i;
	
	L=k%MAX;

	if(HT[L]==0)
		HT[L]=key;

	else
		probe(k+1,key);

}

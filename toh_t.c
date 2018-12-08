//Tower of Hanoi

#include<stdio.h>

void toh(int n,char S,char A,char D)
{
	if(n==1)
		printf("Disk is moved from %c to %c\n",S,D);
	else
	{	toh(n-1,S,D,A);
		printf("Disk is moved from %c to %c\n",S,D);
		toh(n-1,A,S,D);

	}

}

void main()
{
	int num;
	printf("Enter no of disks:");
	scanf("%d",&num);
	toh(num,'X','Y','Z');

}

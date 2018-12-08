/*
Design, Develop and Implement a Program in C for the following operations on Graph(G) of
Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using BFS method
c. Check whether a given graph is connected or not using DFS method.
*/



#include<stdio.h>
#include<stdlib.h>

int N,adj_mat[50][50];int v[50]={0};
int front=-1,rear=-1;int q[50]={0};

void create()
{
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{	if(i==j){adj_mat[i][j]=0; continue;}

			printf("Is %d accessable from %d ==> ",i+1,j+1);
			scanf("%d",&adj_mat[i][j]);

		}

	}
}

void DFS(int source)
{	
	
	v[source]=1;
	printf("%d  ",source);
	for(int i=0;i<N;i++)
	{
		if(adj_mat[source][i]==1 && v[i]==0)
		{
			DFS(i);

		}

	}	



}


int vBFS[50]={0};//Visited matrix for BFS

void BFS(int source)
{

	front=0;rear=-1;
	//insert source
	q[++rear]=source;
	vBFS[source]=1;
	printf("%d ",source);


	while(front<=rear)
	{
		source=q[front++];
		
		for(int i=0;i<N;i++)
		{
			if(adj_mat[source][i]==1 && vBFS[i]==0)
			{
				printf("%d ",i);		
				vBFS[i]=1;
				q[++rear]=i;

			}

		}


	}



}


void main()
{
	
	printf("\nEnter no of cities:\t");
	scanf("%d",&N);	
	


	printf("Create Graph\n");
	create();
	
	//printf("Adj Mat \n\n");
	
	printf("\n\nDFS\n\n");
	DFS(0);

	
	printf("\n\nBFS\n\n");
	BFS(0);
}





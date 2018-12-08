/*
Design, Develop and Implement a Program in C for the following operations on Strings

a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)

b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR ,with REP if PAT exists in STR. Report suitable messages in case PAT does not exist in STR .Support the program with functions for each of the above operations. Don’t use Built-in functions.
*/

#include<stdio.h>

char str[25],pat[25],rep[25];
int s_len=0,p_len=0,r_len=0;




void replace(int i)
{	int k=0;
	while(rep[k]!='\0')
		str[i++]=rep[k++];

}



void check()
{
	while(str[s_len]!='\0') s_len++;
	while(pat[p_len]!='\0') p_len++;
	while(rep[r_len]!='\0') r_len++;

	int i,j,t;

	for(i=0;i<s_len;i++)
	{
		for(j=0,t=i;j<p_len;j++,t++)
		{
			if(str[t]==pat[j])
			{
			
				if(j==p_len-1)
				{
					printf("FOUND!\nREPLACING\n...\n");
			    		replace(i);				
					break;				
				}

			}
			else 
				break;

	
		}

	}

}


void main()
{


	printf("Enter STR :");
	scanf("%s",str);
	printf("Enter PAT :");
	scanf("%s",pat);
	printf("Enter REP :");
	scanf("%s",rep);

	check();
	
	printf("NEW STR IS: \n %s \n",str);
}

#include <stdio.h> 
#include <stdio.h> 
#include <stdlib.h>


#define N_MAX_USER			5
#define N_MAX_GO			17
#define N_MAX_BET			5


//betting
void main()
{
	int input;
	int dollar[N_MAX_USER]={50,50,50,50,50}; 
	int n_user;
	int i;

	
	printf("number(5):");
	scanf("%d",&n_user);
	
	printf("bet your money(max:%d): ",dollar[0]);
	scanf("%d",&input);
		
	for(i=1;i<n_user;i++);
	{
		printf("player[%d]: %d",i,1+rand()%dollar[i]);
	}
	
}



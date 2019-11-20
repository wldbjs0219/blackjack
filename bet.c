#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

extern int bet[N_MAX_USER];
extern int dollar[N_MAX_USER];
extern int n_user;

//betting
void bet_dollar(void)
{
	int input;
	int i;
	
	printf("bet your money(max:%d): ",dollar[0]);
	scanf("%d",&input);
	bet[0]= input;
		
	for(i=1;i<n_user;i++);
	{
		bet[i]=1+rand()%dollar[i]
		printf("player[%d]: %d",i,bet[i]);
	}
}

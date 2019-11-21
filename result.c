#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "cardinform.c"

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

extern int cardcnt[N_MAX_USER];
extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];
extern int cardSum[N_MAX_USER];
extern int dollar[N_MAX_USER];
extern int gameEnd;
extern int n_user;
extern int roundIndex;

// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int user) {
	int i;
	
	for(i=0;i<cardcnt[user];i++)
	{
		cardhold[user][i]=getCardNum(cardhold[user][i]);
		cardSum[user]+=cardhold[user][i];
	}
	
	return cardSum[user];
}

int checkResult(void) {

	int i;
	printf("------- ROUND %d RESULT -------",roundIndex);
	
	//your result
	//case: win
	if(cardSum[0]<=21)
	{
		if(cardSum[0]==21)
		{
			printf("--> your result: win! due to Blackjack --> dollar(%d)\n",dollar[0]);
		}
		
		else if(cardSum[0]<21 && cardSum[0]>=cardSum[n_user])
		{
			printf(" --> your result: win! sum(%d) --> dollar(%d)\n",cardSum[0],dollar[0]);
		}
	//lose
		else if (cardSum[0]<21 && cardSum[0]<cardSum[n_user])
		{
			printf(" --> your result: lose! sum(%d) --> dollar(%d)\n",cardSum[0],dollar[0]);
		}
	}
	else if(cardSum[0]>21)
	{
		printf("--> your result: lose! due to overflow --> dollar(%d)\n",dollar[0]);		
	}
	
	//bankrupt	
	if(dollar[0]==0)
	{
		printf("--> You are bankrupted!! game will be ended\n");
		gameEnd=1;
	}
	
	//players result
	for(i=1;i<n_user;i++)
	{
	//case: win
		if(cardSum[i]<=21)
		{
			if(cardSum[i]==21)
			{
				printf("--> %dth Player result: win! due to Blackjack --> dollar(%d)\n",i,dollar[i]);
			}
		
			else if(cardSum[i]<21 && cardSum[0]>=cardSum[n_user])
			{
				printf(" --> %dth Player result: win! sum(%d) --> dollar(%d)\n",i,cardSum[i],dollar[i]);
			}
	//lose
			else if (cardSum[i]<21 && cardSum[0]<cardSum[n_user])
			{
				printf(" --> %dth Player result: lose! sum(%d) --> dollar(%d)\n",i,cardSum[i],dollar[i]);
			}
		}
		else if(cardSum[i]>21)
		{
			printf("--> %dth Player result: lose! due to overflow --> dollar(%d)\n",i,dollar[i]);
		}
		
	//bankrupt	
		if(dollar[i]==0)
		{
			printf("--> %dth plyer is bankrupted!! game will be ended\n");
			gameEnd=1;
		}
	}
}

int checkWinner(void) {
	int i;
	int max=dollar[0];
	int winer=0;        			//winer plqyer number
	
	printf("game end! your money: %d dollar, ",dollar[0]);
	printf(" players's money: ");
	for(i=1;i<n_user;i++)
	{
		printf("%d dollar  ",dollar[i]);
		if(max<dollar[i])
		{
			max=dollar[i];
			winer=i;
		}
	}
	
	if(max==dollar[0])
	{
		printf("\n\n winer is you!\n");
	}
	else if(max!=dollar[0])
	{
		printf("\n\n winer is %dth player!\n",winer);
	}
	
	return 0;
}
	

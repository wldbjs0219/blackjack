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


// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int user) {
	
	for(i=0;i<cardcnt[user];i++)
	{
		cardhold[user][i]=getCardNum(cardhold[user][i]);
		cardSum[user]+=cardhold[user][i];
	}
	
	return cardSum[user];
}

int checkResult(int user) { 
	
	printf("------- ROUND %d RESULT -------",roundindex);
	
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
		else
		{
			printf("--> your result: lose! due to overflow --> dollar(%d)\n",dollar[0]);
		}
		
	//players result
	for(i=1;i<n_user;i++)
	{
	//case: win
		if(cardSum[i]<=21)
		{
			if(cardSumi0]==21)
			{
				printf("--> %dth Player result: win! due to Blackjack --> dollar(%d)\n",i,dollar[i]);
			}
		
			else if(cardSum[0]<21 && cardSum[0]>=cardSum[n_user])
			{
				printf(" --> %dth Player result: win! sum(%d) --> dollar(%d)\n",i,cardSum[i],dollar[i]);
			}
	//lose
			else if (cardSum[0]<21 && cardSum[0]<cardSum[n_user])
			{
				printf(" --> %dth Player result: lose! sum(%d) --> dollar(%d)\n",i,cardSum[i],dollar[i]);
			}	
			else
			{
				printf("--> %dth Player result: lose! due to overflow --> dollar(%d)\n",i,dollar[i]);
			}
	               
}

int checkWinner() {

	
}

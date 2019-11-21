#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "function.h"

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10

//card tray object
extern int CardTray[N_CARDSET*N_CARD];
extern int cardIndex = 0;						
					
extern int n_user;  // number of players

//play yard information
extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];		//cards that currently the players hold 

extern int cardcnt[N_MAX_USER]={2,2,2,2,2};


//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {
	int i;
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<52;i++)
	{
	 	CardTray[i]=rand()%52 +1;
	}
	
}

//get one card from the tray
int pullCard(void) {

	return CardTray[cardIndex ++];
}

//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two card for each players
	for (i=0;i<n_user;i++)
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
		
	}
	//2. give two card for the operator
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
	
}

void printCardInitialStatus(void) {
	int i,j,k;
	
	printf("------server: ? , ");
	{
		printCard(cardhold[n_user][1]);
	}
	
	printf("      -> you: ");
	for(i=0;i<2;i++);
	{
		printCard(cardhold[0][i]);
	}
	
	for(j=1;j<n_user;j++)
	{
		printf("      -> player %d: ",j);
		for(k=0;k<2;k++)
		{
			printCard(cardhold[j][k]);
		}	
	}
}

void printUserCardStatus(int user) {    			
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt[user];i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}



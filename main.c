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

//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							

//player info
int dollar[N_MAX_USER]={50,50,50,50,50};   //dollars that each player has					
int n_user;  // number of players

//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold 
int cardSum[N_MAX_USER];	//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag




//betting
/*
void bet_dollar()
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
*/

//card array controllers -------------------------------


//mix the card sets and put in the array
int mixCardTray(void) {
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<52;i++)
	{
	 	CardTray[i]=rand()%52 +1;
	}
	
	
	

}

//get one card from the tray
int pullCard(void) {
	int i=0;
	int card=0;   
	
	card=CardTray[i];
	i++;
	
	return card
}


//playing game functions -----------------------------

//player settiing
int configUser(void) {
	
	printf("input the number (max:5):");
	scanf("%d",&n_user);	
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
	
	return;
}






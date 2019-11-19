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
int dollar[N_MAX_USER]={50,50,50,50,50};   		//dollars that each player has					
int n_user;  // number of players

//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];		//cards that currently the players hold 
int cardSum[N_MAX_USER];						//sum of the cards
int bet[N_MAX_USER];							//current betting 
int gameEnd = 0; 								//game end flag

//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)
int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) 								//if it fails to get integer
        input = -1;
    
    return input;
}
//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	
	cardnum
	
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {

	if(cardnum>=1 && cardnum>=13)  // 1~13: heart
	{
		if(cardnum==1)
		{
			printf("heart A ");
		}
		else if(cardnum>1 && cardnum <11)
		{
			printf("heart %d ", cardnum);
		}
		else if(cardnum==11)
		{
			printf("heart J ");
		}
		else if(cardnum==12)
		{
			printf("heart Q ");
		}
		else if(cardnum==13)
		{
			printf("heart K ");
		}
	} 
	 
	else if(cardnum>=14 && cardnum>=26)  //14~26: dia
	{
		if(cardnum==1)
		{
			printf("dia A ");
		}
		else if(cardnum>1 && cardnum <11)
		{
			printf("dia %d ", cardnum);
		}
		else if(cardnum==11)
		{
			printf("dia J ");
		}
		else if(cardnum==12)
		{
			printf("dia Q ");
		}
		else if(cardnum==13)
		{
			printf("dia K ");
		}
	}
		else if(cardnum>=27 && cardnum>39)  //27~39: spade
	{
		if(cardnum==1)
		{
			printf("heart A ");
		}
		else if(cardnum>1 && cardnum <11)
		{
			printf("heart %d ", cardnum);
		}
		else if(cardnum==11)
		{
			printf("heart J ");
		}
		else if(cardnum==12)
		{
			printf("heart Q ");
		}
		else if(cardnum==13)
		{
			printf("heart K ");
		}
	}
	else if(cardnum>=40 && cardnum>=52)  //40~52 : club
	{
		if(cardnum==1)
		{
			printf("heart A ");
		}
		else if(cardnum>1 && cardnum <11)
		{
			printf("heart %d ", cardnum);
		}
		else if(cardnum==11)
		{
			printf("heart J ");
		}
		else if(cardnum==12)
		{
			printf("heart Q ");
		}
		else if(cardnum==13)
		{
			printf("heart K ");
		}
	}
	 
}
	


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

//betting

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

//print initial card status
void printCardInitialStatus(void) {
	
}

int getAction(void) {
	
}


void printUserCardStatus(int user, int cardcnt) {  //cardcnt=Ä«µå¹Þ´ÂÈ½  
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {
	
}

int checkResult() {
	
}

int checkWinner() {
	
}





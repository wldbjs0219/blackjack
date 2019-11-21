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
int cardSum[N_MAX_USER]={0,0,0,0,0};			//sum of the cards
int bet[N_MAX_USER];							//current betting 
int gameEnd = 0; 								//game end flag
int cardcnt[N_MAX_USER]={2,2,2,2,2};			// number received card 

int roundIndex = 1;

//function linking
void printCard(int cardnum);
int getCardNum(int cardnum);
void swap(int a, int b);
void mixCardTray(void);
int pullCard(void);
void offerCards(void);
void printCardInitialStatus(void);
void printUserCardStatus(int user);
void bet_dollar(void);
int getIntegerInput(void);
int getAction(int user);
int calcStepResult(int user);
int checkResult();
int checkWinner(void);

int configUser(void) {
	
	do
	{
		printf("input the number (max:5):");
		scanf("%d",&n_user);
	}
	while(n_user < 1 || n_user > 5);
		
}

int main(int argc, char *argv[]) {
	int max_user;
	int i=2;
	int j;
	int input;
	
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	configUser();   //scanf 가 아닌 교수님이 주신걸로? 


	//Game initialization --------
	//1. players' dollar
	//2. card tray
	mixCardTray();
	printf("card is mixed and put into the tray \n");



	//Game start --------
	do {     				//round replay
		printf("\n --------------------\n-----------------Round %d (cardIndex: %d)-----------------\n--------------------",roundIndex,cardIndex);
		
		//betting
		printf("------BETTING STEP------\n"); 
		bet_dollar();
		printf("--------------------\n");
		
		//offering
		printf("\n------CARD OFFERING------\n");
		offerCards(); 								//1. give cards to all the players
		printCardInitialStatus();
		
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		//my turn
		printf(">>> my turn!-------\n");
		do   
		{	printUserCardStatus(0);  //print current card status printUserCardStatus();
			calcStepResult(0);       //check the card status ::: calcStepResult()
			
			if(cardSum[0]<21)
			{
				getAction(0);
			}

			else if(cardSum[0]>21)
			{
				dollar[0] -= bet[0];
				printf("Dead (sum: %d) --> lose: -%d (dollar: &d)\n ",cardSum[0],bet[0],dollar[0]);
			}
			else 
			{
				dollar[0] += (2*bet[0]);
				printf("Blackjack!! you win! --> get: +%d (dollar: %d)\n",2*bet[0],dollar[0]);
			}
		}while(cardSum[0]<21 || input!=0); 	//do until the player dies or player says stop
		
		//computer players turns
		for (j=1;j<n_user;j++) 						//each player
		{
			printf(">>> Player %d turn!-------\n",j);
			
			do
			{	
				printUserCardStatus(j);   //print current card status printUserCardStatus();
				calcStepResult(j);       //check the card status ::: calcStepResult()
			
				if(cardSum[j]>=0 && cardSum[j]<=20)
				{	
					getAction(j);
				}
				else if(cardSum[j]>21)
				{
					dollar[j] -= bet[j];
					printf("Dead (sum: %d) --> lose: -%d (dollar: &d)\n ",cardSum[j],bet[j],dollar[j]);
				}
				else 
				{
					dollar[j] += (2*bet[j]);
					printf("Blackjack!!  --> get: +%d (dollar: %d)\n",2*bet[j],dollar[j]);
				}
			}while(cardSum[j]<17);
		}
		
		//dealer turn
		printf(">>> Dealer turn!-------\n");
		
		do{	
			printUserCardStatus(n_user);   //print current card status printUserCardStatus();
			calcStepResult(n_user);       //check the card status ::: calcStepResult()
			
			if(cardSum[n_user]>=0 && cardSum[n_user]<=20)
			{	
				getAction(j);
			}
			else if(cardSum[n_user]>21)
			{
				printf("   ::: Dead (sum: %d)\n",cardSum[n_user]);
				printf("[[[[[[dealer result is .......overflow!\n]]]]]]");
			}
			else 
			{
				printf("[[[[[[dealer result is .......blackjack!\n]]]]]]");
			}
			
		}while(cardSum[n_user]<17);
		
	//result
	checkResult();
	roundIndex ++;
	}while(gameEnd==0);

	checkWinner();
	
	return 0;
}







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
int cardSum[N_MAX_USER]=[0,0,0,0,0];			//sum of the cards
int bet[N_MAX_USER];							//current betting 
int gameEnd = 0; 								//game end flag

int cardcnt=2;									// number received card

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
int getCardNum(int cardnum) {             				 //cardnum=input a number on a card 
	
	int calnumber; 								 		//the number for calculation(ex. heart j=10)
	
	if(cardnum==1 || cardnum==14 || cardnum==27 || cardnum==40)
	{
		calnumber=1;
	}
	
	else if(cardnum >=2 && cardnum<=10 || cardnum >=15 && cardnum<=23 || cardnum >=28 && cardnum<=36 || cardnum >=41 && cardnum<=49)
	{
		calnumber=cardnum % 13 ;
	}
	
	else 
	{
		calnumber=10;
	}

	return calnumber;
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
		else 
		{
			printf("heart K ");
		}
	} 
	else if(cardnum>=14 && cardnum>=26)  //14~26: dia
	{
		if(cardnum==14)
		{
			printf("dia A ");
		}
		else if(cardnum>14 && cardnum<24)
		{
			printf("dia %d ", cardnum-13);
		}
		else if(cardnum==24)
		{
			printf("dia J ");
		}
		else if(cardnum==25)
		{
			printf("dia Q ");
		}
		else
		{
			printf("dia K ");
		}
	}
	else if(cardnum>=27 && cardnum>=39)  //27~39: spade
	{
		if(cardnum==27)
		{
			printf("spade A ");
		}
		else if(cardnum>27 && cardnum <37)
		{
			printf("spade %d ", cardnum-26);
		}
		else if(cardnum==37)
		{
			printf("spade J ");
		}
		else if(cardnum==38)
		{
			printf("spade Q ");
		}
		else
		{
			printf("spade K ");
		}
	}
	else if(cardnum>=40 && cardnum>=52)  //40~52 : club
	{
		if(cardnum==40)
		{
			printf("club A ");
		}
		else if(cardnum>40 && cardnum <50)
		{
			printf("club %d ", cardnum-39);
		}
		else if(cardnum==50)
		{
			printf("club J ");
		}
		else if(cardnum==51)
		{
			printf("club Q ");
		}
		else
		{
			printf("club K ");
		}
	}
	 
}
	
//card array controllers -------------------------------
/*
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
	
	return card;
}
*/

//playing game functions -----------------------------

//player settiing
int configUser(void) {
	
	printf("input the number (max:5):");
	scanf("%d",&n_user);
	
}
/*
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
	
}
*/

//print initial card status
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

int getAction(void) {
	
	int num=2;
	int input;
	
	printf("ACTION? ( 0 - go, others - stay )");
	getIntegerInput();
		
	if(input==0)
	{
		cardhold[0][num]= pullCard();
	}
}

void printUserCardStatus(int user) {    			//cardcnt=the number of getting a card 
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}


// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int playernum) {  

}
	



int checkResult(int playernum) {                  // playernum: you-0, player-1~, dealer- n_user
	
	int i
	
	for(i=0;i<cardcnt;i++)
	{
		cardSum[playernum] += cardhold[playernum][j];
	}
	
	if(cardSum <=21)
	{
		if(cardSum = 21)
		{
			dollar[playernum]+=bet[playernum];
			printf("        :::blackjack!! win!! --> + %d (%d)",bet[playernum],dollar[playernum]);
		}
		else if(cardSum < 21)
		{
			printf("sum is %d",)
		}
	
	}	
}

int checkWinner() {
	
	printf("     ->your result: ")
	
}





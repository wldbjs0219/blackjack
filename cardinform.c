#include <stdio.h> 
#include <stdlib.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50

#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

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

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {             				 //cardnum=input a number on a card 
	
	int calnumber; 								 		//the number for calculation(ex. heart j=10)
	
	if(cardnum >=2 && cardnum<=10 || cardnum >=15 && cardnum<=23 || cardnum >=28 && cardnum<=36 || cardnum >=41 && cardnum<=49)
	{
		calnumber=cardnum % 13;
	}
	
	else if(cardnum>=11 && cardnum<=13 || cardnum>=24 && cardnum<=26 || cardnum>=37 && cardnum<=39 || cardnum>=50 && cardnum<=52 )
	{
		calnumber=10;
	}

	return calnumber;
}



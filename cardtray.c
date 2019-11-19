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
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

extern int CardTray[N_CARDSET*N_CARD];
//get one card from the tray

int pullCard(int *ptr) {
	int card;   
	
	card=CardTray[*ptr];
	ptr++;

	return card;
	
}

int main(void)
{ 		
	int i;
	int n_user=3;
	int cardhold[3][2];
	
	for (i=0;i<n_user;i++)
	{
		cardhold[i][0] = pullCard(&i);
		cardhold[i][1] = pullCard(&i+1);
		
		printf("%f\n, %f\n",cardhold[i][0],cardhold[i][1]);
	}

}

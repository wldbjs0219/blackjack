#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

int getIntegerInput(void);
int configUser(void);
void printCardInitialStatus(void);
int getAction(void);
void printUserCardStatus(int user);
int getCardNum(int cardnum);
void printCard(int cardnum);
int mixCardTray(void);
int pullCard(void);
void offerCards(void);
void bet_dollar;
int calcStepResult(int playernum);
int checkResult();
int checkWinner();

#ifndef _DECLARATIONS_H_
#define _DECLARATIONS_H_

/*Declaration of card data*/
typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

/*Declaration of terminal data*/
typedef struct ST_terminalData_t
{
	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_terminalData_t;

/*Declaration of server data*/
typedef struct ST_accountBalance_t
{
	float balance;
	uint8_t primaryAccountNumber[20];
}ST_accountBalance_t;

/*Declaration of check cases*/
typedef enum EN_transStat_t
{
	DECLINED,
	APPROVED
}EN_transStat_t;

ST_cardData_t customer; //Declaration of variable of the ST_cardData_t type
ST_terminalData_t data1; //Declaration of variable of the ST_terminalData_t type

/*Declaration of global array that holds customers' information*/
ST_accountBalance_t g_arr[10]={{100.00,"123456789"},{6000.0,"234567891"},{3250.25,"567891234"},{1500.12,"456789123"},{500.00,"258649173"},{2100.00,"654823719"},
								{0.00,"971362485"},{1.00,"793148625"},{10.12,"123123456"},{0.55,"456789321"}};

EN_transStat_t result; //Declaration of variable of the ST_transStat_t type
uint8_t gu8_size=sizeof(g_arr)/sizeof(ST_accountBalance_t);// size of the array

/*Declaration of a function that check the card is expired or not and return the result */
uint8_t Check_cardExp(ST_cardData_t customer,ST_terminalData_t data1);

/*Declaration of Sorting elements*/
void Check_sorting(ST_accountBalance_t* g_arr,uint8_t gu8_size);

/*Declaration of a function that check the balance and the PAN exist or not and return the result */
uint8_t Check_server(ST_accountBalance_t* g_arr,ST_terminalData_t data1,ST_cardData_t customer);

#endif
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


/*Declaration of a function that check the card is expired or not and return the result */
uint8_t Check_cardExp(ST_cardData_t customer,ST_terminalData_t data1);

/*Declaration of Sorting elements*/
void Check_sorting(ST_accountBalance_t* g_arr,uint8_t gu8_size);

/*Declaration of a function that check the balance and the PAN exist or not and return the result */
uint8_t Check_server(ST_accountBalance_t* g_arr,ST_terminalData_t data1,ST_cardData_t customer);

#endif
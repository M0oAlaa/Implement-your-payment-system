#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"Declarations.h"

void main(void)
{
	fflush(stdin);
	system("cls");
	/*Declaration of some local variables*/
	uint8_t u8_ExpCkeck=0;
	uint8_t u8_next;
	data1.maxTransAmount=5000.0; // Assign the max trans value
	while(1)
	{
		printf("Please Enter Card Data:\n");
		printf("Please Enter the Card Holder Name: ");
		gets((char*)customer.cardHolderName);
		
		printf("Please Enter the Primary Account Number: ");
		gets((char*)customer.primaryAccountNumber);
		
		printf("Please card Expiry Date'MM/YY': ");
		gets((char*)customer.cardExpirationDate);
		
		printf("Please Enter Terminal Data:\n");
		printf("Please Enter the transaction Amount: ");
		scanf("%f",&data1.transAmount); fflush(stdin);
		
		/*Check if the amout is over the max trans or not*/
		if(data1.transAmount>data1.maxTransAmount)
		{
			printf("The Transaction is DECLINED.");// if yes -> Decline
		}
		else if(data1.transAmount<=data1.maxTransAmount)
		{
			/*if no -> ask for the transaction date*/
			printf("Please Enter transaction Date'DD/MM/YY': ");
			gets((char*)data1.transactionDate);
			
			/*Check if the card is expired or not and return the result*/
			u8_ExpCkeck=Check_cardExp(customer,data1);
			/*if yes verify data from the server*/
			if(u8_ExpCkeck==APPROVED)
			{
				printf("Verifying Data from the server...\n");
				u8_ExpCkeck=Check_server(g_arr,data1,customer);
				/*if the data is the same -> APPROVE*/
				if(u8_ExpCkeck==APPROVED)
				{
					printf("The Transaction is APPROVED.");
				}
				/*if not -> DECLINE*/
				else
				{
					printf("The Transaction is DECLINED.");
				}
			}
			/*if not -> Decline*/
			else if(u8_ExpCkeck==DECLINED)
			{
				printf("The Transaction is DECLINED.");
			}
		}
		/*Ask the user if he want to make a new transaction*/
		printf("\nDo you want to continue (y/n)?:\n");
		scanf("%c",&u8_next); fflush(stdin);
		if(u8_next=='n')
		{
			break;
		}
		else
		{
			
		}
	}
}

/*Implementation of expiration date of the card and return the result*/
uint8_t Check_cardExp(ST_cardData_t customer,ST_terminalData_t data1)
{
	uint8_t u8_return;
	if(customer.cardExpirationDate[3]>data1.transactionDate[8])
	{
		u8_return=APPROVED;
	}
	else if (customer.cardExpirationDate[3]<data1.transactionDate[8])
	{
		u8_return=DECLINED;
	}
	else if (customer.cardExpirationDate[3]==data1.transactionDate[8])
	{
		if(customer.cardExpirationDate[4]>data1.transactionDate[9])
		{
			u8_return=APPROVED;
		}
		else if (customer.cardExpirationDate[4]<data1.transactionDate[9])
		{
			u8_return=DECLINED;
		}
		else if(customer.cardExpirationDate[4]==data1.transactionDate[9])
		{
			if(customer.cardExpirationDate[0]>data1.transactionDate[3])
			{
				u8_return=APPROVED;
			}
			else if (customer.cardExpirationDate[0]<data1.transactionDate[3])
			{	
				u8_return=DECLINED;
			}
			else if (customer.cardExpirationDate[0]==data1.transactionDate[3])
			{
				if(customer.cardExpirationDate[1]<data1.transactionDate[4])
				{
					u8_return=DECLINED;
				}
				else
				{
					u8_return=APPROVED;
				}
			}
			
		}
	}
	return u8_return;
}

/*Implementation of sorting elements*/
void Check_sorting(ST_accountBalance_t* g_arr,uint8_t gu8_size)
{
	uint8_t u8_i;
	uint8_t u8_j;
	uint8_t u8_z;
	uint8_t u8_flag;
	ST_accountBalance_t u8_temp;
	for(u8_i=0;u8_i<(gu8_size-1);u8_i++)
	{
		
		if(g_arr[u8_i].primaryAccountNumber[0]<g_arr[u8_i+1].primaryAccountNumber[0])
		{
			u8_flag=1;
		}
		
		else
		{
			u8_flag=0;break;
		}
	}
	
	if(u8_flag==0)
	{
		
		for(u8_i=0;u8_i<(gu8_size-1);u8_i++)
		{
			for(u8_j=0;u8_j<((gu8_size-1)-u8_i);u8_j++)
			{
				for(u8_z=0;u8_z<9;u8_z++)
				{
					if(g_arr[u8_j].primaryAccountNumber[u8_z]>g_arr[u8_j+1].primaryAccountNumber[u8_z])
					{
						printf("%c\n",g_arr[u8_j].primaryAccountNumber[u8_z]);
						printf("%c\n",g_arr[u8_j+1].primaryAccountNumber[u8_z]);
						u8_temp=g_arr[u8_j];
						g_arr[u8_j]=g_arr[u8_j+1];
						g_arr[u8_j+1]=u8_temp;
						break;
					}
				else{}
				}
			}
		}
	}
	
	else{}
}

/*Implementation of the check server and return result*/
uint8_t Check_server(ST_accountBalance_t* g_arr,ST_terminalData_t data1,ST_cardData_t customer)
{
	uint8_t u8_i;
	uint8_t u8_j;
	for(u8_i=0;u8_i<(gu8_size-1);u8_i++)
	{
		if(customer.primaryAccountNumber[0]==g_arr[u8_i].primaryAccountNumber[0])
		{
			if(customer.primaryAccountNumber[8]==g_arr[u8_i].primaryAccountNumber[8])
			{
				if(data1.transAmount<=g_arr[u8_i].balance)
				{
					result=APPROVED;
					g_arr[u8_i].balance=g_arr[u8_i].balance-data1.transAmount;//assign the new value of balance
					break;
				}
				else{
						result=DECLINED;
					}
			}
			else{
					result=DECLINED;
				}
		}
		else{
				result=DECLINED;
			}
	}
	return result;
}

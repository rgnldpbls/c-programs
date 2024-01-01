#include<stdio.h>
#include<stdlib.h>

float deposit(double curbal);
float withdraw(double curbal);
float inquiry(double amount);

int main()
{
	int choice;
	double curbal=25000;
	char choices;
	
	do
	{
		x:
		system("cls");
		printf("<<<<< Welcome to Az Bank>>>>>\n");
		printf("What can I help you?\n");
	
		printf("[1]Deposit\n");
		printf("[2]Withdrawal\n");
		printf("[3]Inquiry\n");
		printf("[4]Exit\n");
		printf("\nYour choice:");
		scanf("%d",&choice);
	
			switch(choice)
			{	
			case 1:
				system("cls");
				curbal = deposit(curbal);
				a:
				printf("\nTry again?\n");
				printf("Type Y if yes.\nType N if no and back to main menu.\n");
				printf("\nYour choice:");
				scanf("%s",&choices);
				if(choices=='Y'||choices=='y'){
					curbal = deposit(curbal);
				}
				 if(choices=='N'||choices=='n'){
					goto x;
				}else 
					goto a;
				break;
			case 2:
				system("cls");
				curbal = withdraw(curbal);
				b:
				printf("\nTry again?\n");
				printf("Type Y if yes.\nType N if no and back to main menu.\n");
				printf("\nYour choice:");
				scanf("%s",&choices);
				if(choices=='Y'||choices=='y'){
					curbal = withdraw(curbal);
				}
				if(choices=='N'||choices=='n'){
					goto x;
				}else
					goto b;
				break;
			case 3:
				system("cls");
				curbal = inquiry(curbal);
				c:
				printf("\nTry again?\n");
				printf("Type Y if yes.\nType N if no and back to main menu.\n");
				printf("\nYour choice:");
				scanf("%s",&choices);
				if(choices=='Y'||choices=='y'){
					curbal = inquiry(curbal);
				}
				if(choices=='N'||choices=='n'){
					goto x;
				}else
					goto c;
			case 4:
				system("cls");
				d:
				printf("Are you sure you want to exit?\n");
				printf("Type Y if yes.\nType N if no and back to main menu.\n");
				printf("\nYour choice:");
				scanf("%s",&choices);
				if(choices=='Y'||choices=='y'){
					printf("Thank you for using the program.");
				exit(0);
				}
				if(choices=='N'||choices=='n'){
					goto x;
				}else
					goto d;
				break;
			}
		}while(choice==0||choice>4);
}
float deposit(double curbal)
{
	system("cls");
	double damount;
	printf("Please enter the amount you would like to deposit:Php ");
	scanf("%lf",&damount);
	curbal = curbal + damount;
	printf("Your balance is Php %.2f\n",curbal);
	return curbal;
}
float withdraw(double curbal)
{
	system("cls");
	double wamount;
	printf("Please enter the amount you would like to withdraw:Php ");
	scanf("%lf",&wamount);
	if(wamount>curbal)
	{	printf("Sorry you do not have enough balance.\n");
		printf("Please try again...\n");
	}else{
		curbal = curbal - wamount;
		printf("Your balance is Php %.2f\n",curbal);
	}
	return curbal;
}
float inquiry(double amount)
{
	system("cls");
	printf("Your current balance is %.2f\n",amount);
	return amount;
}


#include<stdio.h>
#include<stdlib.h>

struct bankAcc{
	int accNo;
	char name[80];
	double curbal;
};

void info(struct bankAcc user[5],int i);
void menu(struct bankAcc user[5],int i);
float deposit(struct bankAcc user[5],int i,double curbal);
float withdraw(struct bankAcc user[5],int i,double curbal);
float inquiry(struct bankAcc user[5],int i,double curbal);


int main(){
	struct bankAcc user[5];
	int i;
	
	for(i=0;i<5;i++){
		info(user,i);
		menu(user,i);
	}
	
	for(i=0;i<5;i++){
		printf("Client #%d\n",i+1);
		printf("Account Number: %d",user[i].accNo);
		printf("\nAccount Name: %s",user[i].name);
		printf("\nBalance Inquiry: %.2f",user[i].curbal);
		printf("\n\n\n");
	}
}

void info(struct bankAcc user[5],int i){
	printf("Please Enter your Account Number:");
	scanf("%d",&user[i].accNo);
	
	fflush(stdin);
	printf("Please Enter your Account Name: ");
	scanf("%[^\n]s",user[i].name);
	
	printf("\n\n");
}
void menu(struct bankAcc user[5],int i){
	int choice;
	user[i].curbal=2000;
	char choices;
	
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
				user[i].curbal = deposit(user,i,user[i].curbal);
				a:
				printf("\nTry again?\n");
				printf("Type Y if yes.\nType N if no and back to main menu.\n");
				printf("\nYour choice:");
				scanf("%s",&choices);
				if(choices=='Y'||choices=='y'){
					user[i].curbal = deposit(user,i,user[i].curbal);
				}
				 if(choices=='N'||choices=='n'){
					goto x;
				}else 
					goto a;
				break;
			case 2:
				system("cls");
				user[i].curbal = withdraw(user,i,user[i].curbal);
				b:
				printf("\nTry again?\n");
				printf("Type Y if yes.\nType N if no and back to main menu.\n");
				printf("\nYour choice:");
				scanf("%s",&choices);
				if(choices=='Y'||choices=='y'){
					user[i].curbal = withdraw(user,i,user[i].curbal);
				}
				if(choices=='N'||choices=='n'){
					goto x;
				}else
					goto b;
				break;
			case 3:
				system("cls");
				user[i].curbal = inquiry(user,i,user[i].curbal);
				c:
				printf("\nTry again?\n");
				printf("Type Y if yes.\nType N if no and back to main menu.\n");
				printf("\nYour choice:");
				scanf("%s",&choices);
				if(choices=='Y'||choices=='y'){
					user[i].curbal = inquiry(user,i,user[i].curbal);
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
					printf("Thank you for using the program.\n\n");
					system("cls");
					break;
					break;
				}
				if(choices=='N'||choices=='n'){
					goto x;
				}else
					goto d;
				break;
			default:
				goto x;
			}
}
float deposit(struct bankAcc user[5],int i,double curbal)
{
	system("cls");
	double damount;
	printf("Please enter the amount you would like to deposit:Php ");
	scanf("%lf",&damount);
	user[i].curbal = curbal + damount;
	printf("Your balance is Php %.2f\n",user[i].curbal);
	return user[i].curbal;
}
float withdraw(struct bankAcc user[5],int i,double curbal)
{
	system("cls");
	double wamount;
	printf("Please enter the amount you would like to withdraw:Php ");
	scanf("%lf",&wamount);
	if(wamount>curbal)
	{	printf("Sorry you do not have enough balance.\n");
		printf("Please try again...\n");
	}else{
		user[i].curbal = curbal - wamount;
		printf("Your balance is Php %.2f\n",user[i].curbal);
	}
	return user[i].curbal;
}
float inquiry(struct bankAcc user[5],int i,double curbal)
{
	system("cls");
	printf("Your current balance is %.2f\n",user[i].curbal);
	return user[i].curbal;
}

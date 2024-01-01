#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define TAB 9
#define BKSP 8
#define SPACE 32 

void Display_Welcome();
void Get_User_Pin(void);
void Add_New_Account();
void Edit_Account();
void View_Account();
void Delete_Account();
void menu();


///STRUCTURES///
struct UserData {
   int Acc_Number;
   char Name[80];
   int PIN;
   float Credit;
   float Debit;
   float Balance;
};

///TYPE DEFINITION OF THE STRUCTURE///
typedef struct UserData UserData;


/// Main PROGRAM ///
int main()
{
	Get_User_Pin();
	Display_Welcome();
		
}
/// THIS REGION IS FOR GETTING THE USER'S PIN CODE ///
/// IT IS A TYPE OF PIN MASKING ///
/// A BUNCH OF ASTERISK WILL SHOW UP INSTEAD OF THE ACTUAL PIN///
void Get_User_Pin(){

    int pin = 1234 ;
    char apin[4] , ch;
    int attempt ;
    int i;
    int pw = 0; 

    for(attempt=1; attempt<=3; attempt++) {
    system("color 9");
    getch();
    system("cls");
    getch();
	printf("\n\n\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");  /// This is the welcoming banner///
    printf("\n\n\t\t\t\t\t ENTER 4 DIGIT PIN CODE: ");
    for(i=0;i<4;i++)
    {
        ch = getch();
       
        if(ch == BKSP)   /// this is to check and position the index in case of backspacing ///
        {
            if(i>0){
                i--;
                printf("\b \b");
            }
        }
        else if(ch==TAB || ch == SPACE ){  /// this is to check and position the index in case of spacing ///
            continue;                                 
        }
        else{
        apin[i] = ch;
        ch = '*' ;			/// the PIN will be masked by a set of asterisk ///
        printf("%c",ch);
        }
    }
    apin[i] = ' ';
    printf("\n");
    pw = atoi(apin) ;
    //printf("%d\n",pw);//

    if(pw != pin){		/// In case of wrong PIN it will display INVALID ///
    	system("color 4");
        printf("\n\n\n\n\t\t\t\t\t\tINVALID PIN!\n");
        system("color 4");
        printf("\n\t\t\t\t\tYou have %d attempts remaining\n",3-attempt);

        if (attempt == 3) {
            exit(1);
        }
    }
    else{
    	system("color 2");	/// This will be displayed in correct PIN///
        printf("\n\t\t\t\t -You have entered the correct PIN code-\n");
        break;
    }
    }
}

/// THIS FUNCTION IS CONSISTS OF WELCOMING THE CLIENT AS WELL AS THE MAIN MENU///
void Display_Welcome(void) {
   char choice;
    getch();
    system("cls");
    system("color 9");
    Alpha:
    getch();
    system("cls");
    system("color 9");
    printf("\n\n\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\t\t\t\tPlease Select An Option");
	printf("\n\t\t\t\t\t[A] Add Account");
	printf("\n\t\t\t\t\t[E] Edit Account");
	printf("\n\t\t\t\t\t[V] View Account");
	printf("\n\t\t\t\t\t[D] Delete Account");
	printf("\n\t\t\t\t\t[X] Exit\n");
	printf("\n\t\t\t\t\tKindly enter your choice: ");
	scanf("%c",&choice);
	
	/// THIS IS THE SWITCH CASE FOR THE MAIN MENU///
	switch(choice){
	
		case 'A' : case 'a':				/// if you press 'a' or 'A', it will Add new account ///
			Add_New_Account();
			goto Alpha;
			break;
		case 'E': case 'e':                /// if you press 'e' or 'E', it will Edit an existing account account ///
			Edit_Account();
			goto Alpha;
			break;
		case 'V' : case 'v':			   /// if you press 'v' or 'V', it will View existing accounts ///
			View_Account();              
			goto Alpha;
			break;
		case 'D' : case 'd':               /// if you press 'd' or 'D', it will Delete account ///
			Delete_Account();
			goto Alpha;
			break;
		case 'X' : case 'x':               /// if you press 'd' or 'D', it will Delete account ///
			printf("Thank you for using the program!");           
			exit(1);
			goto Alpha;
			break;
		default:                           /// If non of the keys were pressed, it will be back at the top///
			goto Alpha;
			break;
		}
}
/// if you press 'a' or 'A', it will Add new account ///
void Add_New_Account()
{
	FILE *fp ;
	fp = fopen("bank.txt", "a");
	if(fp==NULL)
	{
		printf("Error in accessing the FILE");
 	}	
 	else
 	{
 		system("color 9");
    	printf("\n\n\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    	printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
 		UserData profile;
 		printf("\n\t\t\t\tWhat is your Account Number? ");
 		scanf("%d", &profile.Acc_Number);
 		printf("\t\t\t\tWhat is your name? ");
 		scanf("%s", profile.Name);
 		printf("\t\t\t\tWhat is your PIN? ");
 		scanf("%d", &profile.PIN);
 		printf("\t\t\t\tWhat is your credit amount? ");
 		scanf("%f", &profile.Credit);
 		profile.Debit = 0;
 		profile.Balance = 0;
 		fprintf(fp,"%d\t%d\t%.2f\t%.2f\t%.2f\t%s\n", profile.Acc_Number,profile.PIN,profile.Credit,profile.Debit,profile.Balance,profile.Name);
 		fflush(stdin);
 		fclose(fp);	
	}	
}
/// if you press 'e' or 'E', it will Edit an existing account account ///
void Edit_Account() {
	int Acc_num;
	int PIN;
	
	system("color 9");
	printf("\n\n\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO EDITING OF CLIENT'S ACCOUNT\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\n\t\t\t\t    What Account do you want to edit?\n");
	printf("\t\t\t\t   Please enter your Account Number: ");
	scanf("%d",&Acc_num);
	
	FILE *fp, *fpt;
	fp = fopen("bank.txt","r");
	fpt = fopen("account.txt","w+");
	if(fp == NULL) {
		printf("Error in accessing the FILE.");
		return;
	}
	else {
		int flag=0;
		int ch2;
		float dep, with;
		UserData profile;
		system("color 6");
		while(fscanf(fp,"%d %d %f %f %f %s",&profile.Acc_Number,&profile.PIN,&profile.Credit,&profile.Debit,&profile.Balance,profile.Name)!=EOF) {
			if(profile.Acc_Number == Acc_num){
				printf("\t\t\t\tPlease enter your PIN Number:");
				scanf("%d",&PIN);
				if(profile.PIN == PIN){
					invalid:
					printf("What do you want to do?\n");
					printf("1.Deposit\t2.Withdraw\n\n");
					printf("Please select your choice: ");
					scanf("%d",&ch2);
					if(ch2==1){
						dep:
						printf("How much you want to deposit: ");
						scanf("%f",&dep);
						if(dep <0)
						{
							printf("\t\t\t\t Please enter correct amount!");
							goto dep;
						}
						else{
							profile.Debit = dep;
							profile.Balance = profile.Credit + dep;
							fprintf(fpt,"%d\t%d\t%.2f\t%.2f\t%.2f\t%s\n",profile.Acc_Number,profile.PIN,profile.Credit,profile.Debit,profile.Balance,profile.Name);
							flag=1;
							fflush(stdin);
						}
					}else if(ch2==2){
						with:
						printf("How much you want to withdraw: ");
						scanf("%f",&with);
						if(profile.Credit<with){
							printf("\t\t\t\t Please enter correct amount!");
							goto with;
						}
						else{
							profile.Debit = with;
							profile.Balance = profile.Credit - with;
							fprintf(fpt,"%d\t%d\t%.2f\t%.2f\t%.2f\t%s\n",profile.Acc_Number,profile.PIN,profile.Credit,profile.Debit,profile.Balance,profile.Name);
							flag=1;
							fflush(stdin);
						}
					}else{
						goto invalid; 
					}
				}
				else {
					printf("Invalid pin. Please try again.");
					fprintf(fpt,"%d\t%d\t%.2f\t%.2f\t%.2f\t%s\n",profile.Acc_Number,profile.PIN,profile.Credit,profile.Debit,profile.Balance,profile.Name);
				}
			}
			else {
				fprintf(fpt,"%d\t%d\t%.2f\t%.2f\t%.2f\t%s\n",profile.Acc_Number,profile.PIN,profile.Credit,profile.Debit,profile.Balance,profile.Name);
			}
		}if(flag=0)
		{
			printf("\n\t\t\tNo record found!");
		}
		fclose(fp);
 		fclose(fpt);
 		remove("bank.txt");
 		rename("account.txt","bank.txt");
 		fflush(stdin);
	}
}
/// if you press 'd' or 'D', it will Delete account ///
void View_Account()
{
	FILE *fp;
	fp = fopen("bank.txt","r");
	if(fp==NULL)
	{
		printf("Error in accessing the FILE");
	}
	else
	{
		UserData profile;
		
		system("color 2");
    	printf("\n\n\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    	printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MANAGEMENT RECORDS \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf("\n\n\n\tAccount Number\t\tClient's Name\t\tPIN\t\tCredit\t\tDebit\t\tBalance");
		while(fscanf(fp,"%d %d %f %f %f %s",&profile.Acc_Number,&profile.PIN,&profile.Credit,&profile.Debit,&profile.Balance,profile.Name)!=EOF)
		{
			printf("\n\t\t%d\t\t%s\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f", profile.Acc_Number, profile.Name,profile.PIN,profile.Credit,profile.Debit,profile.Balance);
			fflush(stdin);
		}
	fflush(stdin);
 	fclose(fp);
 	
	}
}
/// if you press 'v' or 'V', it will View existing accounts ///
void Delete_Account()
{
	int Acc_num;
	int PIN;
	
	system("color 9");
    printf("\n\n\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO REMOVING OF CLIENT'S ACCOUNT\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\t\t\t\tWhat Account do you want to delete? Please enter your Account Number:");
	scanf("%d", &Acc_num);
	
	FILE *fp, *fpt;
	fp = fopen("bank.txt","r");
	fpt = fopen("account.txt","w+");
	if(fp==NULL)
 	{
		printf("Error in accessing the FILE");
	}
 	else
	{
	 	UserData profile;
	 	int flag = 0;
	 	while(fscanf(fp,"%d %d %f %f %f %s",&profile.Acc_Number,&profile.PIN,&profile.Credit,&profile.Debit,&profile.Balance,profile.Name)!=EOF)
		{
		    if(profile.Acc_Number == Acc_num){
		    	printf("\t\t\t\tPlease enter your PIN Number:");
				scanf("%d", &PIN);
		     	if(profile.PIN == PIN){
					printf("\n\t\t\tAccount is removed succesfully!");
				 	flag = 1;
				}
				else{
				 	fprintf(fpt,"%d\t%d\t%.2f\t%.2f\t%.2f\t%s\n",profile.Acc_Number,profile.PIN,profile.Credit,profile.Debit,profile.Balance,profile.Name);
				}
			}
			else{
			 		fprintf(fpt,"%d\t%d\t%.2f\t%.2f\t%.2f\t%s\n",profile.Acc_Number,profile.PIN,profile.Credit,profile.Debit,profile.Balance,profile.Name);
			 	}
		     
			}
			if(flag=0)
			{
				printf("\n\t\t\tNo record found!");
			}
			fflush(stdin);
 			fclose(fp);
 			fclose(fpt);
 			remove("bank.txt");
 			rename("account.txt","bank.txt");
 			fflush(stdin);		
	 	} 
}

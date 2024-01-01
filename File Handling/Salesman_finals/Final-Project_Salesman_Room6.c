#include<stdio.h>				//The header stands for Standard Input Output.
#include<stdlib.h>				//The header stands for the General Purpose Standard Library .
#include<string.h>				//The header used for manipulating arrays of characters.
#include<stdbool.h>				// The purpose of this header is to add booltype and true and false values as micro definitions.

struct sales{					// Structure in the program, //The entity is sales.
	char salesman_num[20];		// The four are what we called structure members.
	char salesman_name[30];
	double total_sales;
	float commission;
};

typedef struct sales user;		//This statement is used for assigning an alternative name.

void add_User();				//This function is used for adding an information of user.
void edit_User();				//This function is used for editing the information of the user.
void delete_User();				//This function is used for deleting the information of the user.
void view_User();				//This function is used for viewing the information of the users.
int checkNum (char salesmanNum[]);//This function is used to check the format
int lineOf(char *salesmanNum, int *line, int *col); //This function is used to check if the input is duplicate
int checkSale (char sale[]);  	//This function is used to check the input in sales


int main(){						//This main function serves as a Main Menu and calling the other functions.
	system("COLOR 70");			//change the foreground color to white.
	char sel;					//storing selected menu choice of user.
	char try_again;				//storing choice of user on line 75.
	char username[80];
	bool showMenu = true;
	bool x_try_again = true;

    printf("\n\t\t\t\t          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t\t\t\t          |      S  A  L  E  S  M  A  N\t     |\n");
	printf("\t\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t\t      |\t        ABOUT THE PROGRAM:          \t|\n");
	printf("\t\t\t\t      |\t  This is the program where you can \t|\n");
	printf("\t\t\t\t      |\t  Add, Edit, Delete, and View       \t|\n");
	printf("\t\t\t\t      |\t  Salesman Records. The records     \t|\n");
	printf("\t\t\t\t      |\t  are stored in a salesman.txt file.\t|\n");
	printf("\t\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t    __________________________________________________________");
	printf("\n\n\t\t\t\t      ------------------------------------------");
	printf("\n\t\t\t\t     |     Please enter your name below...     |\n");
	printf("\t\t\t\t      ------------------------------------------   ");
	printf("\n\t\t\t\t\t>> ");
	scanf(" %[^\n]%*c",username);
	
	system("cls");
	printf("\n\t\t\t                           Welcome, %s!",username);
	printf("\n\t\t\t                     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t\t\t                     |     I N S T R U C T I O N S    |\n");
	printf("\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t      |\t   1. Enter a menu choice (Please capitalize the letter)         |\n");
	printf("\t\t\t      |\t                                                                 |\n");
	printf("\t\t\t      |\t   2. Salesman Number should have a format of XX-YYYYY-X         |\n");
	printf("\t\t\t      |\t      where X is a letter from A-Z while Y is a digit from 0-9   |\n");
	printf("\t\t\t      |\t                                                                 |\n");
	printf("\t\t\t      |\t   3. Salesman Name can be composed only of letters,             |\n");
	printf("\t\t\t      |\t      spaces, and period                                         |\n");
	printf("\t\t\t      |\t                                                                 |\n");
	printf("\t\t\t      |\t   4. Salesman Sales should only be                              |\n");
	printf("\t\t\t      |\t      a whole number or a decimal number                         |\n");
	printf("\t\t\t      |\t                                                                 |\n");	
	printf("\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t            __________________________________________________________");
	printf("\n\n\t\t\t\t          ------------------------------------------");
	printf("\n\t\t\t\t          |        Press any key to continue...    |\n");
	printf("\t\t\t\t          ------------------------------------------   ");
	
	getch();
	
	system("cls");
	
	do {
		system("COLOR 0A"); //change the foreground color to light green and background color to black
		printf("\n\t\t\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n\t\t\t\t\t      |      M A I N  M E N U\t   |\n");
		printf("\t\t\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\t\t\t\t\t      |\t\t  [A]dd\t\t   |\n");
		printf("\t\t\t\t\t      |\t\t  [E]dit\t   |\n");
		printf("\t\t\t\t\t      |\t\t  [D]elete\t   |\n");
		printf("\t\t\t\t\t      |\t\t  [V]iew\t   |\n");
		printf("\t\t\t\t\t      |\t\t  E[X]it\t   |\n");
		printf("\t\t\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\t\t\t\t__________________________________________________________");
		printf("\n\n\t\t\t\t\t------------------------------------------");
		printf("\n\t\t\t\t\t| Note: You should input capital letters |\n");
		printf("\t\t\t\t\t------------------------------------------");
		printf("\n\t\t\t\t\t\t      Please Select: ");
		scanf("%s",&sel);
			
		switch(toupper(sel)){		//Switch Case statements is used for the selection process. //toupper is used for the lowercase input will convert into an uppercase.
			case 'A':				//Case A is for Add.
				system("cls");
				system("COLOR 0E"); //change the foreground color to light yellow and background color to black
				add_User();
				system("cls");
				break;
				
			case 'E':				//Case E is for Edit.
				system("cls");
				system("COLOR 03"); //change the foreground color to light aqua and background color to black
				edit_User();
				system("cls");
				break;
				
			case 'D':				//Case D is for Delete.
				system("cls");
				system("COLOR 0C"); //change the foreground color to light red and background color to black
				delete_User();
				system("cls");
				break;
				
			case 'V':				//Case V is for View.
				system("cls");
				system("COLOR 0F"); //change the foreground color to bright white and background color to black
				view_User();
				system("cls");
				break;
				
			case 'X':				//Case X is for Exit.
				system("cls");
				system("COLOR 0A"); //change the foreground color to light green and background color to black
				do {
					printf("\n\t\t\t\t\t          ===========================");
            		printf("\n\t\t\t\t\t\t  |         E X I T         |\n");
           			printf("\t\t\t\t\t          ===========================");
           			printf("\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            		printf("\n\n\n\t\t\t\t             Are you sure you want to exit?[Y/N]: ");
					scanf("%s",&try_again);
					
					switch(toupper(try_again)) {
						case 'Y':
							x_try_again=false;
							showMenu=false;
							printf("\n\n\n\t\t\t\t\t   ------------------------------------------");
							printf("\n\t\t\t\t\t   |    Thank you for using the program!    |");
                			printf("\n\t\t\t\t\t   ------------------------------------------");
							getch();
						break;
						case 'N':
							x_try_again=false;
							system("cls");
						break;
						default:
							printf("\n\n\t\t\t\t\t *********************************************");
							printf("\n\t\t\t\t\t *     Invalid input...Please Try Again!     *");
							printf("\n\t\t\t\t\t *********************************************");
							getch();
							system("cls");				
					}
				} while(x_try_again);
				system("cls");
				
				break;
			default:
				system("cls");
				printf("\n\n\t\t\t\t\t *********************************************");
				printf("\n\t\t\t\t\t *     Invalid input...Please Try Again!     *");
				printf("\n\t\t\t\t\t *********************************************");
				getch();
				system("cls");
		}
	} while(showMenu);
	
	return 0;
}

void add_User(){						//This function is used for adding an information of user.
	FILE *fp;							//Initializing file pointer.
	fp = fopen("salesman.txt","a");		//Opening a file.
	if(fp == NULL){						//It is conditional statement if the file is null.
		printf("\n\n\t\t\t\t-------------------------------------------------------------");
        printf("\n\t\t\t\t|  There's a detected error in the file. Please try again!  |");
        printf("\n\t\t\t\t-------------------------------------------------------------");
		return;
	}
	else{
		user i;				//Structure
		int count=0;
		double fqs, sqs, tqs, lqs, ts;
		char temp[100];
		
		fflush(stdin);		
		do {				//This loop is for checking the salesman number, if its format is correct and if its duplicate.
             	printf("\n\t\t\t\t\t        ============================");
				printf("\n\t\t\t\t\t\t|   A D D  R E C O R D S   |\n");
				printf("\t\t\t\t\t        ============================");
				printf("\n\t\t\t\t   ____________________________________________________");
				printf("\n\n\n\t\t\t\t\t        Salesman Number: ");
				scanf("%s",i.salesman_num);

            if(checkNum(i.salesman_num)==-2) {
                printf("\n\n\t\t    ------------------------------------------------------------------------------");
                printf("\n\t\t    |                         The format should be XX-YYYYY-X                    |");
                printf("\n\t\t    |   NOTE: X represents letters from A-Z while Y represents digits from 0-9   |");
                printf("\n\t\t    ------------------------------------------------------------------------------");
                printf("\nPress any key to try again...");
                getch();
                system("cls");
            }
            else if(checkNum(i.salesman_num)!=-1) {
                printf("\n\n\t\t\t    ------------------------------------------------------------------------");
                printf("\n\t\t\t    |                   %s exists on the record                    |",i.salesman_num);
                printf("\n\t\t\t    |   Please input a new unique salesman number with the right format.   |");
                printf("\n\t\t\t    ------------------------------------------------------------------------");
                printf("\n\t\t\t\t\t\tPress any key to try again...");
                getch();
                system("cls");
            }
            else
                count+=1;
		} while (count==0);
		
		printf("\n\n\t\t\t\t\t        Salesman Name: ");
        scanf(" %[^\n]%*c",i.salesman_name);
        printf("\n\t\t\t\t   ____________________________________________________");
            
		do {
			printf("\n\n\t\t\t\tNote: Don't input any character except for one period to be used in decimal.");
			printf("\n\n\t\t\t\t\t       First Quarter Sales:\t");
		    scanf(" %[^\n]%*c",temp);
		} while(checkSale(temp)==0);
		fqs=atof(temp);

		do {
		    printf("\n\t\t\t\t\t       Second Quarter Sales:\t");
		    scanf(" %[^\n]%*c",temp);
		} while(checkSale(temp)==0);
		sqs=atof(temp);

		do {
		    printf("\n\t\t\t\t\t       Third Quarter Sales:\t");
		    scanf(" %[^\n]%*c",temp);
		} while(checkSale(temp)==0);
		tqs=atof(temp);

		do {
		    printf("\n\t\t\t\t\t       Fourth Quarter Sales: \t");
		    scanf(" %[^\n]%*c",temp);
		} while(checkSale(temp)==0);
		lqs=atof(temp);

		
		ts = fqs + sqs + tqs + lqs;
		i.total_sales = ts;
		
		if(ts<=5000){
			i.commission = ts*10/100;
			//fprintf is used for storing the information into a txt file.
			fprintf(fp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
		}
		else if(ts<=10000){
			i.commission = ts*15/100;
			fprintf(fp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
		}
		else if(ts<=15000){
			i.commission = ts*20/100;
			fprintf(fp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
		}
		else if(ts<=20000){
			i.commission = ts*25/100;
			fprintf(fp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
		}
		else if(ts<=25000){
			i.commission = ts*30/100;
			fprintf(fp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
		}
		else if(ts>25000){
            i.commission = ts*50/100;
            if(i.commission>30000)
                fprintf(fp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
            else
                fprintf(fp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, 30000.00);
		}
		fflush(stdin);
		fclose(fp);			//Closing a file.
		printf("\n\n\n\t\t\t\t\t   -------------------------------------");
        printf("\n\t\t\t\t\t   |    Salesman added successfully!    |");
        printf("\n\t\t\t\t\t   -------------------------------------");
        printf("\n\n\t\t\t\t\t\tPress any key to continue.....");
		getch();
	}
}

void edit_User(){			//This function is used for editing the information of the user
	char sales_num[10];
	int count=0;
	user i;					//Structure
	
	do {					//This loop is for checking the salesman number, if its format is correct and if its duplicate.
        printf("\n\t\t\t\t\t          ===========================");
        printf("\n\t\t\t\t\t\t  |         E D I T         |\n");
        printf("\t\t\t\t\t          ===========================");
        printf("\n\n\t\t\t\t\t\t  Salesman Number: ");
        scanf(" %[^\n]%*c",sales_num);


        if(checkNum(sales_num)==-2) {
            printf("\n\n\t\t    ------------------------------------------------------------------------------");
            printf("\n\t\t    |                         The format should be XX-YYYYY-X                    |");
            printf("\n\t\t    |   NOTE: X represents letters from A-Z while Y represents digits from 0-9   |");
            printf("\n\t\t    ------------------------------------------------------------------------------");
            printf("\nPress any key to try again...");
            getch();
            system("cls");
        }
        else if(checkNum(sales_num)==-1) {
            printf("\n\n\t\t\t\t\t     -------------------------------------");
        	printf("\n\t\t\t\t\t     |          No record found!         |");
       		printf("\n\t\t\t\t\t     -------------------------------------");
            printf("\nPress any key to go back to main menu...");
            getch();
            system("cls");
            return;
        }
        else
            count+=1;
	} while (count==0);
	
	FILE *fp, *temp;					//Initializing file pointer.
	fp = fopen("salesman.txt","r");		//Opening a file.
	temp = fopen("temp.txt","w+");
	
	if(fp==NULL){						//It is conditional statement if the file is null.
		printf("\n\n\t\t\t\t-------------------------------------------------------------");
        printf("\n\t\t\t\t|  There's a detected error in the file. Please try again!  |");
        printf("\n\t\t\t\t-------------------------------------------------------------");
		return;
	}
	else{
		double fqs, sqs, tqs, lqs, ts;
		char tempNum[100],tempNum2[100];
		
		//fscanf is used for reading the data from the file.
		while(fscanf(fp,"%s\t%[^\t]\t%[^\t]\t%[^\n]",i.salesman_num,i.salesman_name,tempNum, tempNum2)!=EOF){
			i.total_sales=atof(tempNum);
			i.commission=atof(tempNum2);
			if(strcmp(i.salesman_num,sales_num)==0){		//it is a conditional statement that test if the input sales_num is same as the stored salesman_num.
			printf("\n\t\t\t\t***************************************************************");
                printf("\n\n\t\t\t\t    -------------------------------------------------------");
                printf("\n\t\t\t\t    |   Salesman Name   |   Total Sales   |   Comission   |");
                printf("\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\t\t\t\t    |   %-15s |   %-10.2lf    |   %-10.2f  |",i.salesman_name,i.total_sales,i.commission);
                printf("\n\t\t\t\t    -------------------------------------------------------");
                printf("\n\n\t\t\t\t***************************************************************");
				printf("\n\n\t\t\t\t\t\t  Input new contents of salesman:");
				
				do {
					printf("\n\n\t\t\t\tNote: Don't input any character except for one period to be used in decimal.");
				    printf("\n\n\t\t\t\t\t          First Quarter Sales:\t");
				    scanf(" %[^\n]%*c",tempNum);
				} while(checkSale(tempNum)==0);
				fqs=atof(tempNum);
		
				do {
				    printf("\n\t\t\t\t\t          Second Quarter Sales:\t");
				    scanf(" %[^\n]%*c",tempNum);
				} while(checkSale(tempNum)==0);
				sqs=atof(tempNum);
		
				do {
				    printf("\n\t\t\t\t\t          Third Quarter Sales:\t");
				    scanf(" %[^\n]%*c",tempNum);
				} while(checkSale(tempNum)==0);
				tqs=atof(tempNum);
		
				do {
				    printf("\n\t\t\t\t\t          Fourth Quarter Sales:\t");
				    scanf(" %[^\n]%*c",tempNum);
				} while(checkSale(tempNum)==0);
				lqs=atof(tempNum);
		
				
				ts = fqs + sqs + tqs + lqs;
				i.total_sales = ts;
			
				if(ts<=5000){
					i.commission = ts*10/100;
					//fprintf is used for storing the information into a txt file.
					fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
				}
				else if(ts<=10000){
					i.commission = ts*15/100;
					fprintf(temp,"%s\t%s\t%2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
				}
				else if(ts<=15000){
					i.commission = ts*20/100;
					fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
				}
				else if(ts<=20000){
					i.commission = ts*25/100;
					fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
				}
				else if(ts<=25000){
					i.commission = ts*30/100;
					fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
				}
				else if(ts>25000){
		            i.commission = ts*50/100;
		            if(i.commission>30000)
		                fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
		            else
		                fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, 30000.00);
				}
				printf("\n\n\t\t\t\t\t  -----------------------------------------------");
                printf("\n\t\t\t\t\t  |    The account is updated successfully!.    |");
                printf("\n\t\t\t\t\t  -----------------------------------------------");
				fflush(stdin);
				i.total_sales=0.00;
				i.commission=0.00;
				
			} else{
				fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
				fflush(stdin);
				i.total_sales=0.00;
				i.commission=0.00;
			}
		}
		
		fclose(fp);								//Closing the file.
		fclose(temp);
		
		remove("salesman.txt");					//Removing the file.
		rename("temp.txt","salesman.txt");		//Renaming the file
		
		printf("\n\n\t\t\t\t\t\tPress any key to continue.....");
		getch();
	}
}

void delete_User(){				//This function is used for deleting the information of the user.
	char sales_num[10];
	int count=0;
	user i;						//Structure
	
	do {						//This loop is for checking the salesman number, if its format is correct and if its duplicate.
        printf("\n\t\t\t\t\t          ===========================");
        printf("\n\t\t\t\t\t\t  |       R E M O V E       |\n");
        printf("\t\t\t\t\t          ===========================");
        printf("\n\n\t\t\t\t\t\t  Salesman Number: ");
        scanf(" %[^\n]%*c",sales_num);
        printf("\n\t\t\t\t***************************************************************");


        if(checkNum(sales_num)==-2) {
            printf("\n\n\t\t    ------------------------------------------------------------------------------");
          	printf("\n\t\t    |                         The format should be XX-YYYYY-X                    |");
            printf("\n\t\t    |   NOTE: X represents letters from A-Z while Y represents digits from 0-9   |");
            printf("\n\t\t    ------------------------------------------------------------------------------");
            printf("\nPress any key to try again...");
            getch();
            system("cls");
        }
        else if(checkNum(sales_num)==-1) {
            printf("\n\n\t\t\t\t\t     -------------------------------------");
        	printf("\n\t\t\t\t\t     |          No record found!         |");
       		printf("\n\t\t\t\t\t     -------------------------------------");
            printf("\nPress any key to go back to main menu...");
            getch();
            system("cls");
            return;
        }
        else
            count+=1;
	} while (count==0);
	
	FILE *fp, *temp;						//Initializing file pointer
	fp = fopen("salesman.txt","r");			//Opening a file
	temp = fopen("temp.txt","w+");
	if(fp==NULL){							//It is conditional statement if the file is null.
		printf("\n\n\t\t\t\t-------------------------------------------------------------");
        printf("\n\t\t\t\t|  There's a detected error in the file. Please try again!  |");
        printf("\n\t\t\t\t-------------------------------------------------------------");
		return;
	}
	else{
		char choice[5];
		char ans_yes[5]="yes";
		char ans_no[5]="no";
		char tempNum[100],tempNum2[100];
		bool ask_again = true;
		//fscanf is used for reading the data from the file
		while(fscanf(fp,"%s\t%[^\t]\t%[^\t]\t%[^\n]",i.salesman_num,i.salesman_name,tempNum, tempNum2)!=EOF){
				i.total_sales=atof(tempNum);
				i.commission=atof(tempNum2);
				if(strcmp(i.salesman_num,sales_num)==0){ //it is a conditional statement that test if the input sales_num is same as the stored salesman_num.
				printf("\n\n\t\t\t\t    -------------------------------------------------------");
                printf("\n\t\t\t\t    |   Salesman Name   |   Total Sales   |   Commission  |");
                printf("\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\t\t\t\t    |   %-15s |   %-10.2lf    |   %-10.2f  |",i.salesman_name,i.total_sales,i.commission);
                printf("\n\t\t\t\t    -------------------------------------------------------");
                printf("\n\n\t\t\t\t***************************************************************");
					
					do {
						printf("\n\n\t\t\t\t\t\tDo you want to delete[yes/no]? ");
						scanf(" %[^\n]%*c",&choice);
						
						if(strcmp(ans_yes,choice)==0){
							printf("\n\t\t\t\t\t-----------------------------------------------");
             			 	printf("\n\t\t\t\t\t|    The account is removed successfully!.    |");
              				printf("\n\t\t\t\t\t-----------------------------------------------");
							fflush(stdin);
							i.total_sales=0.00;
							i.commission=0.00;
							ask_again=false;
							break;
						}else if(strcmp(ans_no,choice)==0){
							fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
							fflush(stdin);
							i.total_sales=0.00;
							i.commission=0.00;
							ask_again=false;
							break;
						}else{
							printf("\n\n\t\t\t\t\t *********************************************");
							printf("\n\t\t\t\t\t *               Invalid input               *");
							printf("\n\t\t\t\t\t *********************************************");
							choice[0]='I';
						}
						
					} while(ask_again);
					
				}
				else{
					fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
					fflush(stdin);
					i.total_sales=0.00;
					i.commission=0.00;
				}
			}
		fclose(fp);								//Closing the file
		fclose(temp);
		remove("salesman.txt");					//Removing a file
		rename("temp.txt","salesman.txt");		//Renaming a file
		fflush(stdin);
		printf("\n\n\t\t\t\t\t\tPress any key to continue.....");
		getch();
	}
}

void view_User(){
	FILE *fp;									//Initializing file pointer
	char printSales[100];
	fp = fopen("salesman.txt","r");				//Opening the file
	if(fp==NULL){								//It is conditional statement if the file is null.
		printf("\n\n\t\t\t\t-------------------------------------------------------------");
        printf("\n\t\t\t\t|  There's a detected error in the file. Please try again!  |");
        printf("\n\t\t\t\t-------------------------------------------------------------");
		return;
	}
	else{
		printf("\n\n\t\t\t\t  ----------------------------------------------------------------------------");
        printf("\n\t\t\t\t\t    Salesman\tSalesman\tTotal Sales\tCommission");
        printf("\n\t\t\t\t\t     Number\t Name");
        printf("\n\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        while(fgets(printSales,100,fp)) 	//printing the text file
			printf("\n\t\t\t\t\t   %s",printSales);
		printf("\n\t\t\t\t  -------------------------------------------------------------------------");
        printf("\n\n\t\t\t\t************************************************************************************");
		
		fclose(fp);
		printf("\n\n\t\t\t\t\t\t\tPress any key to continue.....");
		getch();
	}
	fclose(fp);
}

//returns -2 if the salesman number is not in the right format
//returns the line of the salesman number if it is in the right format
int checkNum (char salesmanNum[]) {
    int i, line, col;

	if(salesmanNum[0]>='A' && salesmanNum[0]<='Z'
	&& salesmanNum[1]>='A' && salesmanNum[1]<='Z'    			//checks if the char part (alphabet)
	&& salesmanNum[9]>='A' && salesmanNum[9]<='Z') { 			//of the salesman number is correct
		
		for(i=3; i<=7; i++){ 				//loops through the char of salesman number that should have a digit
    		if(!isdigit(salesmanNum[i]))
    			return -2; 					//the digit part of the salesman number is incorrect
    	}
    	
		if(salesmanNum[2]!='-' && salesmanNum[8]!='-') 
			return -2; 						//returns -2 if the char (-) part of the salesman  number is incorrect
		
		lineOf(salesmanNum,&line,&col); 	//if the format is correct, lineof function will be called
		return line; 
	}
	return -2; 								//the char (alphabet) part of the salesman number is incorrect
	
}

//returns the line and column where the salesman number is located
//returns -1 if the salesman number does not exist
int lineOf(char *salesmanNum, int *line, int *col) {
    FILE *fp;
    fp = fopen("salesman.txt","r");
    char str[100];
    char *pos;

    *line = -1;
    *col = -1;

    while((fgets(str,100,fp))!=NULL) { 		//continue reading until the end line
        *line+=1;
        pos = strstr(str,salesmanNum);

        if(pos!=NULL) { 					//word is found
            *col = (pos-str); 				//memory location of pos minus memory location ng str
            break;
        }
    }
    if(*col==-1)
        *line=-1;
        
    fclose(fp);
    return *col;
}

//returns 1 for valid sale input and 0 if invalid
int checkSale (char sale[]) {
	int i;
	if(!isdigit(sale[0]) || sale[0]=='0')
		return 0;
    else if(isdigit(sale))
        return 1;
    else {
        int countDec=0;
        for(i=0; i<strlen(sale); i++){
            if(isdigit(sale[i])) 					//checks if the char is a digit
                continue;
            else if(sale[i]==46 && countDec==0) 	//46 is the ASCII code of the decimal point
                countDec+=1; 						//increment the countDec if a decimal point is encountered
            else
                return 0; 							//returns 0 when the char is not a digit or not a decimal
        }
        return 1; 									//returns 1 if the program got out of the for loop
    }             									//because this means the inputs are digit and there is only 1 decimal
}

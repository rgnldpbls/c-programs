#include<stdio.h> //The header stands for Standard Input Output
#include<stdlib.h> //The header stands for the General Purpose Standard Library 
#include<string.h> // The header used for manipulating arrays of characters
#include<stdbool.h> // The purpose of this header is to add booltype and true and false values as micro definitions

struct sales{				// Structure in the program, //The entity is sales
	char salesman_num[20];  // The four are what we called structure members.
	char salesman_name[30];    
	double total_sales;
	float commission;
};

typedef struct sales user; //This statement is used for assigning an alternative name.

void add_User();  //This function is used for adding an information of user.
void edit_User(); //This function is used for editing the information of the user
void delete_User(); //This function is used for deleting the information of the user.
void view_User(); //This function is used for viewing the information of the users.

int main(){ 	//This main function serves as a Main Menu and calling the other functions.
	char sel;
	char try_again;
	bool showMenu = true;
	bool x_try_again = true;
	
	do {
		printf("Main Menu\n");
		printf("[A]dding Salesman\n");
		printf("[E]diting Salesman\n");
		printf("[D]eleting Salesman\n");
		printf("[V]iewing Salesmen\n");
		printf("E[X]it Program\n");
		printf("\n\nNote: You should input capital letters\n");
		printf("Please Select: ");
		scanf(" %s",&sel);
		
		switch(toupper(sel)){ //Switch Case statements is used for the selection process. //toupper is used for the lowercase input will convert into an uppercase.
			case 'A': //Case A is for Add.
				system("cls");
				add_User();
				getch();
				system("cls");
				break;
				
			case 'E': //Case E is for Edit.
				system("cls");
				edit_User();
				getch();
				system("cls");
				break;
				
			case 'D': //Case D is for Delete.
				system("cls");
				delete_User();
				getch();
				system("cls");
				break;
				
			case 'V': //Case V is for View
				system("cls");
				view_User();
				getch();
				system("cls");
				break;
				
			case 'X': //Case X is for Exit.
				system("cls");
				do {
					printf("Are you sure you want to exit?[Y/N]: ");
					scanf("%s",&try_again);
					
					switch(toupper(try_again)) {
						case 'Y':
							x_try_again=false;
							showMenu=false;
							printf("\n\n\nThank you for using the program!");
							getch();
						break;
						case 'N':
							x_try_again=false;
							system("cls");
						break;
						default:
							printf("Invalid input...");
							printf("Please Try Again!");
							getch();
							system("cls");				
					}
				} while(x_try_again);
				system("cls");
				
				break;
			default:
				system("cls");
				printf("Invalid input...");
				printf("Please Try Again!");
				getch();
				system("cls");
				break;
		}
	} while(showMenu);
	
	return 0;
}

void add_User(){ //This function is used for adding an information of user.
	FILE *fp; //Initializing file pointer
	fp = fopen("salesman.txt","a"); //Opening the file
	if(fp == NULL){ 	//It is conditional statement if the file is null.
		printf("There's a detected error in the file");
		printf("\nPlease check the salesman.txt file in your computer before trying again.");
		return;
	}
	else{
		user i; //Structure
		int count=0;
		double fqs, sqs, tqs, lqs, ts;
		char temp[100];
		
		fflush(stdin);
		do { //This loop is for checking the salesman number, if its format is correct and if its duplicate.
            printf("\n\nSalesman Number: ");
            scanf(" %[^\n]%*c",i.salesman_num);

            if(checkNum(i.salesman_num)==-2) {
                printf("\n\nThe format should be XX-YYYYY-X");
                printf("\nNOTE: X represents letters from A-Z while Y represents digits from 0-9");
                printf("\nPress any key to try again...");
                getch();
            }
            else if(checkNum(i.salesman_num)!=-1) {
                printf("\n\nThere is a duplicate salesman number.");
                printf("\nPress any key to try again...");
                getch();
            }
            else
                count+=1;
		} while (count==0);
		
		printf("\n\nSalesman Name: ");
        scanf(" %[^\n]%*c",i.salesman_name);
            
		do {
		    printf("\n\nFirst Quarter Sales: ");
		    scanf(" %[^\n]%*c",temp);
		} while(checkSale(temp)==0);
		fqs=atof(temp);

		do {
		    printf("\n\nSecond Quarter Sales: ");
		    scanf(" %[^\n]%*c",temp);
		} while(checkSale(temp)==0);
		sqs=atof(temp);

		do {
		    printf("\n\nThird Quarter Sales: ");
		    scanf(" %[^\n]%*c",temp);
		} while(checkSale(temp)==0);
		tqs=atof(temp);

		do {
		    printf("\n\nFourth Quarter Sales: ");
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
		fclose(fp);  //Closing a file.
		printf("\n\n\n");
		printf("Salesman added successfully\n");
	}
}

void edit_User(){ //This function is used for editing the information of the user
	char sales_num[10];
	int count=0;
	user i; //Structure
	
	do { //This loop is for checking the salesman number, if its format is correct and if its duplicate.
        printf("\n\nSalesman Number: ");
        scanf(" %[^\n]%*c",sales_num);

        if(checkNum(sales_num)==-2) {
            printf("\n\nThe format should be XX-YYYYY-X");
            printf("\nNOTE: X represents letters from A-Z while Y represents digits from 0-9");
            printf("\nPress any key to try again...");
            getch();
        }
        else if(checkNum(sales_num)==-1) {
            printf("\n\nNo record found!");
            printf("\nPress any key to go back to main menu...");
            getch();
            return;
        }
        else
            count+=1;
	} while (count==0);
	
	FILE *fp, *temp; //Initializing file pointer
	fp = fopen("salesman.txt","r"); //Opening a file
	temp = fopen("temp.txt","w+"); 
	
	if(fp==NULL){ //It is conditional statement if the file is null.
		printf("There's a detected error in the file");
		printf("\nPlease check the salesman.txt file in your computer before trying again.");
		return;
	}
	else{
		double fqs, sqs, tqs, lqs, ts;
		char tempNum[100],tempNum2[100];
		//fscanf is used for reading the data from the file
		while(fscanf(fp,"%s\t%[^\t]\t%[^\t]\t%[^\n]",i.salesman_num,i.salesman_name,tempNum, tempNum2)!=EOF){
			i.total_sales=atof(tempNum);
			i.commission=atof(tempNum2);
			if(strcmp(i.salesman_num,sales_num)==0){ //it is a conditional statement that test if the input sales_num is same as the stored salesman_num.
				
				printf("\nSalesman Name: %s",i.salesman_name);
				printf("\nTotal Sales: %.2lf",i.total_sales);
				printf("\nCommission: %.2f",i.commission);
				
				printf("\n\nInput new contents of salesman:");
				
				do {
				    printf("\n\nFirst Quarter Sales: ");
				    scanf(" %[^\n]%*c",tempNum);
				} while(checkSale(tempNum)==0);
				fqs=atof(tempNum);
		
				do {
				    printf("\n\nSecond Quarter Sales: ");
				    scanf(" %[^\n]%*c",tempNum);
				} while(checkSale(tempNum)==0);
				sqs=atof(tempNum);
		
				do {
				    printf("\n\nThird Quarter Sales: ");
				    scanf(" %[^\n]%*c",tempNum);
				} while(checkSale(tempNum)==0);
				tqs=atof(tempNum);
		
				do {
				    printf("\n\nFourth Quarter Sales: ");
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
				printf("\n\nThe account is updated successfully!.");
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
		
		fclose(fp); //Closing the file
		fclose(temp);
		
		remove("salesman.txt"); //Removing the file
		rename("temp.txt","salesman.txt"); //Renaming the file
		
		printf("\n\nPress any key to continue.....\n");
	}
}

void delete_User(){ //This function is used for deleting the information of the user.
	char sales_num[10];
	int count=0;
	user i; //Structure
	
	do { //This loop is for checking the salesman number, if its format is correct and if its duplicate.
        printf("\n\nSalesman Number: ");
        scanf(" %[^\n]%*c",sales_num);

        if(checkNum(sales_num)==-2) {
            printf("\n\nThe format should be XX-YYYYY-X");
            printf("\nNOTE: X represents letters from A-Z while Y represents digits from 0-9");
            printf("\nPress any key to try again...");
            getch();
        }
        else if(checkNum(sales_num)==-1) {
            printf("\n\nNo record found!");
            printf("\nPress any key to go back to main menu...");
            getch();
            return;
        }
        else
            count+=1;
	} while (count==0);
	
	FILE *fp, *temp; //Initializing file pointer
	fp = fopen("salesman.txt","r"); //Opening a file
	temp = fopen("temp.txt","w+");
	if(fp==NULL){ //It is conditional statement if the file is null.
		printf("There's a detected error in the file");
		printf("\nPlease check the salesman.txt file in your computer before trying again.");
		return;
	}
	else{
		char choice[5];
		char ans_yes[5]="yes";
		char ans_no[5]="no";
		char tempNum[100],tempNum2[100];
		//fscanf is used for reading the data from the file
		while(fscanf(fp,"%s\t%[^\t]\t%[^\t]\t%[^\n]",i.salesman_num,i.salesman_name,tempNum, tempNum2)!=EOF){
				i.total_sales=atof(tempNum);
				i.commission=atof(tempNum2);
				if(strcmp(i.salesman_num,sales_num)==0){ //it is a conditional statement that test if the input sales_num is same as the stored salesman_num.
					printf("\nSalesman Name: %s",i.salesman_name);
					printf("\nTotal Sales: %.2lf",i.total_sales);
					printf("\nCommission: %.2f",i.commission);
					
					do {
						printf("\n\nDo you want to delete[yes/no]? ");
						scanf(" %[^\n]%*c",&choice);
						
						if(strcmp(ans_yes,choice)==0){
							printf("\n\nThe account is removed successfully!.");
							fflush(stdin);
							i.total_sales=0.00;
							i.commission=0.00;
							break;
						}else if(strcmp(ans_no,choice)==0){
							//fprintf is used for storing the information into a txt file.
							fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
							fflush(stdin);
							i.total_sales=0.00;
							i.commission=0.00;
							break;
						}else{
							printf("Invalid Input!");
							choice[0]='I';
						}
						
					} while(choice[0]=='I');
					
				}
				else{
					fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
					fflush(stdin);
					i.total_sales=0.00;
					i.commission=0.00;
				}
			}
		fclose(fp); //Closing the file
		fclose(temp);
		remove("salesman.txt"); //Removing a file
		rename("temp.txt","salesman.txt"); //Renaming a file
		fflush(stdin);
		printf("\n\nPress any key to continue.....\n");
	}
}

void view_User(){
	FILE *fp; //Initializing file pointer
	char printSales[100];
	fp = fopen("salesman.txt","r"); //Opening the file
	if(fp==NULL){ //It is conditional statement if the file is null.
		printf("There's a detected error in the file");
		printf("\nPlease check the salesman.txt file in your computer before trying again.");
		return;
	}
	else{
		printf("Salesman Number\tSalesman Name\tTotal Sales\tCommission\n");
        while(fgets(printSales,100,fp)) //printing the text file
            printf("%s",printSales);
		fclose(fp);
		printf("\n\nPress any key to continue.....\n");
		getch();
	}
	fclose(fp); //Closing the file
}

//returns 0 if the salesman number is not in the right format
//returns the line of the salesman number if it is in the right format
int checkNum (char salesmanNum[10]) {
    int i, line, col;

	if(salesmanNum[0]>='A' && salesmanNum[0]<='Z'
	&& salesmanNum[1]>='A' && salesmanNum[1]<='Z'
	&& salesmanNum[9]>='A' && salesmanNum[9]<='Z') {
		for(i=3; i<=7; i++){
    		if(!isdigit(salesmanNum[i]))
    			return -2;
    	}
    	
		if(salesmanNum[2]!='-' && salesmanNum[8]!='-')
			return -2;
		
		lineOf(salesmanNum,&line,&col);
		return line;
	}
	return -2;
	
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

    while((fgets(str,100,fp))!=NULL) { //continue reading until the end line
        *line+=1;
        pos = strstr(str,salesmanNum);

        if(pos!=NULL) { //word is found
            *col = (pos-str); //memory location of pos minus memory location ng str
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
            if(isdigit(sale[i])) //checks if the char is a digit
                continue;
            else if(sale[i]==46 && countDec==0) //46 is the ASCII code of the decimal point
                countDec+=1; //increment the countDec if a decimal point is encountered
            else
                return 0; //returns 0 when the char is not a digit or not a decimal
        }
        return 1; //returns 1 if the program got out of the for loop
    }             //because this means the inputs are digit and there is only 1 decimal
}


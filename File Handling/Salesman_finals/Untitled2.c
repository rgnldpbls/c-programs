#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sales{
	char salesman_num[20];
	char salesman_name[30];
	double total_sales;
	float commission;
};

typedef struct sales user;

void add_User();
void edit_User();
void remove_User();
void view_User();

int main(){
	char sel;
	char try_again;
	
	do {
		printf("Main Menu\n");
		printf("[A]dd\n");
		printf("[E]dit\n");
		printf("[D]elete\n");
		printf("[V]iew\n");
		printf("E[X]it\n");
		printf("\n\nNote: You should input capital letters\n");
		printf("Please Select: ");
		scanf("%s",&sel);
		
		switch(toupper(sel)){
			case 'A':
				system("cls");
				add_User();
				getch();
				system("cls");
				break;
			case 'E':
				system("cls");
				edit_User();
				getch();
				system("cls");
				break;
			case 'D':
				system("cls");
				remove_User();
				getch();
				system("cls");
				break;
			case 'V':
				system("cls");
				view_User();
				getch();
				system("cls");
				break;
			case 'X':
				system("cls");
				do {
					printf("Are you sure you want to exit?[Y/N]: ");
					scanf("%s",&try_again);
					if(toupper(try_again) == 'Y'){
						printf("\n\n\nThank you for using the program!");
						getch();
					}
					else if(toupper(try_again) == 'N'){
						system("cls");
						sel='Z';
					}
					else{
						printf("Invalid input...");
						getch();
						printf("Please Try Again!");
						getch();
						system("cls");
						sel='Z';
					}
				}while(try_again!='N' || try_again!='Y');
				break;
			default:
				system("cls");
				printf("Invalid input...");
				getch();
				printf("Please Try Again!");
				getch();
				system("cls");
		}
	}while(sel!='X');
	
	return 0;
}

void add_User(){
	FILE *fp;
	fp = fopen("salesman.txt","a");
	if(fp == NULL){
		printf("There's a detected error in the file");
		printf("\nPlease check the salesman.txt file in your computer before trying again.");
		return;
	}
	else{
		user i;
		int count=0;
		double fqs, sqs, tqs, lqs, ts;
		char temp[100];
		
		fflush(stdin);
		do {
            printf("\n\nSalesman Number: ");
            scanf(" %[^\n]%*c",i.salesman_num);

            if(checkNum(i.salesman_num)==0) {
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
		fclose(fp);
		printf("\n\n\n");
		printf("Salesman added successfully\n");
	}
}

void edit_User(){
	char sales_num[10];
	int count=0;
	
	
	do {
        printf("\n\nSalesman Number: ");
        scanf(" %[^\n]%*c",&sales_num);

        if(checkNum(sales_num)==1) {
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
	
	FILE *fp, *temp;
	fp = fopen("salesman.txt","r");
	temp = fopen("temp.txt","w+");
	
	if(fp==NULL){
		printf("There's a detected error in the file");
		printf("\nPlease try again!");
		return;
	}
	else{
		user i;
		double fqs, sqs, tqs, lqs, ts;
		char tempNum[100],tempNum2[100];
		
		while(fscanf(fp,"%s\t%[^\t]\t%[^\t]\t%[^\n]",i.salesman_num,i.salesman_name,tempNum, tempNum2)!=EOF){
			i.total_sales=atof(tempNum);
			i.commission=atof(tempNum2);
			if(strcmp(i.salesman_num,sales_num)==0){
				
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
		fclose(fp);
		fclose(temp);
		remove("salesman.txt");
		rename("temp.txt","salesman.txt");
		fflush(stdin);
		printf("\n\nPress any key to continue.....\n");
	}
}

void remove_User(){
	char sales_num[10];
	int count=0;
	user i;
	
	do {
        printf("\n\nSalesman Number: ");
        scanf(" %[^\n]%*c",sales_num);

        if(checkNum(sales_num)==0) {
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
	
	FILE *fp, *temp;
	fp = fopen("salesman.txt","r");
	temp = fopen("temp.txt","w+");
	if(fp==NULL){
		printf("There's a detected error in the file");
		printf("Please try again!");
		return;
	}
	else{
		char choice[5];
		char ans_yes[5]="yes";
		char ans_no[5]="no";
		char tempNum[100],tempNum2[100];
		
		while(fscanf(fp,"%s\t%[^\t]\t%[^\t]\t%[^\n]",i.salesman_num,i.salesman_name,tempNum, tempNum2)!=EOF){
				i.total_sales=atof(tempNum);
				i.commission=atof(tempNum2);
				if(strcmp(i.salesman_num,sales_num)==0){
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
						}else if(strcmp(ans_no,choice)==0){
							fprintf(temp,"%s\t%s\t%.2lf\t%.2f\n",i.salesman_num, i.salesman_name, i.total_sales, i.commission);
							fflush(stdin);
							i.total_sales=0.00;
							i.commission=0.00;
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
			fclose(fp);
			fclose(temp);
			remove("salesman.txt");
			rename("temp.txt","salesman.txt");
			fflush(stdin);
			printf("\n\nPress any key to continue.....\n");
	}
}

void view_User(){
	FILE *fp;
	char printSales[100];
	fp = fopen("salesman.txt","r");
	if(fp==NULL){
		printf("There's a detected error in the file");
		printf("Please try again!");
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
    			return 0;
    	}
    	
		if(salesmanNum[2]!='-' && salesmanNum[8]!='-')
			return 0;
		
		lineOf(salesmanNum,&line,&col);
		return line;
	}
	return 0;
	
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

    return *col;
}

//returns 1 for valid sale input and 0 if invalid
int checkSale (char sale[]) {
	int i;
	if(!isdigit(sale[0]))
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

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
	
	select:
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
			getchar();
			getchar();
			system("cls");
			goto select;
			break;
		case 'E':
			system("cls");
			edit_User();
			getchar();
			getchar();
			system("cls");
			goto select;
			break;
		case 'D':
			system("cls");
			remove_User();
			getchar();
			getchar();
			system("cls");
			goto select;
			break;
		case 'V':
			system("cls");
			view_User();
			getchar();
			getchar();
			system("cls");
			goto select;
			break;
		case 'X':
			system("cls");
			exit:
			printf("Are you sure you want to exit?[Y/N]: ");
			scanf("%s",&try_again);
			if(toupper(try_again) == 'Y'){
				printf("\n\n\nThank you for using the program!");
				getchar();
				getchar();
				exit(0);
			}
			else if(toupper(try_again) == 'N'){
				system("cls");
				goto select;
			}
			else{
				printf("Invalid input...");
				getchar();
				getchar();
				printf("Please Try Again!");
				getchar();
				getchar();
				system("cls");
				goto exit;
			}
		default:
			system("cls");
			printf("Invalid input...");
			getchar();
			getchar();
			printf("Please Try Again!");
			getchar();
			getchar();
			system("cls");
			goto select;
	}
	return 0;
}

void add_User(){
	FILE *fp;
	fp = fopen("salesman.txt","a");
	if(fp == NULL){
		printf("There's a detected error in the file");
		printf("Please try again!");
		return;
	}
	else{
		user i;
		double fqs, sqs, tqs, lqs, ts;
		fflush(stdin);
		printf("Salesman Number: ");
		scanf("%s",i.salesman_num);
		
		fflush(stdin);
		printf("\n\nSalesman Name: ");
		scanf("%[^\n]s",i.salesman_name);
		
		printf("\n\nFirst Quarter Sales: ");
		scanf("%lf",&fqs);
		
		printf("\n\nSecond Quarter Sales: ");
		scanf("%lf",&sqs);
		
		printf("\n\nThird Quarter Sales: ");
		scanf("%lf",&tqs);
		
		printf("\n\nFourth Quarter Sales: ");
		scanf("%lf",&lqs);
		
		ts = fqs + sqs + tqs + lqs;
		i.total_sales = ts;
		
		if(ts<=5000){
			i.commission = ts*10/100;
			fprintf(fp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
		}
		else if(ts<=10000){
			i.commission = ts*15/100;
			fprintf(fp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
		}
		else if(ts<=15000){
			i.commission = ts*20/100;
			fprintf(fp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
		}
		else if(ts<=20000){
			i.commission = ts*25/100;
			fprintf(fp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
		}
		else if(ts<=25000){
			i.commission = ts*30/100;
			fprintf(fp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
		}
		else if(ts>25000){
			i.commission = ts*50/100;
			fprintf(fp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
		}
		fflush(stdin);
		fclose(fp);
		printf("\n\n\n");
		printf("Salesman added successfully\n");
	}
}

void edit_User(){
	char sales_num[20];
	printf("Enter the Sales Number you want to update: ");
	scanf("%s",&sales_num);
	
	FILE *fp, *temp;
	fp = fopen("salesman.txt","r");
	temp = fopen("temp.txt","w+");
	if(fp==NULL){
		printf("There's a detected error in the file");
		printf("Please try again!");
		return;
	}
	else{
		int found = 0;
		user i;
		double fqs, sqs, tqs, lqs, ts;
		while(fscanf(fp,"%s %lf %f %[^\n]s",i.salesman_num,&i.total_sales,&i.commission,i.salesman_name)!=EOF){
			if(strcmp(i.salesman_num,sales_num)==0){
				printf("\nSalesman Name: %s",i.salesman_name);
				printf("\nTotal Sales: %.2lf",i.total_sales);
				printf("\nCommission: %.2f",i.commission);
				
				printf("\n\nInput new contents of salesman:");
				printf("\n\nFirst Quarter Sales: ");
				scanf("%lf",&fqs);
		
				printf("\n\nSecond Quarter Sales: ");
				scanf("%lf",&sqs);
		
				printf("\n\nThird Quarter Sales: ");
				scanf("%lf",&tqs);
			
				printf("\n\nFourth Quarter Sales: ");
				scanf("%lf",&lqs);
		
				ts = fqs + sqs + tqs + lqs;
				i.total_sales = ts;
			
				if(ts<=5000){
					i.commission = ts*10/100;
					fprintf(temp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
				}
				else if(ts<=10000){
					i.commission = ts*15/100;
					fprintf(temp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
				}
				else if(ts<=15000){
					i.commission = ts*20/100;
					fprintf(temp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
				}
				else if(ts<=20000){
					i.commission = ts*25/100;
					fprintf(temp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
				}
				else if(ts<=25000){
					i.commission = ts*30/100;
					fprintf(temp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
				}
				else if(ts>25000){
					i.commission = ts*50/100;
					fprintf(temp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
				}
				printf("\n\nThe account is updated successfully!.");
				found =1;
				}else{
					fprintf(temp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
					fflush(stdin);
				}
		}if(found==0){
			printf("\n\nRecord not found!");
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
	char sales_num[20];
	printf("Enter the Sales Number you want to remove: ");
	scanf("%s",&sales_num);
	
	FILE *fp, *temp;
	fp = fopen("salesman.txt","r");
	temp = fopen("temp.txt","w+");
	if(fp==NULL){
		printf("There's a detected error in the file");
		printf("Please try again!");
		return;
	}
	else{
		int found = 0;
		user i;
		char choice[5];
		char ans_yes[5]="yes";
		char ans_no[5]="no";
		while(fscanf(fp,"%s %lf %f %[^\n]s",i.salesman_num,&i.total_sales,&i.commission,i.salesman_name)!=EOF){
				if(strcmp(i.salesman_num,sales_num)==0){
					printf("\nSalesman Name: %s",i.salesman_name);
					printf("\nTotal Sales: %.2lf",i.total_sales);
					printf("\nCommission: %.2f",i.commission);
					
					again:
					printf("\n\nDo you want to delete[yes/no]? ");
					scanf("%s",&choice);
					
					if(strcmp(ans_yes,choice)==0){
						printf("\n\nThe account is removed successfully!.");
						found=1;
						fflush(stdin);
					}else if(strcmp(ans_no,choice)==0){
						found=1;
						fprintf(temp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
						fflush(stdin);
					}else{
						printf("Invalid Input!");
						goto again;
					}
				}
				else{
					fprintf(temp,"%s\t%.2lf\t%.2f\t%s\n",i.salesman_num,i.total_sales,i.commission,i.salesman_name);
					fflush(stdin);
				}
			}if(found==0){
				printf("\n\nRecord not found!");
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
	fp = fopen("salesman.txt","r");
	if(fp==NULL){
		printf("There's a detected error in the file");
		printf("Please try again!");
		return;
	}
	else{
		user i;
		printf("\n|Salesman Number\t|Salesman Name\t\t|Total Sales\t\t|Commission");
		while(fscanf(fp,"%s %lf %f %[^\n]s",i.salesman_num,&i.total_sales,&i.commission,i.salesman_name)!=EOF){
			printf("\n|%s\t\t|%s\t\t|%.2lf\t\t|%.2f",i.salesman_num,i.salesman_name,i.total_sales,i.commission);
		}
		fflush(stdin);
		fclose(fp);
		printf("\n\nPress any key to continue.....\n");
	}
}
	

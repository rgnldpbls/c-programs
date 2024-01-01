#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product{
	char prod_code[15];
	char prod_description[25];
	int avail_qty;
};

typedef struct product prod;

void menu();
void AddRecord();
void UpdateRecord();
void RemoveRecord();
void ListRecord();

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
			AddRecord();
			getchar();
			getchar();
			system("cls");
			goto select;
			break;
		case 'E':
			system("cls");
			UpdateRecord();
			getchar();
			getchar();
			system("cls");
			goto select;
			break;
		case 'D':
			system("cls");
			RemoveRecord();
			getchar();
			getchar();
			system("cls");
			goto select;
			break;
		case 'V':
			system("cls");
			ListRecord();
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

void AddRecord(){
	system("cls");
	FILE *fp;
	fp = fopen("product.txt","a");
	if(fp == NULL){
		printf("Error in opening the file, please try again!\n");
		printf("Press any key to continue.....\n");
		return;
	}
	else{
		prod p;
		printf("\nAdd new Product");
		
		printf("\n\nProduct Code: ");
		scanf("%s",p.prod_code);
		
		printf("\n\nProduct Description: ");
		scanf("%s",p.prod_description);
		
		printf("\n\nInitial Quantity: ");
		scanf("%d",&p.avail_qty);
		
		fprintf(fp,"%s\t%d\t%s\n",p.prod_code,p.avail_qty,p.prod_description);
		
		fflush(stdin);
		fclose(fp);
		system("cls");
		printf("Product added Successfully\n");
		printf("Press any key to continue.....\n");
	}
}

void ListRecord(){
	system("cls");
	printf("===========PRODUCT DETAILS===========\n");
	FILE *fp;
	fp = fopen("product.txt","r");
	if(fp == NULL)
	{
		printf("Error in opening the file, please try again!\n");
		printf("Press any key to continue.....\n");
		return;
	}
	else{
		prod p;
		while(fscanf(fp,"%s\t%d\t%s\n",p.prod_code,&p.avail_qty,p.prod_description)!=EOF){
			printf("\n\n|Product Code:\t\t%s",p.prod_code);
			printf("\n|Product Description:\t%s",p.prod_description);
			printf("\n|Initial Quantity:\t%d",p.avail_qty);
			fflush(stdin);
		}
		fflush(stdin);
		fclose(fp);
		printf("\n\nPress any key to continue.....\n");
	}
}

void UpdateRecord(){
	system("cls");
	char prod_num[80];
    printf("Enter Product Code of the product you want to update the details : ");
    scanf("%s",&prod_num);
    
    FILE *fp,*temp;
    fp = fopen("product.txt", "r");
    temp = fopen("temp.txt","w+");
    if (fp == NULL)
    {
        printf("Error in opening the file, please try again!\n");
        printf("Press any key to continue....\n");
        return;
    }
    else{
    	int flag = 0;
        prod p;
        int trans, purch, sold;
        while(fscanf(fp,"%s\t%d\t%s\n",p.prod_code,&p.avail_qty,p.prod_description)!=EOF){
        	if(strcmp(p.prod_code,prod_num)==0){
        		printf("\n|Product Name:\t%s",p.prod_description);
				printf("\n|Available Quantity:\t%d",p.avail_qty);
				
				transact:
				printf("\n\nTransaction[0.Purchase/1.Sold]? ");
				scanf("%d",&trans);
				
				if(trans==0){
					printf("Quantity to Purchase: ");
					scanf("%d",&purch);
					p.avail_qty = purch + p.avail_qty;
					fprintf(temp,"%s\t%d\t%s\n",p.prod_code,p.avail_qty,p.prod_description);
				}
				else if(trans==1){
					ques:
					printf("Quantity to Sold: ");
					scanf("%d",&sold);
					if(p.avail_qty<sold){
						printf("Invalid!");
						goto ques;
					}else{
						p.avail_qty = p.avail_qty - sold;
						fprintf(temp,"%s\t%d\t%s\n",p.prod_code,p.avail_qty,p.prod_description);
					}
				}else{
					printf("Invalid Input!");
					goto transact;
				} 
				system("cls");
                printf("The Product is updated successfully\n");
                flag = 1;
			}else{
				fprintf(temp,"%s\t%d\t%s\n",p.prod_code,p.avail_qty,p.prod_description);
				fflush(stdin);
			}
		}if(flag == 0)
        {
            system("cls");
            printf("No record found for %s number\n",prod_num);
        }
        fclose(fp);
        fclose(temp);
        remove("product.txt");
        rename("temp.txt","product.txt");
        fflush(stdin);
        printf("Press any key to continue....\n");
	}
}

void RemoveRecord(){
	system("cls");
	char prod_num[80];
    printf("Enter Product Code of the product you want to update the details : ");
    scanf("%s",&prod_num);
    
    FILE *fp,*temp;
    fp = fopen("product.txt","r");
    temp = fopen("temp.txt","w+");
    if (fp == NULL)
    {
        printf("Error in opening the file, please try again!\n");
        printf("Press any key to continue....\n");
        return;
    }else{
    	int flag = 0;
        prod p;
        char choice;
        while(fscanf(fp,"%s\t%d\t%s\n",p.prod_code,&p.avail_qty,p.prod_description)!=EOF){
        	if(strcmp(p.prod_code,prod_num)==0){
        		printf("\n|Product Name: %s",p.prod_description);
				printf("\n|Available Quantity: %d",p.avail_qty);
				
				printf("\n\nThe account is removed successfully!.");
				flag=1;
			}else{
				fprintf(temp,"%s\t%d\t%s\n",p.prod_code,p.avail_qty,p.prod_description);
				fflush(stdin);
			}
		}if(flag==0){
			system("cls");
            printf("No record found for %s number\n",prod_num);
		}
		fclose(fp);
		fclose(temp);
		remove("product.txt");
		rename("temp.txt","product.txt");
		fflush(stdin);
		printf("\n\nPress any key to continue.....\n");
	}
}

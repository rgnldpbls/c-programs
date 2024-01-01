#include <stdio.h>

int main()
{
	int age, educ, vitalw, vitalb, vitalh, gender;
	char name [80];
	
	printf("Welcome to Miss Universe Qualification!\n");
	printf("Please enter your name: ");
    scanf("%s",name);
    
    printf("Enter your age: ");
    scanf("%d",&age);
    
    printf("Please enter your highest educational attainment:\n");
	printf("Press 1 if you are atleast high school graduate.\nPress 0 if not: ");
	scanf("%d",&educ);
	
	printf("Please enter your vital stats in waistline(in): ");
	scanf("%d",&vitalw);
	
	printf("Please enter your vital stats in bustline(in): ");
    scanf("%d",&vitalb);
    
    printf("Please enter your vital stats in hipline(in): ");
    scanf("%d",&vitalh);
    
    printf("Please enter your gender:\nPress 1 if you are Female.\nPress 0 if not: ");
    scanf("%d",&gender);
    
    if(age>=18 && age<=28){
		if(educ==1){
			if(vitalw==36){
				if(vitalb==24){
					if(vitalh==36){
						if(gender==1){
							printf("Ms.%s, Congratulations! You are qualified in Miss Universe.\n", name);
						}else
							printf("Sorry, you are not qualified!\nReason:You did not meet the qualification in gender.\n");
					}else
						printf("Sorry, you are not qualified!\nReason:You did not meet the qualification in  vital stats.\n");
				}else
					printf("Sorry, you are not qualified!\nReason:You did not meet the qualification in vital stats.\n");
			}else
				printf("Sorry, you are not qualified!\nReason:You did not meet the qualification in vital stats.\n");
		}else
			printf("Sorry, you are not qualified!\nReason:You did not meet the qualification in education.\n");
	}else
		printf("Sorry, you are not qualified!\nReason:You did not meet the qualification in age.\n");
	
    printf("Thank you for using the program.");
    return 0;
	}

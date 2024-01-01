#include<stdio.h>
#include<stdlib.h>

int main(){
	int sdk[3][3]={0}, ip[3]={0}; //sdk is the main array / ip the input array
	int a,b,x; // a represent rows, b for columns, x for inputs 
	int y; //use for the loop inputting 3 times
	int k=1; //use for loop in try again
	char name[80];
	
	
	printf("Please input your username:");
	scanf("%[^\n]s",&name);
	system("cls");
	printf("Hello %s,\nWelcome to Sudoku solver!\n",name);
	printf("\nMechanics of this games are the following:");
	printf("\nThe size of the game is 3x3.\n");
	printf("\nThe user will input designated rows and columns from the range of 1-3.\n");
	printf("\nThe user will input numbers in the range of 1-9.\n");
	printf("\nThe user will input three times.\n\n");
	
	while(k==1){
		printf("Please input the designated row and column.\n");
		y=0;
		do{
			e:
			printf("\nRow:");
			scanf("%d",&a);
			scanf("%*[^\n]");
			if(a<=0||a>3){
				printf("\nInput error,You input invalid row\nPlease try again!\n");
				goto e;
			}printf("Column:");
			scanf("%d",&b);
			scanf("%*[^\n]");
			if(b<=0||b>3){
				printf("\nInput error,You input invalid column\nPlease try again!\n");
				goto e;
			}printf("Please input the number you choose from 1-9:");
			scanf("%d",&x);
			scanf("%*[^\n]");
			if(x<=0||x>9){
				printf("\nInput error,You input invalid number\nPlease try again!\n");
				goto e;
			}else if(sdk[a-1][b-1]!=0){
				printf("\nInput error\nYou already input the same row and column\nPlease try again!\n");
				goto e;
			}else if(x==ip[0]){
				printf("\nInput error\nYou already input the same number\nPlease try again!\n");
				goto e;
			}else if(x==ip[1]){
				printf("\nInput error\nYou already input the same number\nPlease try again!\n");
				goto e;
			}else if(x==ip[2]){
				printf("\nInput error\nYou already input the same number\nPlease try again!\n");
				goto e;
			}else if(x!=0){
			sdk[a-1][b-1]=x;
			}ip[y]=x;
			y++;
		}while(y<3);
		printf("\nThe complete filled out table for your sudoku is:\n");
		x=1;
		for(a=0;a<3;a++){
			for(b=0;b<3;b++){
				if(sdk[a][b]==0){
					while(sdk[a][b]==0){
						if(x==ip[0]){
							x++;
						}else if(x==ip[1]){
							x++;
						}else if(x==ip[2]){
							x++;
						}else if(sdk[a][b]==0){
							sdk[a][b]=x;
							printf("%d ",sdk[a][b]);
							x++;
							break;
						}
					}
				}else{
						printf("%d ",sdk[a][b]);
				}
			}printf("\n");
		}
		c:
		printf("\n\nWould you like to play again?\n");
		printf("Press 1 if Yes\nPress 0 if No\n");
		printf("Your choice:");
		scanf("%d",&k);
		system("cls");
		for(a=0;a<3;a++)
            ip [a]=0;
        for(a=0;a<3;a++)
            for (b=0;b<3;b++)
                sdk[a][b]=0;
		if(k==0){
			printf("Thank you for using this program!");
			exit(0);
		}else if(k>1){
			goto c;
		}
	}
	return 0;
}

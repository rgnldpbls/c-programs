// Final
#include<stdio.h>
#include<stdlib.h>

void header(){
	printf("\t\t\t============================================\n");
	printf("\t\t\t\t\tSUDOKU SOLVER\n");
	printf("\t\t\t============================================\n\n\n");
}

void instr(){
	printf("\t\tMechanics of this games are the following:\n\n");
	printf("\t\tThe size of the game is 3x3.\n\n");
	printf("\t\tThe user will input designated rows and columns from the range of 1-3.\n\n");
	printf("\t\tThe user will input numbers in the range of 1-9.\n\n");
	printf("\t\tThe user will input three times.\n\n\n");
}

int main(){
	int sdk[3][3]={0}; //sdk is the main array / ip the input array
	int *ip;
	ip = (int*)malloc(3*sizeof(int));
	int a,b,x; // a represent rows, b for columns, x for inputs 
	int *pa, *pb, *px;
	pa=&a, pb=&b, px=&x;
	int y; //use for the loop inputting 3 times
	int k=1; //use for loop in try again
	char name[80];
	
	system("color 0a");
	header();
	printf("\t\tPlease input your username:");
	scanf("%[^\n]s",&name);
	system("cls");
	
	header();
	printf("\t\tHello %s, Welcome to Sudoku solver!\n\n",name);
	instr();
	
	while(k==1){
		header();
		printf("\tPlease input the designated row and column.\n\n");
		y=0;
		do{
			start:
			printf("\n\tRow:");
			scanf("%*[^\n]");
			scanf("%d",&a);
			if(a<=0||a>3){
				scanf("%*[^\n]");
				printf("\n\tInput error,You input invalid row\n\tPlease try again!\n\n");
				goto start;
			}printf("\n\tColumn:");
			scanf("%d",&b);
			if(b<=0||b>3){
				scanf("%*[^\n]");
				printf("\n\tInput error,You input invalid column\n\tPlease try again!\n\n");
				goto start;
			}printf("\n\tPlease input the number you choose from 1-9:");
			scanf("%d",&x);
			if(x<=0||x>9){
				scanf("%*[^\n]");
				printf("\n\tInput error,You input invalid number\n\tPlease try again!\n\n");
				goto start;
			}else if(*(*(sdk+(a-1))+(b-1))!=0){
				printf("\n\tInput error, You already input the same row and column\n\tPlease try again!\n\n");
				goto start;
			}else if(x==*(ip+0)){
				printf("\n\tInput error, You already input the same number\n\tPlease try again!\n\n");
				goto start;
			}else if(x==*(ip+1)){
				printf("\n\tInput error, You already input the same number\n\tPlease try again!\n\n");
				goto start;
			}else if(x==*(ip+2)){
				printf("\n\tInput error, You already input the same number\n\tPlease try again!\n\n");
				goto start;
			}else if(x!=0){
				(*(*(sdk+(a-1))+(b-1))=x);
			}*(ip+y)=x;
			y++;
		}while(y<3);
		printf("\n\tThe complete filled out table for your sudoku is:\n");
		x=9;
		for(a=0;a<3;a++){
			for(b=0;b<3;b++){
				if(*(*(sdk+*pa)+*pb)==0){
					while(*(*(sdk+*pa)+*pb)==0){
						if(*px==*(ip+0)){
							x--;
						}else if(*px==*(ip+1)){
							x--;
						}else if(*px==*(ip+2)){
							x--;
						}else if(*(*(sdk+*pa)+*pb)==0){
							*(*(sdk+*pa)+*pb)=*px;
							printf("\t|\t%d\t| ",*(*(sdk+*pa)+*pb));
							x--;
							break;
						}
					}
				}else{
						printf("\t|\t%d\t| ",*(*(sdk+*pa)+*pb));
				}
			}printf("\n");
		}
		end:
		printf("\n\n\tWould you like to play again?\n");
		printf("\tPress 1 if Yes\n\tPress 0 if No\n");
		printf("\tYour choice:");
		scanf("%d",&k);
		system("cls");
		for(a=0;a<3;a++)
            ip [a]=0;
        for(a=0;a<3;a++)
            for (b=0;b<3;b++)
                sdk[a][b]=0;
		if(k==0){
			header();
			printf("\t\t\t\tThank you for using this program!\n\n");
			exit(0);
		}else if(k>1){
			goto end;
		}
	}
	return 0;
}

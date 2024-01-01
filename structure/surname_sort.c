//By Surname
#include<stdio.h>

struct student{
	int idNum;
	char fName[80];
	char lName[80];
};

void input(struct student user[5],int i){
	int a;
	for(a=0;a<i;a++){
		printf("Please Enter Your ID Number: ");
		scanf("%d",&user[a].idNum);
		
		fflush(stdin);
		printf("Please Enter Your First Name: ");
		scanf("%[^\n]s",user[a].fName);
		
		fflush(stdin);
		printf("Please Enter Your Last Name: ");
		scanf("%[^\n]s",user[a].lName);
		
		printf("\n\n");
	}
}
void output(struct student user[5], int i){
	int a;
	printf("==============================================================================\n");
	printf("LastName\t\tFirstName\t\t\tID Number\t\t\n");
	for(a=0;a<i;a++){
		printf("%s\t\t\t%s\t\t\t%d\t\t\t\n",user[a].lName,user[a].fName,user[a].idNum);
	}
	printf("==============================================================================\n");
}
void sort(struct student user[5], int i){
	int a,b,srt;
	struct student temp;
	for(a=0;a<i-1;a++){
		for(b=a+1;b<i;b++){
			srt=strcmp(user[a].lName,user[b].lName);
			if(srt>0){
				temp=user[a];
				user[a]=user[b];
				user[b]=temp;
			}
		}
	}
}
int main(){
	struct student user[5];
	int i=5;
	
	input(user,i);
	printf("Before sorting:\n");
	output(user,i);
	sort(user,i);
	printf("\n\n");
	printf("After sorting:\n");
	output(user,i);
	
	return 0;
}

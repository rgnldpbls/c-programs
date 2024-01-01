#include<stdio.h>

/*int main(){
	FILE *fp;
	fp = fopen("BSIT.txt","a");
	char name[80];
	printf("Enter any string: ");
	scanf("%s",name);
	fprintf(fp,"%s\t",name );
	fclose(fp);
	
	return 0;
}*/

/*int main(){
	FILE *fp;
	fp = fopen("BSIT.txt","a");
	struct record{
		char name[80];
		int age;
	};	
	char ans='y';
	struct record stud;
	
	while(ans=='y'){
		printf("name please:");
		scanf("%s",stud.name);
		printf("age please:");
		scanf("%d",&stud.age);
		fprintf(fp,"%s\t%d\n",stud.name, stud.age);	
		printf("another record(y/n): ");
		scanf("%s",&ans);
	}
	fclose(fp);
}*/

/*int main(){
	FILE *fp;
	fp = fopen("BSIT.txt","r");
	char name[80];
	int age;
	 
	while(fscanf(fp,"%s %d",name, &age)!=EOF){
		printf("%s\t%d\n",name,age);
	}
	fclose(fp);
	return 0;
}*/

/*int main(){
	FILE *fp;
	char word[80]="WelcomeBSIThopeyouhaveagreatday!";
	fp = fopen("BSIT.doc","w");
	fwrite(&word, sizeof(word),1,fp);
	
	fclose(fp);
}*/

/*int main(){
	FILE *fp;
	
	char ch;
	fp = fopen("try.txt","r");
	
	fseek(fp,5,SEEK_CUR);
		ch = getc(fp);
		printf("%c\n",ch);
	fclose(fp);
	
	rename("BSIT.txt","BSIT,1-4.txt");
	return 0;
}*/

int main(){
	char sales_num[15];
	printf("sales num: ");
	scanf("%s",&sales_num);
	printf("%s",sales_num);
}

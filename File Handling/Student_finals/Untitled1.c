#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	char stud_no[15];
	char stud_name[25];
	char course[5];
	int year;
	int section;
};

void add_student();
void edit_student();
void delete_student();
void view_student();

typedef struct student stud;

int main(){
	char choose;
	
	back:
	printf("Main Menu\n");
	printf("[A]dd\n");
	printf("[E]dit\n");
	printf("[D]elete\n");
	printf("[V]iew\n");
	printf("E[X]it\n");
	printf("Please choose: ");
	scanf("%s",&choose);
	
	switch(choose){
		case 'A':
			add_student();
			goto back;
			break;
		case 'E':
			edit_student();
			goto back;
			break;
		case 'D':
			delete_student();
			goto back;
			break;
		case 'V':
			view_student();
			goto back;
			break;
		case 'X':
			printf("\nExit Program");
			exit(0);
		default:
			printf("Invalid Input");
			system("cls");
			goto back;
			break;
	}
}

void add_student(){
	system("cls");
	FILE *fp;
	fp = fopen("student.txt","a");
	if(fp!=NULL){
		stud s;
		printf("Add New Student");
		printf("\nStudent Number: ");
		scanf("%s",s.stud_no);
		
		fflush(stdin);
		printf("\nStudent Name: ");
		scanf("%[^\n]s",s.stud_name);
		
		printf("\nCourse: ");
		scanf("%s",s.course);
		
		printf("\nYear: ");
		scanf("%d",&s.year);
		
		printf("\nSection: ");
		scanf("%d",&s.section);
		
		fprintf(fp,"%s\t%s\t%d\t%d\t%s\n",s.stud_no,s.course,s.year,s.section,s.stud_name);
		
		fflush(stdin);
		fclose(fp);
		printf("\n\nStudent Info Added Successfully!");
		system("cls");
	}
	else{
		printf("Error in opening the file, please try again!\n");
		printf("Press any key to continue.....\n");
		getchar();
		system("cls");
		return;
	}
}

void edit_student(){
	system("cls");
	char student_num[15];
	printf("Please input Student Number: ");
	scanf("%s",&student_num);
	
	FILE *fp, *fp_temp;
	fp = fopen("student.txt","r");
	fp_temp = fopen("temp_file.txt","w+");
	if(fp!=NULL){
		int flag=0;
		stud s;
		while(fscanf(fp,"%s %s %d %d %[^\n]s",s.stud_no,s.course,&s.year,&s.section,s.stud_name)!=EOF){
			if(strcmp(s.stud_no,student_num)==0){
				printf("\nStudent Name:%s",s.stud_name);
				printf("\nCourse:%s",s.course);
				printf("\nYear:%d",s.year);
				printf("\nSection:%d",s.section);
				
				printf("\n\nInput new student information");
				printf("\nNew Year Level: ");
				scanf("%d",&s.year);
				
				printf("\nNew Section: ");
				scanf("%d",&s.section);
				
				fprintf(fp_temp,"%s\t%s\t%d\t%d\t%s\n",s.stud_no,s.course,s.year,s.section,s.stud_name);
				printf("\n\nStudent Info Updated Successfully!");
				flag=1;
			}
			else{
				fprintf(fp_temp,"%s\t%s\t%d\t%d\t%s\n",s.stud_no,s.course,s.year,s.section,s.stud_name);
				fflush(stdin);
			}
		}if(flag==0){
			printf("Record not found!");
			getchar();
			system("cls");
		}
		fflush(stdin);
		fclose(fp);
		fclose(fp_temp);
		remove("student.txt");
		rename("temp_file.txt","student.txt");
		fflush(stdin);
		printf("\nPress any key to continue....\n");
		getchar();
		system("cls");
	}
	else{
		printf("Error in opening the file, please try again!\n");
		printf("Press any key to continue.....\n");
		getchar();
		system("cls");
		return;	
	}
}

void delete_student(){
	system("cls");
	char student_num[15];
	printf("Please input Student Number: ");
	scanf("%s",&student_num);
	
	FILE *fp, *fp_temp;
	fp = fopen("student.txt","r");
	fp_temp = fopen("temp_file.txt","w+");
	if(fp!=NULL){
		int flag=0;
		stud s;
		while(fscanf(fp,"%s %s %d %d %[^\n]s",s.stud_no,s.course,&s.year,&s.section,s.stud_name)!=EOF){
			if(strcmp(s.stud_no,student_num)==0){
				printf("\nStudent Name:%s",s.stud_name);
				printf("\nCourse:%s",s.course);
				printf("\nYear:%d",s.year);
				printf("\nSection:%d",s.section);
				
				printf("\n\nStudent Info Removed Successfully!");
				flag=1;
			}
			else{
				fprintf(fp_temp,"%s\t%s\t%d\t%d\t%s\n",s.stud_no,s.course,s.year,s.section,s.stud_name);
				fflush(stdin);
			}
		}if(flag==0){
			printf("Record not found!");
			getchar();
			system("cls");
		}
		fflush(stdin);
		fclose(fp);
		fclose(fp_temp);
		remove("student.txt");
		rename("temp_file.txt","student.txt");
		fflush(stdin);
		printf("\nPress any key to continue....\n");
		getchar();
		system("cls");
	}
	else{
		printf("Error in opening the file, please try again!\n");
		printf("Press any key to continue.....\n");
		getchar();
		system("cls");
		return;	
	}
}

void view_student(){
	system("cls");
	FILE *fp;
	fp = fopen("student.txt","r");
	if(fp!=NULL){
		stud s;
		while(fscanf(fp,"%s %s %d %d %[^\n]s",s.stud_no,s.course,&s.year,&s.section,s.stud_name)!=EOF){
			printf("\nStudent Number:%s",s.stud_no);
			printf("\nStudent Name:%s",s.stud_name);
			printf("\nCourse:%s",s.course);
			printf("\nYear:%d",s.year);
			printf("\nSection:%d",s.section);
			printf("\n");
			fflush(stdin);		
		}
		fclose(fp);
		printf("\n\nPress any key to continue.....\n");
		getchar();
		getchar();
		system("cls");
	}
	else{
		printf("Error in opening the file, please try again!\n");
		printf("Press any key to continue.....\n");
		system("cls");
		return;
	}
}

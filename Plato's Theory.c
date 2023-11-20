// Plato's Theory
#include <stdio.h>

int main()
{
    
    char gender;
    char name[80];
    int age;
    
    printf("Please enter your username: ");
    scanf("%s",name);
    printf("Enter your age: ");
    scanf("%d",&age);
    printf("Please enter your gender:\nPress M if Male\nPress F if Female\n");
    scanf(" %c",&gender);
    
    if(gender=='M'||gender=='m')
    {        
        age = age / 2+7;
        printf("Hi %s, your gender is Male and your ideal partner's age is %d.\n",name,age);
    }
    else
    {
        age = (age - 7)*2;
        printf("Hi %s, your gender is Female and your ideal partner's age is %d.\n",name,age);
    }
	printf("Thanks for using the program.\n");
   return 0;
}

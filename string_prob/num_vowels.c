#include<stdio.h>  
#include<string.h>
#include<conio.h>


int vowels(char []);

int main(){  
    int c;  
    char str[100];
	
    printf ("Input 100 characters:\n");
    for(c=0;c<100;c++){  
    	str[c]= getchar();
	}
    printf("\n\n\n");
    printf("Output:\n");
	printf("%s",str);
	printf("\n\n");   
    printf("Length: %d",strlen(str));
    
	c = vowels(str);
    return 0;
}

int vowels(char str[]){
	int a=0, e=0, i=0, o=0, u=0, d=0;
	char f;
	
	do{
		f=str[d];
		
		if(f=='a'){
			a++;
		}
		if(f=='e'){
			e++;
		}
		if(f=='i'){
			i++;
		}
		if(f=='o'){
			o++;
		}
		if(f=='u'){
			u++;
		}
		d++;
	}while(f!='\0');
	printf("\n\nNumber of a's: %d",a);
	printf("\n\nNumber of e's: %d",e);
	printf("\n\nNumber of i's: %d",i);
	printf("\n\nNumber of o's: %d",o);
	printf("\n\nNumber of u's: %d",u);
		
	return;
}

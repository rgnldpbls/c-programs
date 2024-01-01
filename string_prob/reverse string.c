//REVERSE STRING

#include<stdio.h>
#include<string.h>

int main()
{
	char wrd[100];
	int length, i;
	
	printf("Input word: ");
	scanf("%s", wrd);
	length= strlen(wrd);
	
	for(i=length; i>=0; i--)
	{
		printf("%c ",wrd[i]);
	}
	printf("\n");
	return 0;
}

//Case fix

#include<stdio.h>
#include<string.h>

int main()
{
	char wrd[100];
	int i;
	printf("Input word:");
	scanf("%s",wrd);
	
	if(wrd[0]>=97 && wrd[0]<=122)
		wrd[0] = wrd[0]-32;
	printf("%c",wrd[0]);
	for(i=1;i<strlen(wrd);i++)
	{
		if(wrd[i]>=65 && wrd[i]<=91)
			printf("%c",wrd[i]+32);
		else
			printf("%c",wrd[i]);
	}
	
	return 0;
	
}

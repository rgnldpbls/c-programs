#include<stdio.h>

int main(){
	char x[3][3]={{'*'},{'*','*'},{'*','*','*'}};
	int a,b;
	for(a=2;a>=0;a--)//outer loop
	{
		for(b=0;b<=a;b++)//inner loop
		{
			printf("%c ",x[a][b]);
			}printf("\n");
	}
}

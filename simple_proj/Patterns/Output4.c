#include<stdio.h>

int main(){
	int x[3][3]={{3},{3,2},{3,2,1}};
	int a,b;
	for(a=2;a>=0;a--)//outer loop
	{
		for(b=0;b<=a;b++)//inner loop
		{
			printf("%d ",x[a][b]);
			}printf("\n");
	}
}

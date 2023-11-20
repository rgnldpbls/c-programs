// Simple Math Calculator
#include<stdio.h>

int main(){
	double num1,num2,sum,diff,prod,quo;
	
	printf("First Number: ");
	scanf("%lf",&num1);
	
	printf("Second Number: ");
	scanf("%lf",&num2);
	
	printf("\n\n\nResults:");
	add_func(num1,num2,sum);
	subt_func(num1,num2,diff);
	multi_func(num1,num2,prod);
	div_func(num1,num2,quo);
	
}
int add_func(double num1,double num2,double sum){
	sum = num1 + num2;
	printf("\nThe Sum of %.2lf and %.2lf is %.2lf.",num1,num2,sum);
	return;
}
int subt_func(double num1,double num2,double diff){
	if(num1>num2){
		diff = num1 - num2;
		printf("\nThe Difference between %.2lf and %.2lf is %.2lf.",num1,num2,diff);
		return;
	}else{
		diff = num2 - num1;
		printf("\nThe Difference between %.2lf and %.2lf is %.2lf.",num2,num1,diff);
		return;
	}
}
int multi_func(double num1,double num2,double prod){
	prod = num1*num2;
	printf("\nThe Product of %.2lf and %.2lf is %.2lf.",num1,num2,prod);
	return;
}
int div_func(double num1,double num2,double quo){
	if(num1>num2){
		quo = num1/num2;
		printf("\nThe Quotient between %.2lf and %.2lf is %.2lf.",num1,num2,quo);
		return;
	}else{
		quo = num2/num1;
		printf("\nThe Quotient between %.2lf and %.2lf is %.2lf.",num2,num1,quo);
		return;
	}
}

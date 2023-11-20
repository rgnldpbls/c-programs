//Simple Loan Calculator
#include<stdio.h>

int main(){
	double loan,pay,curr_loan;
	
	printf("Please input your loan: ");
	scanf("%lf",&loan);
	
	printf("\n\n\nHere is the monthly payment schedule:");
	printf("\n\nMonth 1");
	pay = loan*10/100;
	printf("\nTen percent of %.2lf = %.2lf",loan,pay);
	curr_loan = loan-pay;
	printf("\nRemaining amount: %.2lf",curr_loan);
	
	printf("\n\nMonth 2");
	pay = curr_loan*10/100;
	printf("\nTen percent of %.2lf = %.2lf",curr_loan,pay);
	curr_loan = curr_loan-pay;
	printf("\nRemaining amount: %.2lf",curr_loan);
	
	printf("\n\nMonth 3");
	pay = curr_loan*10/100;
	printf("\nTen percent of %.2lf = %.2lf",curr_loan,pay);
	curr_loan = curr_loan-pay;
	printf("\nRemaining amount: %.2lf",curr_loan);
	
	return 0;
}

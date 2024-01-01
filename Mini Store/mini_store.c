#include <stdio.h>						
int main () {
	
	float kgA, kgB, kgC, kgD, pA, pB, pC, pD;
	char name [80];
	
	printf("Please enter the username: ");
	scanf("%s", name);
	
	printf("Candies Section\n");
	printf("Candy A costs Php.35.00/kg.\n");
	printf("Candy B costs Php.45.00/kg.\n");
	printf("Candy C costs Php.56.00/kg.\n");
	printf("Candy D costs Php.57.50/kg.\n");
	
	printf("Please enter the weight in kg. of Candy A: ");		
	scanf("%f", &kgA);						
	printf("Please enter the weight in kg. of Candy B: ");		
	scanf("%f", &kgB);					
	printf("Please enter the weight in kg. of Candy C: ");		
	scanf("%f", &kgC);					
	printf("Please enter the weight in kg. of Candy D: ");		
	scanf("%f", &kgD);
						
	pA = kgA * 35.00;							
	pB = kgB * 45.00;						
	pC = kgC * 56.00;							
	pD = kgD * 57.50;
	
	printf("Good Day Mr./Ms.%s!\n", name);						
	printf("The costs of Candy A is Php.%.2f\n", pA);	
	printf("The costs of Candy B is Php.%.2f\n", pB);	
	printf("The costs of Candy C is Php.%.2f\n", pC);	
	printf("The costs of Candy D is Php.%.2f\n", pD);
	printf("Thank you for using the program.");
		
	return 0;							
}

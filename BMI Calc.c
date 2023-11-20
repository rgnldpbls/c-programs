// Simple BMI Calculator
#include<stdio.h>


int main(){
	float weight, height, con_height,fin_height,bmi;
	
	printf("Please input your weight in kilogram: ");
	scanf("%f",&weight);
	
	printf("Please input your height in centimeters: ");
	scanf("%f",&height);
	
	con_height = height/100;
	
	fin_height = con_height * con_height;
	
	bmi = weight/fin_height;
	printf("\n\nResults:\n");
	
	if(bmi<18.5){
		printf("Your BMI is %.2f and classified as Underweight",bmi);
		return 0;
	}
	else if(bmi>=18.5 && bmi<=24.9){
		printf("Your BMI is %.2f and classified as Normal",bmi);
		return 0;
	}else if(bmi>=25.0 && bmi <= 29.0){
		printf("Your BMI is %.2f and classified as Overweight",bmi);
		return 0;
	}else if(bmi>=30.0 && bmi <= 40.0){
		printf("Your BMI is %.2f and classified as Obese",bmi);
		return 0;
	}else{
		printf("Your BMI is %.2f and classified as Extreme Obese",bmi);
		return 0;
	}
	
}

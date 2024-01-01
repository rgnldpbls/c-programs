float withdraw(double curbal)
{
	system("cls");
	double wamount;
	printf("Please enter the amount you would like to withdraw:Php ");
	scanf("%lf",&wamount);
	if(wamount>curbal)
	{	printf("Sorry you do not have enough balance.\n");
		printf("Please try again...\n");
	}else{
		curbal = curbal - wamount;
		printf("Your balance is Php %.2f\n",curbal);
	}
	return curbal;
}

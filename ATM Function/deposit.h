float deposit(double curbal)
{
	system("cls");
	double damount;
	printf("Please enter the amount you would like to deposit:Php ");
	scanf("%lf",&damount);
	curbal = curbal + damount;
	printf("Your balance is Php %.2f\n",curbal);
	return curbal;
}

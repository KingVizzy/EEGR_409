//Vallery Salomon
//Lab 3
//EEGR 409 C Programming Applications
//September 16, 2016

#include <stdio.h>

int main()
{

	//Declare Variables
	double N;
	double x;
	int i = 1;
	double sum;
	//Get input from user
	printf("Enter limit value and enter increment value:");
	scanf_s("%d %d", &N, &x);

	//Control Statement
	while (i <= N)
	{

		i = N + x;

	};

	printf("The sum of the numbers are 2.2f", i);

	getchar();


}
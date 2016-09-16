//Vallery Salomon
//Lecture 4 Lab 1
//EEGR 409 C Programming Applications
//September 16, 2016

#include <stdio.h>
#include <math.h>

int main()
{

	//Declare Variables
	int N;
	double x;
	int i = 1;
	double sum = 0;

	//Get input from user
	printf("Enter limit value and enter increment value: ");
	scanf_s("%d %lf", &N, &x);

	//Control Statement
	while (i <= N)
	{

		sum = sum + i;
		i = i + x;

	}

	//Display output
	printf("The sum of the numbers are %2.2lf", sum);

	getchar();
	getchar();
	return 0;
}
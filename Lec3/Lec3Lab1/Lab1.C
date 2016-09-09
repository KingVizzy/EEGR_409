//Vallery Salomon
//EEGR 409 C Programming Applications
//September 9th, 2016
//Lecture 3: Lab 1

#include <stdio.h>

int main()
{

	double a, b, c;

	printf("Enter three numbers: ");
	scanf_s("%lf %lf %lf", &a, &b, &c);

	if (a > b)
	{

		printf("This is the largest number\n%f", a);

	}
	else if (b > c)
	{

		printf("This is the largest number\n%f", b);

	}
	else if (c > b)
	{

		printf("This is the largest number\n%f", c);

	}

	getchar();
	getchar();
}
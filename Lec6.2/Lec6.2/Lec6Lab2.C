//Vallery Salomon
//Lecture 6 Lab 2
//EEGR 409 C Programming Applications
//October 7, 2016

#include <stdio.h>
#include <math.h>




int main()
{


	//Declare Variables
	double getVal();
	double a = getVal(0, 1000000);
	double b = getVal(0, 1000000);
	double c = sqrt(pow(a, 2) + pow(b, 2));

	//Print out hypotenuse
	printf("The hypotenuse is %f", c);

}

double getVal(a, b)
{
	while (1)
	{
		double d;
		printf("Enter length of the two sides of the right triangle:");
		scanf_s("%d", &d);
		if ((a <= d) && (d >= b))
		{
			return d;
		}
		else if
		{
			printf("The value must be greater than 1 \n");
			printf("The value must be less than 1000000 \n");
			printf("Enter a valid value");
		}
		(getchar != "\n");
	} 

}
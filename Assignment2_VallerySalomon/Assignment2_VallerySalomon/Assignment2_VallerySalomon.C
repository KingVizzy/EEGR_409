//Vallery Salomon
//Assignment 2
//EEGR 409 C Programming Applications
//January 24, 2016

#include <stdio.h>
#include <math.h>

int main() 
{
	//Declare variables
	double Sal1;

	//Ask user for input 
	printf("Enter Salinity: ");
	scanf_s("%lf", &Sal1);


	//Control statement to classify Salinity 
	if ((Sal1 > 0) && (Sal1 < 10))
	{

		printf("Salinity is between 0 and 10");

	}

	else if((Sal1 > 11) && (Sal1 < 20))
	{

		printf("Salinity is between 10 and 20");

	}
	
	else if((Sal1 > 21) && (Sal1 < 24.7))
	{

		printf("Salinity is between 20 and 24.7");

	}
	else if((Sal1 > 24.8) && (Sal1 < 30))
	{

		printf("Salinity is between 24.7 and 30");

	}
	else if((Sal1 > 31) && (Sal1 < 35))
	{
		
		printf("Salinity is between 30 and 35");

	}
	else if(Sal1 < 0)
	{

		printf("Error! Invalid Salinity level");

	}
	else if(Sal1 > 36)
	{

		printf("Error! Invalid Salinity level");

	};
	
	
	getchar();
	getchar();

}
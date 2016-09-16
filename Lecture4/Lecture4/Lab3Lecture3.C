//Vallery Salomon
//Lab 3
//EEGR 409 C Programming Applications
//September 16, 2016

#include <stdio.h>

int main() 
{
	//Declare Variable
	double rho;
	int gauge;

	//Get input from user
	printf("Enter Wire gauge(12, 14, 16, 18): ");
	scanf_s("%d", &gauge);

	//Funtion for determining Resistivity from wire gauge
	switch (gauge)
	{
	case 12: rho = 5.211;  break;
	case 14: rho = 8.285;  break;
	case 16: rho = 13.170; break;
	case 18: rho = 20.950; break;
	default: printf("Invalid gauge %d \n", gauge);

		return 1;
	}

	printf("rho is %7.3f ", rho);

	getchar();
	getchar();

}
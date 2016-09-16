//Vallery Salomon
//EEGR 409 C Programming Applications
//Quiz 3
//September 16, 2016

#include <stdio.h>

int main()
{

	//Declare variables
	double rho;
	char class;
	int gauge;

	//Get input from user
	printf("Enter the wire gauge (12, 14, 16, 18): ");
	scanf_s("%d", &gauge);

	//Control statement to output resistivity and class
	switch (gauge)
	{
	case 12: rho = 5.211;
			 class = 'A';
			 break;

	case 14: rho = 8.285;
			 class = 'A';
			 break;

	case 16: rho = 13.170;
			 class = 'B';
			 break;

	case 18: rho = 20.950;
			 class = 'B';
			 break;

	 default: printf("Invalid Wire Gauge\n");
			 return 1;
			 
	}

	printf("The resistivity of the gauge is %7.3f and  the class of the gauge is %c", rho, class);
	
	getchar();
	getchar();
	return 0;


}
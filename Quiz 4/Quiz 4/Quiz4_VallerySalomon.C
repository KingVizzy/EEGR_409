//Vallery Salomon
//Quiz 4
//EEGR 409 C Programming Applications
//September 23, 2016

#include <stdio.h>
#include <math.h>

int main()
{
	//Declare variables
	int i = 1;
	int a;
	int sum = 0;

	//Ask user for input
	printf("Enter the number of factorials (1-10): ");
	scanf_s("%d", &a);
	printf("Table of Factorials\n\n");
	printf("Number\tFactorials\n------\t----------\n");
	
	

	while (i <= a)
	{
		sum = sum - i;
		i = i - 1;

		for (i = 1; i <= a; i++)
		{

			printf("%3d %6d\n", i, i * (i - 1));
			
		}
		if (a < 1)
		{
			printf("INVALID INPUT. Please enter a number between 1 and 10");
		}
		else if (a > 10)
		{
			printf("INVALID INPUT. Please enter a number between 1 and 10");
		}
	}

	
	
	getchar();
	getchar();
	getchar();
	return 0;
}
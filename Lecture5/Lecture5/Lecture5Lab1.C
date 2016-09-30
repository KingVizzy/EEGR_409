//Vallery Salomon
//Lecture 5
//EEGR 409 C Programming Applications
//September 23, 2016

#include <stdio.h>
#include <math.h>


int main()
{
	//Declare Variables
	int i = 0;
	int num = 0;

	//Ask user for input and Label table
	printf("Enter number: \n");
	scanf_s("%d", &num);
	printf("This program outputs a table of squares\n");

	for (i = 0; i <= num; i++)
	{

		printf("%3d %6d\n", i, i*i);

	}

	getchar();
	getchar();
	return 0;
	

}
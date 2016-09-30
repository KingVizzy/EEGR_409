//Vallery Salomon
//Lecture 6 Lab 1
//EEGR 409 C PRogramming Applications
//September 30, 2016


#include <stdio.h>
#include <math.h>

int square(int x)
{
	return pow(x, 2);
	
}

int sumsqd(int x)
{
	return x + x;
	
}

int main()
{
	//Declare Variables & Get user input
	int num1, num2, num_sqrd1, num_sqrd2, sum_sqrd;
	printf("Enter two number: ");
	scanf_s("%d %d", &num1, &num2);

	//Perform operation
	num_sqrd1 = square(num1);
	num_sqrd2 = square(num2);
	sum_sqrd = sumsqd(num_sqrd1, num_sqrd2);

	//Display Results
	printf("The sum and square of %d and %d is %d", num1, num2, sum_sqrd);
	
	getchar();
	getchar();
	return 0;
}
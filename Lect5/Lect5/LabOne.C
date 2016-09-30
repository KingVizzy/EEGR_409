//Vallery Salomon
//Lecture 5
//EEGR 409 C Programming Applications
//September 23, 2016

#include <stdio.h>

int main()
{
	//Declare variables
	char c;


	//Ask user for input
	printf("Enter a character: ");
	do
	{

		scanf_s("%c", &c);
		printf("The character you entered was %c \n", c);


	} while (c != '\n');



	getchar();
	getchar();
	getchar();

}
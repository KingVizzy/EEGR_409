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
	scanf_s("%c", &c);
	printf("The character you entered was %c \n", c);
	printf("It's size is %d", sizeof(c));


	getchar();
	getchar();
	getchar();
	return 0;

}
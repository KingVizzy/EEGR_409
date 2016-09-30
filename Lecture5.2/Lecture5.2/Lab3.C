//Vallery Salomon
//Lecture 5 Lab 2
//EEGR 409 C Programming Applications
//September 30, 2016

#include <stdio.h>

int main()
{

	//Declare Variables
	char c = 0, ct = c;
	printf("Enter some text: \n");

	//Function
	do
	{
		c = getchar();
		
		if (c >= 'a' && c <= 'z') c -= 32;
		printf("%c", c);
	} while (c != '\n');

	getchar();
	getchar();
	return 0;


}
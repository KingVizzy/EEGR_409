//Vallery Salomon
//Lecture 5 Lab 2
//EEGR 409 C Programming Applications
//September 30, 2016

#include <stdio.h>

int main()
{

	//Declare Variables
	char c;
	char c2;
	int i = 0;
	printf("Enter  some text\n");

	//Function
	do 
	{
		scanf_s("%c", &c);
		printf("%c", c);

		if (c >= 'a' && c <= 'z') c2 -= 32;
		printf("%c", c2);
	} while (c != '\n');

	getchar();
	getchar();
	return 0;


}
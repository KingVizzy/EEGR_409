//Vallery Salomon
//Lecture 5 Lab 2
//EEGR 409 C Programming Applications
//September 30, 2016

#include <stdio.h>

int main()
{
	//Declare Variables
	char alp = 'A';
	char alp2 = 'a';
	int i = 0;
	printf("The column of alphabets\n");
	printf("Uppercase\tLowercase\n");

	//Function
	for(i = alp; i <= 'Z'; i++)
	{
		printf("%c \t\t %c \n", alp++, alp2++);

	}

	getchar();
	getchar();
	return 0;

}
//Vallery Salomon
//Quiz 5
//EEGR 409 C Programming Applications
//September 30, 2016

#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()

{

	//Declare Variables and get user input
	char mny, c;
	int n = 1;
	
	//printf("Enter a dollar amount: ");
	scanf("%c", &mny)

	//Perform operations
	do
	{
		c = getchar();
		printf("%c", c);
		if (c >= '0' && c < ':')
		{
			printf("working");
			n++;
		}
	} while (c != '.');
	
	printf("The number of digits is %d \n", n);


	system("pause");
	return 0;
}
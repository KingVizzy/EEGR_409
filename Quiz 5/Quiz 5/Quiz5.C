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
	char mny = 0, c = 0;
	int n = 0;
	printf("Enter a dollar amount: ");
	scanf_s("%c", &mny);

	//Perform operations
	do
	{
		c = getchar();
		if (c >= '0' && c <= ':')
		{
			n++;
		}
	} while (c != '.');
	
	printf("The number of digits is %d \n", n);


	system("pause");
	return 0;
}
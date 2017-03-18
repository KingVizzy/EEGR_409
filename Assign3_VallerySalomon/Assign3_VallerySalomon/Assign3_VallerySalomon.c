//Vallery Salomon
//Assignment 3
//EEGR 409 C Programming Applications
//January 24, 2017

#include <stdio.h>
#include <math.h>

#define REFRate  0.02 
#define TotAcres 14000



void main()
{
	int i = (2500 + (REFRate * 2500)), opt = 0, yrs, reFor = 0;

	printf("TIMBER REGROWTH\n-------------------\n");
	printf("Option 1: Table of Number of Acres Reforested\n");
	printf("Option 2: Number of Years for Complete Reforestation\n");
	printf("Option 3: Exit Program");
	printf("Enter menu option(1-3)\n");
	scanf("%d", &opt);

	/* My thought process behind solving this problem is that I will need a loop within a loop 
	to keep the program running and to perform the correct operation. For option one I had the second loop perform the 
	increment operations needed to make the table */

	while (opt = 1)
	{
		printf("Enter the number of years to use for the table (max 20)");
		scanf("%d", &yrs);
		printf("Year\t\t\tAcres\n----\t\t\t----\n");
		while (i <= yrs)
		{
			reFor = reFor + i;
			i = i + (REFRate * i);
			yrs++;
		}

		printf("%d\t\t\t%d\n", yrs, reFor);
	} while (getchar() != '\n');

	/* For option 2 I looked up a growth rate formula and manipulated it with the exponential function to 
	to solve for the number of years it will take for complete reforestation */
	while (opt = 2)
	{
		int acrs = 0;
		int num = 0;
		printf("Enter the number of acres left uncut to use for the table (max: 14,000)");
		scanf("%d", &acrs);
		num = ( exp(1 + 0.02) / exp(TotAcres / acrs) );
		printf("It will take %d years for complete reforestation", num);

	}while (getchar() != '\n');

	/* Option 3 is to just end the program */
	while (opt = 3)
	{
		break;
	}
}
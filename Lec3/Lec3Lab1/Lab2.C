//Vallery Salomon
//EEGR 409 C Programming Applications
//Labs

#include <stdio.h>

int main()
{
	//Declare Variables
	double Face1E, Face2E, Face1NC, Face2NC, Face3E, Face3NC, Rat1, Rat2, Rat3, Diff1, Diff2, Diff3;

	//Read Variables and store values
	printf("Enter eye distance and nose to chin ratio for face 1: \n");
	scanf_s("%lf %lf", &Face1E, &Face1NC);
	printf("Enter eye distance and nose to chin ratio for face 2: \n");
	scanf_s("%lf %lf", &Face2E, &Face2NC);
	printf("Enter eye distance and nose to chin ratio for face 3: \n");
	scanf_s("%lf %lf", &Face3E, &Face3NC);
	
	//Calculate Eyes to Nose to chin ratios for the 3 faces
	Rat1 = (Face1E / Face1NC);
	Rat2 = (Face2E / Face2NC);
	Rat3 = (Face3E / Face3NC);
	Diff1 = fabs(Rat1 - Rat2);
	Diff2 = fabs(Rat2 - Rat3);
	Diff3 = fabs(Rat1 - Rat3);

	if ((Diff1 > Diff3) && (Diff1 > Diff2))
	{

		printf("These are the smallest ratios: %lf", Diff3, Diff2);


	}
	else if ((Diff2 > Diff1) && (Diff2 > Diff3))
	{

		printf("These are the smallest ratios: %lf", Diff1, Diff3);

	}
	else if ((Diff3 > Diff1) && (Diff3 > Diff2))
	{

		printf("These are the smallest ratios: %lf", Diff1, Diff2);

	}

	getchar;
}
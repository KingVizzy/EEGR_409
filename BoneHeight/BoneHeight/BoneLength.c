//Vallery Salomon
//EEGR 409 C Programming Applications
//Lecture 2 Lab
//September 2, 2016

#include <stdio.h>
#include <math.h>

int main() {

	double femur, humerus;
	double mfem, mhum, ffem, fhum;

	//Get values for femur and humerus
	printf("Enter values for Femur and Humerus: ");
	scanf_s("%lf %lf", &femur, &humerus);

	//Calculate Male and Female Heights from Femur and Humerus
	ffem = (femur * 1.94 + 28.7);
	mfem = (femur * 1.88 + 32);
	mhum = (humerus * 2.8 + 28.2);
	fhum = (humerus * 2.9 + 27.9);

	//Display Male and Female Heights from Femur and Humerus
	printf("Height Estimate in Inches \n\t\"Male\"\t\t\"Female\"\n");
	printf("Femur\t\\%-5.lf\\\t\t\\%6.1lf\\\n", mfem, ffem);
	printf("Humerus\t\\%-5.1lf\\\t\t\\%6.1lf\\\n", mhum, fhum);


	getchar();
	getchar();
	return 0;

}
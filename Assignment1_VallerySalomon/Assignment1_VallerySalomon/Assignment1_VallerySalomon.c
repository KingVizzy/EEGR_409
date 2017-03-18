//Vallery Salomon
//Assignment 1 
//EEGR 409 C Progamming Applications 
//January 24, 2017

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14

int main() {

	//Declare Variables
	double Radius, Diameter, Circumference, TD, D1, D2, D3, AvgD, Dis, Enc, EcR;
	int run1, run2, run3;

	//Get radius of wheel and revolutions made from users
	printf("Enter the radius of the wheel: ");
	scanf_s("%lf", &Radius);
	printf("Enter the number of revolutions for run 1: ");
	scanf_s("%d", &run1);
	printf("Enter the number of revolutions for run 2: ");
	scanf_s("%d", &run2);
	printf("Enter the number of revolutions for run 3: ");
	scanf_s("%d", &run3);
	printf("Enter the true distance traveled: ");
	scanf_s("%lf", &TD);

	//Calculate the distance traveled in each run
	Diameter = (Radius * 2);
	Circumference = (Diameter * PI);
	D1 = (Circumference * run1);
	D2 = (Circumference * run2);
	D3 = (Circumference * run3);
	AvgD = ((D1 + D2 + D3) / 3);
	Enc = abs((int) (AvgD - TD));
	EcR = (Enc / TD);

	//Format and display the results
	printf("RUN\t\tDISTANCE (cm) \n");
	printf("---\t\t------------- \n");
	printf("1\t\t%4.2lf\n", D1);
	printf("2\t\t%4.2lf\n", D2);
	printf("3\t\t%4.2lf\n", D3);
	printf("Average Distance Traveled:\t\t%4.2lf\n", AvgD);
	printf("Encoder Error:\t\t\t\t%1.2lf\n", Enc);
	printf("Percent Encoder Error:\t\t\t%1.2f\n", EcR);

	getchar();
	getchar();
	getchar();
}
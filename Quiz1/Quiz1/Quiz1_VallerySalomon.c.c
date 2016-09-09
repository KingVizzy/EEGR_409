//Vallery Salomon
//EEGR 409 C Programming Applications
//Quiz 1
//September 2, 2016

#include <stdio.h>
#include <math.h>

int main() {

	//Values for Voltages and Resistors
	int Vb = 12;
	int R1 = 10;
	int R2 = 15;
	int R3 = 20;
	
	//Calculated Current Values
	double I2 = (Vb / ( (R1 * R3) / (R1 + R2)));
	double I1 = (Vb - (I2*R2)) / R1;
	double I3 = (I1 - I2);
	
	//Print out I1, I2, and I3
	printf("The current through the resistors are: \n");
	printf("i2=\t%2.2lfA\n", I2);
	printf("i1=\t%2.2lfA\n", I1);
	printf("i3=\t%2.2lfA\n", I3);

	getchar();
	getchar();
	return 0;


}
//Vallery Salomon
//Assignment 3
//EEGR 409 C Programming Applications
//September 12, 2016

#include <stdio.h>
#include <math.h>

#define MAX_SEGMENT 55

void printSegment(double max_id, double vds, double id)
{
	int segments = round((id / max_id) * MAX_SEGMENT);

	printf("%1.2f\u2502", vds);
	for (int i = 0; i, segments; i++)
	{
		printf("\u2588");
	}
	printf(" %2.2f\n", id);
}

int main(void)
{

	//Declare Variables
	double data[2][8] = {{1, 2, 3, 4, 5, 6, 7, 8},	       //VDS
						 {13, 25, 33, 40, 0, 57, 0, 59}};  //ID
	double halfIDS;									       //Half point ID	

	int numCol = sizeof(data[0]) / sizeof(data[0][0]);
	int endPoint = (int)data[0][numCol - 1];

	printf("\t\tMOSFET Drain Current vs Drain to Source Voltage\n");

	printf("-----------------------------------------------------------------------------------\n\n");


	//Computing and display
	for (int i = 0; i < numCol; i++)
	{
		//Find missing data BEFORE it is needed for previous half-point
		if (data[1][i + 1] == 0)
		{
			data[1][i + 1] = data[1][i] + ((data[0][i + 1] - data[0][i]) / (data[0][i + 2] - data[0][i])) * (data[1][i + 2] - data[1][i]);
		}
		//Whole Point Output
		printSegment(data[1][numCol - 1], data[0][i], data[1][i]);

		//Calculate half-point IDS
		halfIDS = data[1][i] + ((data[0][i] + 0.5 - data[0][i]) / (data[0][i + 1] - data[0][i])) * (data[1][i + 1] - data[1][i]);

		//Stopping the output of the last half-point
		if (i == endPoint - 1) return 0;

		//Half-Point Output
		printSegment(data[1][numCol - 1], data[0][i] + 0.5, halfIDS);
	}
	
	return 0;
}
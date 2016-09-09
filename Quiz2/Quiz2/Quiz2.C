//Vallery Salomon
//EEGR 409 C Programming Applications
//September 9, 2016
//Quiz 2

#include <stdio.h>
#include <math.h>

int main()
{
	//Declare Variables
	double t1, t2, t3;
	float Vel1, Vel2, Vel3, Acc1, Acc2, Acc3;

	//Read in values for time
	printf("Enter time 1, 2 and 3 (t1 t2 t3): ");
	scanf_s("%lf %lf %lf", &t1, &t2, &t3);

	//Calculate Velocity and Acceleration
	Vel1 = ((0.0001 * pow(t1, 3)) - (0.00488 * pow(t1, 2)) + (0.75796 * t1) + 181.3566);
	Vel2 = ((0.0001 * pow(t2, 3)) - (0.00488 * pow(t2, 2)) + (0.75796 * t2) + 181.3566);
	Vel3 = ((0.0001 * pow(t3, 3)) - (0.00488 * pow(t3, 2)) + (0.75796 * t3) + 181.3566);

	Acc1 = (3 - 0.000062 * pow(Vel1, 2));
	Acc2 = (3 - 0.000062 * pow(Vel2, 2));
	Acc3 = (3 - 0.000062 * pow(Vel3, 2));


	//Print and format data
	printf("Time\t\tVelocity\tAcceleration\n");
	printf("%1.0lf\t\t%3.2lf\t\t%1.2lf\n", t1, Vel1, Acc1);
	printf("%1.0lf\t\t%3.2lf\t\t%1.2lf\n", t2, Vel2, Acc2);
	printf("%1.0lf\t\t%3.2lf\t\t%1.2lf\n", t3, Vel3, Acc3);

	getchar();
	getchar();
}
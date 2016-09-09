//EEGR 409 C Programming Applications
//Vallery Salomon
//Lab 1
//August 26, 2016
#include <stdio.h>
#include <Math.h>


int main() {

	int p1x = 1; //integer value for x1
	int p1y = 5; //integer value for y1
	int p2x = 4; //integer value for x2
	int p2y = 7; //integer value for y2

	float hyp = sqrt(pow(p2x - p1x,2) + pow(p2y - p1y,2)); //equation for hypotenuse

	printf("The distance between points (1,5) and point (4,7) is: %10.2f \n", hyp); //display the distance between points
	getchar();
}
//Vallery Salomon
//EEGR 409 C Programming Applications
//September 27, 2016
//Assignment 4

#include <stdio.h>

int main()
{
	FILE *sensor;
	int num, min, max, sum, count, first;
	sensor = fopen("C:\\Users\KurrentLogic\Documents\data.txt", "r");
	if (sensor != NULL)
	{
		for (sum = count = first = 0;
			fscanf(sensor, "%d", &num) == 1; sum += num, ++count)
			if (!first)
			{
				min = max = num; first = 1;
			}
			else if (num > max) max = num;
			else if (num < min) min = num;
			fclose(sensor);
			printf("count = %d, min = %d, max = %d, sum = %d, avg = %.1lf\n",
				count, min, max, sum, sum / (double)count);
	}
	else
	{
		printf("Unable to read file 'C:\\Users\KurrentLogic\Documents\data.txt'.\n");
	}
		getchar();
		return 0;
		
}
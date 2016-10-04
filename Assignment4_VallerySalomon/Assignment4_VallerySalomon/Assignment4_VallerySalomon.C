//Vallery Salomon
//EEGR 409 C Programming Applications
//September 27, 2016
//Assignment 4

#include<stdio.h>
#include<math.h>
#include <stdlib.h>


FILE *data1;
int main()
{
	//Declare Variables
	double max_avg = 0;
	double min_avg = 0;
	double data;
	double inp1 = 0;
	double inp2 = 0;
	double inp3 = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	double max = 0;
	double min = 0;
	double sumMin = 0;
	double sumMax = 0;



	data1 = fopen("data.txt", "r");

	if (data1 == NULL)
	{
		printf("Unable to read\n");
	}
	else
	{
		printf("Max Voltage\tAverage Max\tMin Voltage\tAverage Min\n");
		printf("-----------\t---------\t----------\t-----------\n");

		while (fscanf(data1, "%lf", &data) == 1)
		{
			inp3 = inp2;
			inp2 = inp1;
			inp1 = data;

			if (inp2 - inp3 > 0 && inp2 - inp1 > 0)
			{
				max = inp2;
				a++;
				sumMax = sumMax + inp2;
				max_avg = sumMax / a;
				c++;
				if (inp2 < 0.7)
				{
					sumMax -= inp2;
					a--;
					max_avg = sumMax / a;
					printf("%10.3lf\t     -----\t", max);
				}
				else {
					printf("%10.3lf\t%10.3lf\t", max, max_avg);
				}
			}


			if ((inp2 - inp3 < 0) && (inp2 - inp1 < 0))
			{
				min = inp2;
				b++;
				sumMin += inp2;
				min_avg = sumMin / b;
				d++;
				if (min > -1 * 0.7)
				{
					sumMin -= inp2;
					b--;
					min_avg = sumMin / b;
					printf("%10.3lf\t   ------\tSag Detected!!!\n", min);


				}
				else
				{
					printf("%10.3lf\t%10.3lf\n", min, min_avg);
				}
			}
		}
	}
	fclose(data1);

	getchar();
	getchar();
	return 0;
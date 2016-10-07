//Vallery Salomon
//Quiz 6
//EEGR 409 C Programming Applications
//October 7, 2016

#include <stdio.h>
#include <math.h>

int main()
{
	double GetValue();
	double CalcPoly();
	double x = 0;
	double ans = 0;

	
	printf("Enter value for x: ");
	x = GetValue();
	ans = CalcPoly(x);
	printf("The result of the polynomial is %2.0f", ans);

	getchar();
	getchar();

}

double GetValue()
{
	double x = 0;
	
	while (1)
	{
		scanf_s("%lg", &x);
		if ((x > 0) && (x < 1000000))
		{
			return x;
		}
		printf("Enter a valid value for x");
		

	}
	
}

double CalcPoly(double x)
{
	
	double y = pow(x, 2) - (4 * x) + 7;
	return y;
}
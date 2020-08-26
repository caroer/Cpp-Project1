#include <iostream>
#include <cmath>
#include <math.h>


double function(double x)
{
	f = 1 + sin(exp(3 * x))
		return f
}

double I1(int a, int b)
{
	I1 = ((b - a) / 6) * (function(a) + 4 * f((a + b) / 2) + f(b))
		return I1
}

double I2(int a, int b)
{
	gamma = (a + b) * 0.5
		I2 = I1(a, gamma) + I1(gamma, b)
		return I2
}

double ASI(double f, int a, int b, double tol)
{
	I1 = I1(a, b);
	I2 = I2(a, b);
	errest = abs(I1 - I2)

		if (errest < 15 * tol)
		{
			return I2;
		}
	return ASI(f, a, (a + b) / 2, tol / 2) + ASI(f, (a + b) / 2, b, tol / 2)
}

int main()
{
	int a = -1;
	int b = 1;
	double tol = pow(double 10, double - 2);
	f = function();

	I = ASI(f, a, b, tol);

	return 1
}
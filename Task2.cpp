#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

//declaration of function
double f(double x)
{
	//definition of function
	double f = 1 + sin(exp(3 * x));
	return f;
}
//declaration of function
double I1(double a, double b)
{
	//definition of function, integral using Simpson's rule
	double I_1 = ((b - a) / 6) * (f(a) + 4 * f((a + b) / 2) + f(b));
	return I_1;
}
//declaration of function
double I2(double a, double b)
{
	//definition of variable, midpoint
	double gamma = (a + b) * 0.5;
	//definition of function, helping calculate error
	double I_2 = I1(a, gamma) + I1(gamma, b);
	return I_2;
}

//declaration of function, adaptive Simpson's Integration
double ASI(double a, double b, double tol)
{
	//compute I1 integral between values a and b
	double I_1 = I1(a, b);
	//compute I2 integral for estimating error
	double I_2 = I2(a, b);
	//calculate error estimation
	double errest = abs(I_1 - I_2);

	if (errest < 15 * tol) //decide if error is too big
	{
		//end loop if error estimate satisfies tolerance 
		return I_2; 
	}
	else
	{
		//keep looping if error estimate does not satisfy 
		//condition, algorithm will subdivide interval of 
		//integration in two and apply ASI recursively
		return ASI(a, (a + b) / 2, tol / 2) + ASI((a + b) / 2, b, tol / 2);
	}
	
}

int main()
{
	// declaration of variable before use, lower integration limit
	double a = -1; 
	// declaration of variable before use, higher integration limit
	double b = 1; 
	// declaration of variable before use, tolerance
	double tol = pow(10, -3); 

	// declaration of function, final approximation of integral
	double I = ASI(a, b, tol);
	// printing result
	cout << I << endl;

	return 1;
}
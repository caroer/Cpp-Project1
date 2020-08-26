#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// declaration of functions before use
long double sinTaylor(double, double);
long double cosTaylor(double, double);

// Creating function sinTaylor(N, x) that calculates the sum of 
// the first N terms in the Taylor series of the sine function  
// for the variable x. 
long double sinTaylor(double N, double x)
{
	long double result;

	if (N == 0) //the first term in the sum is calculated separately 
	{
		result = x; //the first term is calculated here; x/1
	}
	else //for more terms from the sum, the calculations will be different
	{
		//The sum for N = 1, will be A defined right below times x.
		//For higher N's A right below will be the content of the
		//innermost paranthesis of the polynomialization of the sum.
		long double A = 1 - (x / (2 * N)) * (x / (2 * N + 1));
		//for higher values of N more calculations are necessary
		for (double i = N - 1; i > 0; --i)
		{
			// multiplying the innermost paranthesis A with 
			// the closest fraction from the polynomial
			long double B = A * (x / (2 * i)) * (x / (2 * i + 1));
			//A right below form the two innermost parantheses
			A = 1 - B;
			// this loop keeps repeating to fill up all 
			// paranthesis of the polynomial
		}
		//now only the outer x/1 is missing, multiply here
		result = x * A;
	}
	return result;
}

// Creating function cosTaylor(N, x) that calculates the sum of 
// the first N terms in the Taylor series of the cosine function  
// for the variable x. 
long double cosTaylor(double N, double x)
{
	long double result;

	if (N == 0)  //the first term in the sum is calculated separately 
	{
		result = 1; //the first term is calculated here; 1
	}
	else //for more terms from the sum, the calculations will be different
	{
		//The sum for N = 1, will be A defined right below.
		//For higher N's A right below will be the content of the
		//innermost paranthesis of the polynomialization of the sum.
		long double A = 1 - (x / (2 * N) * (x / (2 * N - 1)));

		//for higher values of N more calculations are necessary
		for (double i = N - 1; i > 0; --i)
		{
			// multiplying the innermost paranthesis A with 
			// the closest fraction from the polynomial
			long double B = A * (x / (2 * i)) * (x / (2 * i - 1));
			//A right below form the two innermost parantheses
			A = 1 - B;
			// this loop keeps repeating to fill up all 
			// paranthesis of the polynomial
		}
		//A will now be the full polynomial
		result = A;
	}
	return result;
}

int main()
{
	//declaration of variable before use, here choose input
	//variable for the approximations
	double x = 2;
	//initialization of vector before use, later use for 
	//filling up with errors from sine approximation
	vector<long double> s;
	//initialization of vector before use, later use for 
	//filling up with errors from cosine approximation
	vector<long double> c;

	for (double N = 0; N <= 24; ++N)
	{
		//definition of variable, error between value of 
		//approximative sine function and sine function 
		//from C standard library
		long double e_s = abs(sin(x) - sinTaylor(N, x));
		//definition of variable, error between value of 
		//approximative cosine function and cosine function 
		//from C standard library
		long double e_c = abs(cos(x) - cosTaylor(N, x));
		//filling the vectors with the errors of the 
		//approximative sine and cosine functions for one 
		//input value x and 1 to 25 number of terms from
		//the Taylor series.
		s.push_back(e_s);
		c.push_back(e_c);
		//printing out the errors of the approximations
		cout << e_s << endl;
		// cout << e_c << endl; 
	}

	//printing out the exact and approximate values and corresponding errors
	//cout << sin(x) << " " << sinTaylor(N,x) << " " << e_s << endl; 
	//cout << cos(x) << " " << cosTaylor(N, x) << " " << e_c << endl; 
	return 1;
}
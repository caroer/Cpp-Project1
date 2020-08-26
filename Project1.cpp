#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double sinTaylor(double, double);
double cosTaylor(double, double);


double sinTaylor(double N, double x)
{
	double result = 1.0;

	if (N == 0)
	{
		result = x;
	}
	else
	{
		double A = 1 - (x / (2 * N)) * (x / (2 * N + 1));

		
		for (double i = N-1; i > 0; --i)
		{
			double B = A * (x / (2 * i)) * (x / (2 * i + 1));
			A = 1 - B;
		}
		result = x * A;
	}
	return result;
}

double cosTaylor(double N, double x)
{
	double result = 1.0;

	if (N == 0)
	{
		result = 1;
	}
	else
	{
		double A = 1 - (x / (2 * N) * (x / (2 * N - 1)));

		for (double i = N - 1; i > 0; --i)
		{
			double B = A * (x / (2 * i)) * (x / (2 * i - 1));
			A = 1 - B;
		}
		result = A;
	}
	return result;
}

int main()
{
	double x = 1;
	double N = 2;
	//cout << sinTaylor(N, x) << endl;
	cout << cosTaylor(N, x) << endl;
	return 1;
}
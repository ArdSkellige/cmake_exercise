#include "funk.hpp"

int test = 9;
void Test(int a)
{
	cout << "Test = " << a << endl;
}

double Sum(double x, double y)
{
	cout << "sum = " << x + y << endl;
	return x + y;
}

double Mult(double x, double y)
{
	cout << "mult = " << x * y << endl;
	return x * y;
}

double Subtraction(double x, double y)
{
	cout << "subtraction = " << x - y << endl;
	return x - y;
}

double Divide(double x, double y)
{
	cout << "divide = " << x / y << endl;
	return x / y;
}

void MesSum(double x, double y)
{
	cout << "Sum " << x << " + " << y << " = " << x + y << endl;
}

void MesMult(double x, double y)
{
	cout << "Mult " << x << " * " << y << " = " << x * y << endl;
}

void MesSubtr(double x, double y)
{
	cout << "Subtr " << x << " - " << y << " = " << x - y << endl;
}

void MesDiv(double x, double y)
{
	cout << "Divide " << x << " / " << y << " = " << x / y << endl;
}
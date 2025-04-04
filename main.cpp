#include "app/funk.hpp"

double (*math)(double, double);
double (*mathAr[4])(double, double) = { Sum, Subtraction, Mult };
typedef void mmm(double, double);
typedef void (*rrr)(double, double);

extern int test;
void Test(int a);
void PrintMessage();

int main()
{
	double res = 0;
	double a = 12.4;
	double b = 3.1;

	// Sum(a, b);
	// math = Subtraction;
	// math(a, b);
	// cout << endl;

	// mathAr[3] = Divide;
	// for (size_t i = 0; i < 4; i++)
	// {
	// 	mathAr[i](a, b);
	// }
	// cout << endl;

	// mmm* n1 = MesDiv;
	// n1(a, b);
	// rrr n2 = MesMult;
	// n2(a, b);
	// cout << endl;

	auto f = [](double& _a)
	{
		_a = 17.2;
	};
	f(a);
	cout << "a = " << a << endl;
	
	Test(test);
	PrintMessage();


	return 0;
}
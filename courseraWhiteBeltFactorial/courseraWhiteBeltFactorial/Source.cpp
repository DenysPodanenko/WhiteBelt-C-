#include <iostream>
using namespace std;

int factorial(int x)
{
	if (x < 1)
	{
		return	1;
	}
	int a = 1;
	for (int i = 1; i <= x; ++i)
	{
		a *= i;
	}
	return a;
}

void main()
{
	int a = 1;
	cout << factorial(a);
}
#include <iostream>

using namespace std;

int main()
{
	double price, discount, extraDiscount, discountPerc, extraDiscountPerc;
	cin >> price >> discount >> extraDiscount >> discountPerc >> extraDiscountPerc;

	if (price > extraDiscount)
	{
		double a = price * (extraDiscountPerc / 100);
		cout << price - a;
	}
	else if (price > discount)
	{
		double a = price * (discountPerc / 100);
		cout << price - a;
	}
	else
	{
		cout << price;
	}
	return 0;
}
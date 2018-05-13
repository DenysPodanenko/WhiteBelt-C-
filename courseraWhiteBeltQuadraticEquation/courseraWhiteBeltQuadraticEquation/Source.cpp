#include <iostream>

using namespace std;

int main()
{
	double a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	double D = pow(b, 2) - (4 * a*c);

	if (D > 0)
	{
		cout << ((-b + sqrt(D)) / (2 * a)) << endl;
		cout << ((-b - sqrt(D)) / (2 * a)) << endl;
	}
	if (D == 0)
	{
		cout << (-b) / (2 * a);
	}
	if (D < 0)
	{
		cout << "There are no real roots";
	}

	system("pause");
	return 0;
}
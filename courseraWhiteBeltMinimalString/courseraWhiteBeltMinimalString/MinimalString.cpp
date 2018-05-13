#include <iostream>
#include <string>

using namespace std;

int main()
{
	string first;
	string second;
	string third;

	cin >> first;
	cin >> second;
	cin >> third;

	if (first < second && first < third)
	{
		cout << first;
	}
	else if (second < first && second < third)
	{
		cout << second;
	}
	else if (third < first && third < second)
	{
		cout << third;
	}

	system("pause");

	return 0;
}
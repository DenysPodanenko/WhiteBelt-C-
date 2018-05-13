#include <iostream>

using namespace std;

int main()
{
	int hour = 0;
	int min = 0;

	cin >> hour;
	cin >> min;

	if (hour == 12)
	{
		cout << 12;
	}
	else
	{
		cout << 12 - hour<<endl;
	}

	if (min == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << 60 - min << endl;
	}
	return 0;
}
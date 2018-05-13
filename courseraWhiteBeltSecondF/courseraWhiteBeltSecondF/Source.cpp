#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int fCount = 0;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'f')
		{
			fCount++;
		}
		if (fCount == 2)
		{
			cout << i << endl;
			break;
		}
	}

	if (fCount == 0)
	{
		cout << -2 << endl;
	}
	if (fCount == 1)
	{
		cout << -1 << endl;
	}

	system("pause");

	return 0;
}
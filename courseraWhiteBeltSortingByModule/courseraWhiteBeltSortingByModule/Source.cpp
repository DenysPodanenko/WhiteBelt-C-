#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool myfunction(int i, int j)
{
	return (abs(i) < abs(j));
}

int main()
{
	int N = 0;
	cin >> N;
	
	vector<int> v;

	for (int i = 0; i < N; ++i)
	{
		int number = 0;
		cin >> number;
		v.push_back(number);
	}

	sort(v.begin(), v.end(), myfunction);

	for (const auto& i : v)
	{
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
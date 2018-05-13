#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction(const string& a, const string& b)
{
	string first = "";
	string second = "";

	for (auto& i : a)
	{
		char ch = tolower(i);
		first.push_back(ch);
	}
	for (auto& i : b)
	{
		char ch = tolower(i);
		second.push_back(ch);
	}

	return (first < second);
}

int main()
{
	int N = 0;
	cin >> N;

	vector<string> v;

	for (int i = 0; i < N; ++i)
	{
		string str = "";
		cin >> str;

		v.push_back(str);
	}

	sort(v.begin(), v.end(), myfunction);

	for (const auto& i : v)
	{
		cout << i << ' ';
	}

	system("pause");
	return 0;
}
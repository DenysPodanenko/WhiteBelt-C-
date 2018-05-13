#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	set<string> strs;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		strs.insert(str);
	}

	cout << strs.size();
	return 0;
}
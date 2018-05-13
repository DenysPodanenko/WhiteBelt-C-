#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s) 
{
	for (size_t i = 0; i < s.size() / 2; ++i) 
	{
		if (s[i] != s[s.size() - i - 1]) 
		{
			return false;
		}
	}
	return true;
}

vector<string> PolinomFilter(vector<string> vec, int length)
{
	vector<string> answer;

	for (auto c : vec)
	{
		if (c.size() >= length && IsPalindrom(c))
		{
			answer.push_back(c);
		}
	}

	return answer;
}

int main()
{
	vector<string> vec = PolinomFilter({ "abacaba", "aba" },5);

	for (auto i : vec)
	{
		cout << i << endl;
	}

	system("pause");
	return 0;
}
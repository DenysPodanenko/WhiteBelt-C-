#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//vector<string> AnagramCheck(const map<string, string>& m)
//{
//	vector<string> answer;
//	
//	map<char, int> firstWord;
//	map<char, int> secondWord;
//
//	for (const auto& couple : m)
//	{
//		for (int i = 0; i < couple.first.size(); ++i)
//		{
//			++firstWord[couple.first[i]];
//		}
//		for (int i = 0; i < couple.second.size(); ++i)
//		{
//			++secondWord[couple.second[i]];
//		}
//
//		if (firstWord == secondWord)
//		{
//			answer.push_back("YES");
//		}
//		else
//		{
//			answer.push_back("NO");
//		}
//
//		firstWord.clear();
//		secondWord.clear();
//	}
//
//	return answer;
//}

map<char, int> BuildCharCounters(string str)
{
	map<char, int> charCounter;

	for (const auto& ch : str)
	{
		++charCounter[ch];
	}

	return charCounter;
}

int main()
{
	int countOfCouples = 0;
	cin >> countOfCouples;

	for (int i = 0; i < countOfCouples; ++i)
	{
		string firstWord;
		cin >> firstWord;
		string secondWord;
		cin >> secondWord;

		if (BuildCharCounters(firstWord) == BuildCharCounters(secondWord))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}
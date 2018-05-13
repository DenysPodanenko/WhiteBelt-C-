#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;

void ADD(vector<set<string>>& v,const string& word1,const string& word2)
{
	set<string> s;
	s.insert(word1);
	s.insert(word2);

	v.push_back(s);
}

void COUNT(const vector<set<string>>& v,const string& word)
{
	int c = 0;
	for (const auto& s : v)
	{
		c += s.count(word);
	}

	cout << c << endl;
}

void CHECK(const vector<set<string>>& v, const string& word1, const string& word2)
{
	int counter = 0;
	for (const auto& s : v)
	{
		counter += s.count(word1);
		counter += s.count(word2);

		if (counter == 2)
		{
			cout << "YES" << endl;
			return;
		}
		else
		{
			counter = 0;
		}
	}

	cout << "NO" << endl;
}

int main()
{
	int Q = 0;
	cin >> Q;

	vector<set<string>> synonyms;

	for (int i = 0; i < Q; ++i)
	{
		string command = "";
		cin >> command;

		if (command == "ADD")
		{
			string word1 = "";
			cin >> word1;
			string word2 = "";
			cin >> word2;
			ADD(synonyms, word1, word2);
		}
		else if (command == "COUNT")
		{
			string word = "";
			cin >> word;
			COUNT(synonyms, word);
		}
		else if (command == "CHECK")
		{
			string word1 = "";
			cin >> word1;
			string word2 = "";
			cin >> word2;

			CHECK(synonyms, word1, word2);
		}
	}

	system("pause");
	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ADD(vector<vector<string>>& month, int day, string business)
{
	month[day].push_back(business);
}

void importBusiness(vector<vector<string>>& month)
{
	vector<string> tmp;
	for (int i = 29; i < 31; ++i)
	{
		for (auto s : month[i])
		{
			tmp.push_back(s);
		}
	}
	month.resize(30);
	month[29].insert(end(month[29]), begin(tmp), end(tmp));
}

void NEXT(vector<vector<string>>& month, int& currentMonth)
{
	if (currentMonth != 11)
	{
		currentMonth++;
		if (currentMonth == 1)
		{
			vector<string> tmp;
			for (int i = 27; i < 31; ++i)
			{
				for (auto s : month[i])
				{
					tmp.push_back(s);
				}
			}
			month.resize(28);
			month[27].insert(end(month[27]), begin(tmp), end(tmp));
		}
		else if (currentMonth % 2 == 0)
		{
			month.resize(31);
		}
		else if (currentMonth % 2 != 0)
		{
			importBusiness(month);
		}
	}
	else
	{
		currentMonth = 0;
		importBusiness(month);
	}
}

struct answerCople
{
	int count;
	vector<string> business;
};

answerCople DUMP(vector<vector<string>>& month, int day)
{
	answerCople answ;
	answ.count = month[day].size();
	answ.business = month[day];

	return answ;
}

int main()
{
	int currentMonth = 0;
	vector<vector<string>> month(31);
	vector<answerCople> answer;

	int operationCount = 0;
	cin >> operationCount;

	for (int i = 0; i < operationCount; ++i)
	{
		string command = "";
		cin >> command;

		if (command == "ADD")
		{
			int day = 0;
			string business = "";
			cin >> day;
			cin >> business;

			ADD(month,day-1,business);
		}
		else if (command == "NEXT")
		{
			NEXT(month, currentMonth);
		}
		else if (command == "DUMP")
		{
			int day = 0;
			cin >> day;
			answer.push_back(DUMP(month, day-1));
		}
	}

	for (auto struc : answer)
	{
		cout << struc.count << " ";
		for (auto b : struc.business)
		{
			cout << b << " ";
		}

		cout << endl;
	}

	system("pause");
	return 0;
}
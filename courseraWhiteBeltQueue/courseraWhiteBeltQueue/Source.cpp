#include <iostream>
#include <vector>
#include <string>

using namespace std;

void COME(vector<bool>& people, int count)
{
	if (count >= 0)
	{
		people.resize(people.size()+count, false);
	}
	else
	{
		people.erase(people.end()+count,people.end());
	}
}

void WORRY(vector<bool>& people, int peopIndex)
{
	people[peopIndex] = true;
}

void QUIET(vector<bool>& people, int peopIndex)
{
	people[peopIndex] = false;
}

int WORRY_COUNT(const vector<bool>& people)
{
	int count = 0;
	for (auto p : people)
	{
		if (p == 1)
		{
			count++;
		}
	}

	return count;
}

int main()
{
	int countOperations = 0;
	cin >> countOperations;

	vector<bool> queue;
	vector<int> answer;
	for (int i = 0; i < countOperations; ++i)
	{
		string command = "";
		int comValue = 0;

		cin >> command;

		if (command == "WORRY")
		{
			cin >> comValue;
			WORRY(queue, comValue);
		}
		else if (command == "QUIET")
		{
			cin >> comValue;
			QUIET(queue,comValue);
		}
		else if(command == "COME")
		{
			cin >> comValue;
			COME(queue, comValue);
		}
		else if (command == "WORRY_COUNT")
		{
			answer.push_back(WORRY_COUNT(queue));
		}
	}
	
	for (auto i : answer)
	{
		cout << i << endl;
	}
	system("pause");
	return 0;
}
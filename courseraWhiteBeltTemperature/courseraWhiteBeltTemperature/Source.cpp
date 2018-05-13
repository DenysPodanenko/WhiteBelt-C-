#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	vector<int> days(N);
	for (int i = 0; i < days.size(); ++i)
	{
		cin >> days[i];
	}

	int tmpSum = 0;
	for (int i = 0; i < days.size(); ++i)
	{
		tmpSum += days[i];
	}

	int middle = tmpSum / days.size();

	vector<int> answer;
	for (int i = 0; i < days.size(); ++i)
	{
		if (days[i] > middle)
		{
			answer.push_back(i);
		}
	}

	cout << answer.size() << endl;
	for (int n : answer)
	{
		cout << n << " ";
	}

	return 0;
}
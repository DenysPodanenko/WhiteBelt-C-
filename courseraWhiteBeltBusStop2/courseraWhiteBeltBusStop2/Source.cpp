#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int countOfRequests = 0;
	cin >> countOfRequests;

	int busNumber = 1;

	map<int, vector<string>> buses;

	for (int i = 0; i < countOfRequests; ++i)
	{
		vector<string> stops;
		int N = 0;
		cin >> N;
		for (int j = 0; j < N; ++j)
		{
			string stop;
			cin >> stop;
			stops.push_back(stop);
		}

		bool isBus = false;
		for (auto& couple : buses)
		{
			if (couple.second == stops)
			{
				cout << "Already exists for " << couple.first << endl;
				isBus = true;
			}
		}
		if (!isBus)
		{
			buses[busNumber] = stops;
			cout << "New bus " << busNumber << endl;
			++busNumber;
		}
	}

	system("pause");
	return 0;
}
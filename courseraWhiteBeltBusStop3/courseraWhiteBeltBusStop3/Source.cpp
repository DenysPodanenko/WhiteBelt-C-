#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
	int Q = 0;
	cin >> Q;

	map<int, set<string>> buses;
	int busNumber = 1;

	for (int i = 0; i < Q; ++i)
	{
		set<string> stops;
		int stopsCount = 0;
		cin >> stopsCount;

		for (int j = 0; j < stopsCount; ++j)
		{
			string stop = "";
			cin >> stop;
			stops.insert(stop);
		}

		bool isExist = false;
		int existBus = 0;
		for (const auto& item : buses)
		{
			if (item.second == stops)
			{
				isExist = true;
				existBus = item.first;
			}
		}

		if (isExist)
		{
			cout << "Already exists for " << existBus << endl;
		}
		else
		{
			buses[busNumber] = stops;
			busNumber++;
		}
	}

	system("pause");
	return 0;
}
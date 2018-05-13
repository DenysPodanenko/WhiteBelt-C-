#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void NEW_BUS(map<string, vector<string>>& m, const string& busName,const int& countStops)
{
	vector<string> stops;
	for (int i = 0; i < countStops; ++i)
	{
		string stop = "";
		cin >> stop;
		stops.push_back(stop);
	}

	m[busName] = stops;
}

void BUSES_FOR_STOP(const map<string, vector<string>>& m,const string& stop)
{
	vector<string> currStopBuses;

	for (const auto& couple : m)
	{
		for (const auto& v : couple.second)
		{
			if (v == stop)
			{
				currStopBuses.push_back(couple.first);
			}
		}
	}

	if (currStopBuses.size() == 0)
	{
		cout << "No stop" << endl;
	}
	else
	{
		for (const auto& b : currStopBuses)
		{
			cout << b << " ";
		}
		cout << endl;
	}
}

void STOPS_FOR_BUS(map<string, vector<string>>& m,const string& bus)
{
	bool isThisBus = false;
	for (const auto& couple : m)
	{
		if (couple.first == bus)
		{
			isThisBus = true;
		}
	}
	if (!isThisBus)
	{
		cout << "No bus" << endl;
		return;
	}
	vector<string> stops = m[bus];

	for (const auto& s : stops)
	{
		bool busExist = false;
		cout << "Stop " << s << ": ";
		for (const auto& couple : m)
		{
			for (const auto& v : couple.second)
			{
				if (v == s && couple.first != bus)
				{
					cout << couple.first << " ";
					busExist = true;
				}
			}
		}
		if (!busExist)
		{
			cout << "no interchange";
		}
		cout << endl;
	}
}

void ALL_BUSES(const map<string, vector<string>>& m)
{
	if (m.size() == 0)
	{
		cout << "No buses" << endl;
	}
	else
	{
		for (const auto& couple : m)
		{
			cout << "Bus " << couple.first << ": ";
			for (const auto& v : couple.second)
			{
				cout << v << " ";
			}
			cout << endl;
		}
	}
}

//struct route
//{
//	string bus;
//	vector<string> stops;
//};

int main()
{
	int countOfRequest = 0;
	cin >> countOfRequest;

	map<string, vector<string>> buses;

	for (int i = 0; i < countOfRequest; ++i)
	{
		string command = "";
		cin >> command;

		if (command == "NEW_BUS")
		{
			string bus = "";
			cin >> bus;
			int stopCount;
			cin >> stopCount;

			NEW_BUS(buses, bus, stopCount);
		}
		else if (command == "BUSES_FOR_STOP")
		{
			string stop = "";
			cin >> stop;

			BUSES_FOR_STOP(buses, stop);
		}

		else if (command == "STOPS_FOR_BUS")
		{
			string bus = "";
			cin >> bus;
			
			STOPS_FOR_BUS(buses,bus);
		}
		else if (command == "ALL_BUSES")
		{
			ALL_BUSES(buses);
		}
	}

	system("pause");
	return 0;
}
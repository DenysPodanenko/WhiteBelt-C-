#include <iostream>
#include <map>
#include <string>

using namespace std;

void CHANGE_CAPITAL(map<string, string>& m,const string& country,const string& newCapital)
{
	bool IsNewCountry = true;
	for (const auto& couple : m)
	{
		if (country == couple.first)
		{
			IsNewCountry = false;
		}
	}
	
	if (m[country] == newCapital)
	{
		cout << "Country " << country << " hasn't changed its capital" << endl;
	}
	else if (IsNewCountry)
	{
		cout << "Introduce new country " << country << " with capital " << newCapital << endl;
		m[country] = newCapital;
	}
	else
	{
		cout << "Country " << country << " has changed its capital from " << m[country] << " to " << newCapital << endl;
		m[country] = newCapital;
	}
}

void RENAME(map<string, string>& m,const string& oldCountry,const string& newCountry)
{
	bool isExistOldCountry = false;
	bool isExistNewCountry = false;

	for (const auto& couple : m)
	{
		if (couple.first == oldCountry)
		{
			isExistOldCountry = true;
		}
		if (couple.first == newCountry)
		{
			isExistNewCountry = true;
		}
	}
	
	if (oldCountry != newCountry && isExistOldCountry && !isExistNewCountry)
	{
		cout << "Country " << oldCountry << " with capital " << m[oldCountry] << " has been renamed to " << newCountry << endl;

		string tmp = m[oldCountry];
		m.erase(oldCountry);
		m[newCountry] = tmp;
	}
	else
	{
		cout << "Incorrect rename, skip" << endl;
	}
}

void ABOUT(map<string, string>& m, const string& country)
{
	bool isExist = false;
	
	for (const auto& couple : m)
	{
		if (couple.first == country)
		{
			isExist = true;
		}
	}

	if (isExist)
	{
		cout << "Country " << country << " has capital " << m[country] << endl;
	}
	else
	{
		cout << "Country " << country << " doesn't exist" << endl;
	}
}

void DUMP(const map<string, string>&m)
{
	if (m.size() == 0)
	{
		cout << "There are no countries in the world" << endl;
	}
	else
	{
		for (const auto& couple : m)
		{
			cout << couple.first << "/" << couple.second << endl;
		}
	}
}

int main()
{
	int countOfRequests = 0;
	cin >> countOfRequests;
	map<string, string> countryCapitals;

	for (int i = 0; i < countOfRequests; ++i)
	{
		string command;
		cin >> command;

		if (command == "CHANGE_CAPITAL")
		{
			string oldCap;
			cin >> oldCap;
			string newCap;
			cin >> newCap;
			
			CHANGE_CAPITAL(countryCapitals, oldCap, newCap);
		}
		else if (command == "RENAME")
		{
			string oldCountry;
			cin >> oldCountry;
			string newCountry;
			cin >> newCountry;

			RENAME(countryCapitals, oldCountry,newCountry);
		}
		else if (command == "ABOUT")
		{
			string country;
			cin >> country;

			ABOUT(countryCapitals, country);
		}
		else if (command == "DUMP")
		{
			DUMP(countryCapitals);
		}
	}


	return 0;
}
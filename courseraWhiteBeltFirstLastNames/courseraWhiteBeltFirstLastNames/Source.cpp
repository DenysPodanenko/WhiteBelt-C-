#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Name
{
	string FirstName;
	string LastName;
};

class Person {
public:
	void ChangeFirstName(const int& year, const string& first_name) {
		info[year].FirstName = first_name;
	}
	void ChangeLastName(const int& year, const string& last_name) {
		info[year].LastName = last_name;
	}
	string GetFullName(int year) {
		if (!isYearExist(year))
		{
			return "Incognito";
		}

		if (info[year].FirstName.size() != 0 && info.find(year) != info.end())
		{
			FirstName = info[year].FirstName;
		}
		else 
		{
			string str = "";
			do
			{
				year = info.lower_bound(year)->first;
				if (info[year].FirstName.size() > 0)
				{
					str = info[year].FirstName;
				}
				if (year = info.begin()->first)
				{
					break;
				}
			} 
			while (str.size() == 0);

			FirstName = str;
		}

		if (info[year].LastName.size() != 0 && info.find(year) != info.end())
		{
			LastName = info[year].LastName;
		}
		else
		{
			int a = info.lower_bound(year)->first;
			string str = "";
			do
			{
				if (info[a].FirstName.size() > 0)
				{
					str = info[a].LastName;
				}
				if (a = info.begin()->first)
				{
					break;
				}

				a = info.lower_bound(a)->first;
			} while (str.size() == 0);

			LastName = str;
		}

		if (FirstName.size() == 0)
		{
			return LastName + " with unknown first name";
		}
		else if (LastName.size() == 0)
		{
			return FirstName + " with unknown last name";
		}
		else
		{
			return FirstName + " " + LastName;
		}
	}
private:
	string FirstName;
	string LastName;
	map<int, Name> info;

	bool isYearExist(const int& year)
	{
		if (year >= info.begin()->first)
		{
			return true;
		}
		else
		{
			false;
		}
	}
};


int main()
{
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	system("pause");
	return 0;
}
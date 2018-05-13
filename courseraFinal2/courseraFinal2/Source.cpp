#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <exception>

using namespace std;

struct Day
{
	int value;
	explicit Day(int newValue)
	{
		value = newValue;
	}
};

struct Month
{
	int value;
	explicit Month(int newValue)
	{
		value = newValue;
	}
};

struct Year
{
	int value;
	explicit Year(int newValue)
	{
		value = newValue;
	}
};

struct Date
{
	int year;
	int month;
	int day;

	Date(Year newYear, Month newMonth, Day newDay)
	{
		year = newYear.value;
		month = newMonth.value;
		day = newDay.value;
	}

	Date()
	{
		year = 0;
		month = 0;
		day = 0;
	}
};

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.year == rhs.year && lhs.month == rhs.month)
	{
		return lhs.day < rhs.day;
	}
	else if (lhs.year == rhs.year)
	{
		return lhs.month < rhs.month;
	}
	return lhs.year < rhs.year;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	if (lhs.year == rhs.year && 
		lhs.month == rhs.month && 
		lhs.day == rhs.day)
	{
		return true;
	}
	return false;
}

void  EnsureNextSymbolAndSkip(stringstream& stream)
{
	if (stream.peek() != '-')
	{
		throw runtime_error("Wrong date format: " + stream.str());
	}
	stream.ignore(1);
}

Date strToDate(const string& dStr)
{
	stringstream stream(dStr);
	Date date;


	stream >> date.year;
	EnsureNextSymbolAndSkip(stream);

	stream >> date.month;
	if (date.month < 1 || date.month>12)
	{
		stringstream ss;
		ss << "Month value is invalid: " << to_string(date.month);
		throw runtime_error(ss.str());
	}
	EnsureNextSymbolAndSkip(stream);

	stream >> date.day;
	if (date.day < 1 || date.day>31)
	{
		stringstream ss;
		ss << "Day value is invalid: " << to_string(date.day);
		throw runtime_error(ss.str());
	}
	return date;	
}

class CustomDataBase
{
public:
	void Add(Date& date,const string& event)
	{
		db.insert(pair<Date, string>(date, event));
	}

	bool Del(Date& date,const string& event)
	{
		typedef multimap<Date, string>::iterator iterator;
		pair<iterator, iterator> iterpair = db.equal_range(date);

		bool isErase = false;

		iterator it = iterpair.first;
		for (; it != iterpair.second; ++it)
		{
			if (it->second == event)
			{
				db.erase(it);
				isErase = true;
				break;
			}
		}

		if (isErase)
		{
			return true;
		}
		return false;
	}

	int Del(Date& date)
	{
		int count = db.count(date);
		db.erase(date);
		return count;
	}
	
	vector<string> Find(const Date& date)
	{
		vector<string> events;

		typedef multimap<Date, string>::iterator iterator;
		pair<iterator, iterator> iterpair = db.equal_range(date);

		iterator it = iterpair.first;
		for (; it != iterpair.second; ++it)
		{
			events.push_back(it->second);
		}

		sort(events.begin(), events.end());

		return events;
	}

	void Print() const
	{
		cout << "----------" << endl;
		for (const auto& pair : db)
		{
			cout << setw(4) << setfill('0') << pair.first.year<<'-';
			cout << setw(2) << setfill('0') << pair.first.month << '-' << pair.first.day<<' ';
			cout << pair.second << endl;
		}
		cout << "----------" << endl;
	}
private:
	multimap<Date, string> db;
};

int main()
{
	CustomDataBase db;
	
	string command;
	while (true) 
	{
		cin >> command;
		try
		{
			if (command == "Add")
			{
				string date;
				cin >> date;
				string event;
				cin >> event;

				db.Add(strToDate(date), event);
			}
			else if (command == "Del")
			{
				string date;
				cin >> date;
				string event;
				cin >> event;

				if (event.size() > 0)
				{
					if (db.Del(strToDate(date), event))
					{
						cout << "Deleted successfully" << endl;
					}
					else
					{
						cout << "Event not found" << endl;
					}
				}
				else
				{
					cout << "Deleted " << db.Del(strToDate(date)) << " events" << endl;
				}
			}
			else if (command == "Find")
			{
				string date;
				cin >> date;
				for (const auto& str : db.Find(strToDate(date)))
				{
					cout << str << endl;
				}
			}
			else if (command == "Print")
			{
				db.Print();
			}
			else
			{
				stringstream ss;
				ss << "Unknown command: " << command;
				throw runtime_error(ss.str());
			}
		}
		catch (exception& ex)
		{
			cout << ex.what() << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
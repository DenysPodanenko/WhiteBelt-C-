#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cctype>
#include <iomanip>

using namespace std;

class Date {
public:
	void SetYear(int y)
	{
		year = y;
	}

	void SetMonth(int m)
	{
		month = m;
	}

	void SetDay(int d)
	{
		day = d;
	}

	int GetYear() const
	{
		return year;
	}

	int GetMonth() const
	{
		return month;
	}

	int GetDay() const
	{
		return day;
	}
private:
	int year;
	int month;
	int day;
};

Date castStringToDate(const string& strDate)
{
	Date date;
	vector<int> dateNums;
	string sTmp;
	for (int i = 0; i < strDate.size(); ++i)
	{
		if (strDate[i] == '-' || i == strDate.size() - 1)
		{
			dateNums.push_back(abs(stoi(sTmp)));
			sTmp.clear();
		}
		sTmp.push_back(strDate[i]);
	}
	date.SetYear(dateNums[0]);
	date.SetMonth(dateNums[1]);
	date.SetDay(dateNums[2]);

	return date;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	if (lhs.GetDay() == rhs.GetDay() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetYear() == rhs.GetYear())
	{
		return true;
	}
	return false;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() < rhs.GetYear())
	{
		return true;
	}
	else if (lhs.GetYear() > rhs.GetYear())
	{
		return false;
	}
	else if (lhs.GetMonth() < rhs.GetMonth())
	{
		return true;
	}
	else if (lhs.GetMonth() > rhs.GetMonth())
	{
		return false;
	}
	else if (lhs.GetDay() < rhs.GetDay())
	{
		return true;
	}
	else if (lhs.GetDay() > rhs.GetDay())
	{
		return false;
	}
	return false;
}

class Database {
public:
	void AddEvent(const Date& date, const string& _event)
	{
		events[date] = _event;
	}

	bool Del(const Date& date, const string& _event)
	{
		if (events.count(date) > 0 && _event == events.at(date))
		{
			for (auto it = events.begin(); it != events.end(); ++it)///вывод на экран
			{				
				if (it->first == date && it->second == _event)
				{
					events.erase(it);
				}
			}
			return true;
		}
		return false;
	}
	int Del(const Date& date)
	{
		int countEvent = 0;
		for (auto it = events.begin(); it != events.end(); ++it)///вывод на экран
		{
			if (it->first == date)
			{
				countEvent++;
			}
		}
		events.erase(date);
		return countEvent;
	}

	vector<string> Find(const Date& date) const
	{
		vector<string> answer;
		for (const auto& pair : events)
		{
			if (pair.first == date)
			{
				answer.push_back(pair.second);
			}
		}
		return answer;
	}

	void Print() const
	{
		for (const auto& pair : events)
		{
			cout << setfill('0') << setw(4) << pair.first.GetYear() << '-' << setfill('0') << setw(2) << pair.first.GetMonth() << '-' << setfill('0') << setw(2) << pair.first.GetDay() << " " << pair.second << endl;
		}
	}
private:
	map<Date, string> events;
};

int main() {
	Database db;
	
	string command;
	while (getline(cin, command)) {
		if (command == "Add")
		{
			string strDate;
			cin >> strDate;

			string eve;
			cin >> eve;

			db.AddEvent(castStringToDate(strDate), eve);
		}
		else if (command == "Del")
		{
			string strDate;
			cin >> strDate;
			char ch;
			cin >> ch;
			if (isspace(ch))
			{
				string eve;
				cin >> eve;

				if (db.Del(castStringToDate(strDate), eve))
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
				cout << "Deleted " << db.Del(castStringToDate(strDate)) << " events" << endl;
			}
		}
		else if (command == "Find")
		{
			string strDate;
			cin >> strDate;
			for (const auto& str : db.Find(castStringToDate(strDate)))
			{
				cout << str << endl;
			}
		}
		else if (command == "Print")
		{
			db.Print();
		}

	}

	return 0;
}
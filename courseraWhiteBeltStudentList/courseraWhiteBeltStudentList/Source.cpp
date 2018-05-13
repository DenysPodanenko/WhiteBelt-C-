#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Birthday
{
	int day;
	int month;
	int year;
};

struct Student
{
	string name;
	string secondName;
	Birthday birthday;
};

int main()
{
	int N = 0;
	cin >> N;
	vector<Student> students;
	for (int i = 0; i < N; ++i)
	{
		Student student;
		cin >> student.name;
		cin >> student.secondName;
		cin >> student.birthday.day;
		cin >> student.birthday.month;
		cin >> student.birthday.year;

		students.push_back(student);
	}

	int M = 0;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		string request;
		cin >> request;
		if (request == "name")
		{
			int num = 0;
			cin >> num;
			num--;
			if (num > students.size())
			{
				cout << "bad request" << endl;
				continue;
			}
			cout << students[num].name << " " << students[num].secondName << endl;
		}
		else if (request == "date")
		{
			int num = 0;
			cin >> num;
			num--;
			if (num > students.size())
			{
				cout << "bad request" << endl;
				continue;
			}
			cout << students[num].birthday.day << "." << students[num].birthday.month << "." << students[num].birthday.year << endl;
		}
		else
		{
			cout << "bad request" << endl;
		}
	}
	return 0;
}
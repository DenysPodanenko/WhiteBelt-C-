#include <iostream>
#include <string>

using namespace std;

struct Specialization
{
	string value;
	explicit Specialization(string newValue)
	{
		value = newValue;
	}
};

struct Course
{
	string value;
	explicit Course(string newValue)
	{
		value = newValue;
	}
};

struct Week
{
	string value;
	explicit Week(string newValue)
	{
		value = newValue;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(Specialization spec, Course cour, Week w)
	{
		specialization = spec.value;
		course = cour.value;
		week = w.value;
	}
};

int main()
{
	LectureTitle title(Specialization("C++"), Course("White belt"), Week("4th"));

	system("pause");
	return 0;
}
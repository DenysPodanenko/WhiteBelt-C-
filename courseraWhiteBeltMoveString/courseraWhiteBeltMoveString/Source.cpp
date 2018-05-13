#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveString(vector<string>& source, vector<string>& destination)
{
	for (auto s : source)
	{
		destination.push_back(s);
	}
	source.clear();
}

int main()
{
	vector<string> source = {"hi", "koko", "word", "shi"};

	for (auto s : source)
	{
		cout << s << " ";
	}

	cout << "\n";

	vector<string> dest = {"a", "b", "c", "d"};

	MoveString(source, dest);

	for (auto s : source)
	{
		cout << s << " ";
	}

	cout << "\n";

	for (auto s : dest)
	{
		cout << s << " ";
	}

	cout << "\n";

	system("pause");
	return 0;
}
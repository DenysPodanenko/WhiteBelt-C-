#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	string line;
	if (input)
	{
		while (getline(input, line))
		{
			cout << line << endl;
			output << line << endl;
		}
	}

	system("pause");
	return 0;
}
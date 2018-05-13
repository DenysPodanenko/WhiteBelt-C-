#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void main()
{
	ifstream input("input.txt");
	/*int N = 0;
	int M = 0;
	input >> N;
	input >> M;*/

	vector<vector<int>> table;
	for (int i = 0; i < 2; ++i)
	{
		vector<int> vec;
		for (int j = 0; j < 3; ++j)
		{
			string str;
			getline(input, str, ',');
			int a = atoi(str.c_str());
			vec.push_back(a);
		}
		table.push_back(vec);
	}



	system("pause");
}
#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& vec)
{
	for (int i = 0, j=vec.size()-1; i < vec.size()/2; ++i, --j)
	{
		int tmp = vec[i];
		vec[i] = vec[j];
		vec[j] = tmp;
	}
}

int main()
{
	vector<int> numbers = { 1, 5, 3, 4, 2,7 };
	Reverse(numbers);

	for (auto i : numbers)
	{
		cout << i << " ";
	}

	cout << endl;

	system("pause");
	return 0;
}
vector<int> Reversed(const vector<int>& v) 
{
	vector<int> revVec = v;
	for (int i = 0, j = revVec.size() - 1; i < revVec.size() / 2; ++i, --j)
	{
		int tmp = revVec[i];
		revVec[i] = revVec[j];
		revVec[j] = tmp;
	}

	return revVec;
}
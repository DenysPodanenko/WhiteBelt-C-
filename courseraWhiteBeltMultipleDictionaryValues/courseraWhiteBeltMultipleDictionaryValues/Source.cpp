set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> answer;
	for (const auto& couple : m)
	{
		answer.insert(couple.second);
	}

	return answer;
}
class SortedStrings {
public:
	void AddString(const string& s) {
		strings.push_back(s);
	}
	vector<string> GetSortedStrings() {
		vector<string> sortedStrings = strings;
		sort(sortedStrings.begin(), sortedStrings.end());
		return sortedStrings;
	}
private:
	vector<string> strings;
};
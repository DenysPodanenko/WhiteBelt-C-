class ReversibleString
{
private:
	string str;

public:
	ReversibleString()
	{
		str = "";
	}
	ReversibleString(const string& s)
	{
		str = s;
	}

	void Reverse()
	{
		for (int i = 0, j = str.size()-1; i < str.size()/2; ++i, --j)
		{
			char tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
		}
	}

	string ToString() const
	{
		return str;
	}
};
#include <iostream>
#include <sstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int gcd(int a, int b) {

	if (a == b) {
		return a;
	}
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	return gcd(a, b - a);
}

int lcm(int p, int q)
{
	return p*q / gcd(p, q);
}

class Rational {
public:
	Rational()
	{
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator)
	{
		if (numerator == 0)
		{
			p = numerator;
			q = 1;
		}
		else if (numerator % denominator == 0)
		{
			cout << "The invariant of irreducibility is violated" << endl;
		}
		else
		{
			bool positive = false;
			if (numerator > 0 && denominator > 0)
			{
				positive = true;
			}
			else if (numerator < 0 && denominator < 0)
			{
				positive = true;
			}
			else
			{
				positive = false;
			}

			p = abs(numerator) / gcd(abs(numerator), abs(denominator));
			q = abs(denominator) / gcd(abs(numerator), abs(denominator));

			if (!positive)
			{
				p *= -1;
			}
		}
	}

	int Numerator() const
	{
		return p;
	}

	int Denominator() const
	{
		return q;
	}

	Rational operator = (const Rational rational)
	{
		return Rational(rational.Numerator(), rational.Denominator());
	}

private:
	int p;
	int q;
};

bool operator==(const Rational& lhs, const Rational& rhs)
{
	if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
	{
		return true;
	}
	else
	{
		return false;
	}
}

Rational operator+(const Rational& lhs,const Rational& rhs)
{
	if (lhs.Denominator() == rhs.Denominator())
	{
		return Rational(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
	}
	else 
	{

		int p = lhs.Numerator()*(lcm(lhs.Denominator(), rhs.Denominator())/lhs.Denominator()) + rhs.Numerator()*(lcm(lhs.Denominator(), rhs.Denominator())/rhs.Denominator());
		int q = lhs.Denominator()*(lcm(lhs.Denominator(), rhs.Denominator())/lhs.Denominator());

		return Rational(p / gcd(abs(p), q), q / gcd(abs(p), q));
	}
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	if (lhs.Denominator() == rhs.Denominator())
	{
		return Rational(lhs.Numerator() - rhs.Numerator(), lhs.Denominator());
	}
	else
	{
		int p = lhs.Numerator()*(lcm(lhs.Denominator(), rhs.Denominator())/lhs.Denominator()) - rhs.Numerator()*(lcm(lhs.Denominator(), rhs.Denominator())/rhs.Denominator());
		int q = lhs.Denominator()*(lcm(lhs.Denominator(), rhs.Denominator())/lhs.Denominator());

		return Rational(p / gcd(abs(p), q), q / gcd(abs(p), q));
	}
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
}

istream& operator >> (istream& stream, Rational& rational)
{
	if (stream.good())
	{
		int p = 0;
		int q = 0;
		stream >> p;
		stream.ignore(1);
		stream >> q;

		rational = Rational(p, q);
	}
	return stream;
}

ostream& operator<<(ostream& stream, const Rational& rational)
{
	stream << rational.Numerator() << "/" << rational.Denominator();
	return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
	if (lhs.Denominator() == rhs.Denominator())
	{
		return lhs.Numerator() < rhs.Numerator();
	}
	else if (lhs.Numerator() == rhs.Numerator())
	{
		if (lhs.Denominator() < rhs.Denominator())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return lhs.Numerator()*(lhs.Denominator() / lcm(lhs.Denominator(), rhs.Denominator())) < 
			rhs.Numerator()*(rhs.Denominator() / lcm(lhs.Denominator(), rhs.Denominator()));
	}
}

int main() {
	{
		const set<Rational> rs = { { 1, 2 },{ 1, 25 },{ 3, 4 },{ 3, 4 },{ 1, 2 } };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			system("pause");
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			system("pause");
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			system("pause");
			return 3;
		}
	}

	cout << "OK" << endl;
	system("pause");
	return 0;
}
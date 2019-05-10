#include "fraction.h"

namespace math_custom {

	fraction::fraction(long double n, long double d)
	{
		while (fmod(n, 10) != 0 && fmod(d, 10) != 0) {
			n *= 10;
			d *= 10;
		}

		if (fmod(n, 10) == 0 && fmod(d, 10) == 0) {
			n /= 10;
			d /= 10;
		}

		numerator(n);
		denominator(d);
	}

	//unary operator overloads
	fraction& fraction::operator++()
	{
		*this += 1;
		return *this;
	}

	fraction fraction::operator++(int)
	{
		fraction temp = *this;
		*this += 1;
		return temp;
	}

	fraction& fraction::operator--()
	{
		*this -= 1;
		return *this;
	}

	fraction fraction::operator--(int)
	{
		fraction temp = *this;
		*this -= 1;
		return temp;
	}

	//fraction operator assignment overloads//
	fraction& fraction::operator+=(const fraction &other) {
		*this = *this + other;
		return *this;
	}

	fraction& fraction::operator-=(const fraction &other) {
		*this = *this - other;
		return *this;
	}

	fraction& fraction::operator/=(const fraction &other) {
		*this = *this / other;
		return *this;
	}

	fraction& fraction::operator*=(const fraction &other) {
		*this = *this * other;
		return *this;
	}

	//relational operators//
	bool fraction::operator>(const fraction &other) const
	{
		return ((double)this->get_simplify() > (double)other.get_simplify());
	}

	bool fraction::operator<(const fraction &other) const
	{
		return ((double)this->get_simplify() < (double)other.get_simplify());
	}

	bool fraction::operator>=(const fraction &other) const
	{
		return ((double)this->get_simplify() >= (double)other.get_simplify());
	}

	bool fraction::operator<=(const fraction &other) const
	{
		return ((double)this->get_simplify() <= (double)other.get_simplify());
	}

	bool fraction::operator==(const fraction &other) const {
		return ((double)this->get_simplify() == (double)other.get_simplify());
	}

	bool fraction::operator!=(const fraction &other) const {
		return ((double)this->get_simplify() != (double)other.get_simplify());
	}

	//cast operators//
	fraction::operator double() {
		return static_cast<double>(nr / dr);
	}

	fraction::operator float() {
		return static_cast<float>(nr / dr);
	}

	fraction::operator int() {
		return static_cast<int>(nr / dr);
	}

	//public accessors//
	long double fraction::numerator() const {
		return nr;
	}

	long double fraction::denominator() const {
		return dr;
	}

	void fraction::numerator(const long double& n)
	{
		nr = n;
		if (nr == 0) dr = 1;
	}

	void fraction::denominator(const long double& d)
	{
		if (d != 0) {
			if (nr == 0) dr = 1;
			else {
				dr = d;	
				if (d < 0) {
					dr *= -1;
					nr *= -1;
				}
			}
		}
		else {
			throw std::invalid_argument("demonimator cannot be zero(0)");
		}
	}

	//functions//
	fraction fraction::get_reciprocal()const {
		return (fraction(dr, nr));
	}

	void fraction::reciprocal() {
		*this = get_reciprocal();
	}

	long double fraction::gcd(const long double& x, const long double& y)
	{
		long double divisor = x < y ? x : y;
		long double divident = x > y ? x : y;
		long double remainder = 1; //dummy remainder

		while (remainder) {
			remainder = fmod(divident, divisor);
			divident = divisor;
			if (remainder) divisor = remainder;
		}
		return divisor;
	}

	//long double fraction::lcm(std::initializer_list<fraction> fracs)
	//{
	//    std::vector<long double> denoms;
	//    for (auto i : fracs) {
	//        denoms.push_back(i.denominator());
	//    }
	//}

	fraction fraction::get_simplify() const
	{
		if (nr != 0) {
			long double divisor = gcd(nr, dr);
			long double num = nr / divisor;
			long double denom = dr / divisor;
			return fraction(num, denom);
		}
		return fraction(0, 1);
	}


	const fraction& fraction::simplify() {
		*this = get_simplify();
		return *this;
	}

	//global operator overloads//
	std::ostream& operator<<(std::ostream &out, const fraction &frac)
	{
		if (frac.denominator() == 1.0l || frac.numerator() == 0.0l) {
			out << frac.numerator();
		}
		else {
			out << frac.numerator() << "/" << frac.denominator();
		}
		return out;
	}



	fraction operator+(const fraction & f1, const fraction & f2)
	{
		fraction temp;
		if (f1.denominator() == f2.denominator()) {
			temp.numerator(f1.numerator() + f2.numerator());
			temp.denominator(f1.denominator());
		}
		else {
			temp.numerator(f1.numerator() * f2.denominator() + f1.denominator() * f2.numerator());
			temp.denominator(f1.denominator() * f2.denominator());
		}
		return temp;
	}

	fraction operator-(const fraction & f1, const fraction & f2)
	{
		fraction temp;
		if (f1.denominator() == f2.denominator()) {
			temp.numerator(f1.numerator() - f2.numerator());
			temp.denominator(f1.denominator());
		}
		else {
			temp.numerator(f1.numerator() * f2.denominator() - f1.denominator() * f2.numerator());
			temp.denominator(f1.denominator() * f2.denominator());
		}
		return temp;
	}

	fraction operator/(const fraction & f1, const fraction & f2)
	{
		fraction temp;
		temp.numerator(f1.numerator() * f2.denominator());
		temp.denominator(f1.denominator() * f2.numerator());
		return temp;
	}

	fraction operator*(const fraction & f1, const fraction & f2)
	{
		fraction temp;
		temp.numerator(f1.numerator() * f2.numerator());
		temp.denominator(f1.denominator() * f2.denominator());
		return temp;
	}

	fraction operator+(const long double& number, const fraction & frac)
	{
		return fraction(number, 1) + frac;
	}

	fraction operator+(const fraction& frac, const long double& number)
	{
		return fraction(number, 1) + frac;
	}

	fraction operator-(const long double & number, const fraction & frac)
	{
		return  fraction(number, 1) - frac;
	}

}





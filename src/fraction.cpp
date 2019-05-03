#include "fraction.h"
namespace math_custom {
	/////////////////
	//Constructors//
	///////////////
	fraction::fraction()noexcept:nr(0), dr(1.0l) {}

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

		set_numerator(n);
		set_denominator(d);
	}

	////////////////////////////////
	//fraction operator overloads//
	//////////////////////////////
	fraction fraction::operator+(const fraction &other) const
	{
		fraction temp;
		if (dr == other.dr) {
			temp.set_numerator(nr + other.nr);
			temp.set_denominator(dr);
		}
		else {
			temp.set_numerator(nr * other.dr + dr * other.nr);
			temp.set_denominator(dr * other.dr);
		}
		return temp;
	}

	fraction fraction::operator-(const fraction &other) const
	{
		fraction temp;
		if (dr == other.dr) {
			temp.set_numerator(nr - other.nr);
			temp.set_denominator(dr);
		}
		else {
			temp.nr = nr * other.dr - dr * other.nr;
			temp.dr = dr * other.dr;
		}
		return temp;
	}

	fraction fraction::operator/(const fraction &other) const {
		fraction temp;
		temp.set_numerator(nr * other.dr);
		temp.set_denominator(dr * other.nr);
		return temp;
	}

	fraction fraction::operator*(const fraction &other) const {
		fraction temp;
		temp.set_numerator(nr * other.nr);
		temp.set_denominator(dr * other.dr);
		return temp;
	}

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

	///////////////////////////////////////////
	//fraction operator assignment overloads//
	/////////////////////////////////////////
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

	/////////////////////////
	//relational operators//
	///////////////////////
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

	///////////////////
	//cast operators//
	/////////////////
	fraction::operator double() {
		return static_cast<double>(nr / dr);
	}

	fraction::operator float() {
		return static_cast<float>(nr / dr);
	}

	fraction::operator int() {
		return static_cast<int>(nr / dr);
	}


	/////////////////////
	//public accessors//
	///////////////////
	long double fraction::get_numerator() const {
		return nr;
	}

	long double fraction::get_denominator() const {
		return dr;
	}

	void fraction::set_numerator(const long double& n)
	{
		nr = n;
		if (nr == 0) dr = 1;
	}

	void fraction::set_denominator(const long double& d)
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


	//////////////
	//functions//
	////////////
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
	//        denoms.push_back(i.get_denominator());
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

	//////////////////////////////
	//global operator overloads//
	////////////////////////////
	std::ostream& operator<<(std::ostream &out, const fraction &frac)
	{
		if (frac.get_denominator() == 1.0l || frac.get_numerator() == 0.0l) {
			out << frac.get_numerator();
		}
		else {
			out << frac.get_numerator() << "/" << frac.get_denominator();
		}
		return out;
	}

}





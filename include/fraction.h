#pragma once
#include<ostream>		// ostream operator<< overload
#include <stdexcept>	//std::invalid_argument()
#include <cmath>		// fmod()
#include <vector> 

namespace math_custom {
	class fraction
	{
	private:
		long double nr;
		long double dr;

		//    fraction nf;
		//    fraction df;

	public:
		fraction()noexcept;

		template <class number_t>
		fraction(const number_t& n) {
			*this = fraction(n, 1).get_simplify();
		}

		fraction(long double n, long double d);

		//binary operators
		fraction operator+(const fraction& other)const;
		fraction operator-(const fraction& other)const;
		fraction operator/(const fraction& other)const;
		fraction operator*(const fraction& other)const;

		//unary operators
		fraction& operator++();
		fraction operator++(int);//postfix
		fraction& operator--();
		fraction operator--(int);//postfix

		//assignment or short hand operators
		fraction& operator+=(const fraction& other);
		fraction& operator-=(const fraction& other);
		fraction& operator/=(const fraction& other);
		fraction& operator*=(const fraction& other);

		//relational operators
		bool operator>(const fraction& other)const;
		bool operator<(const fraction& other)const;
		bool operator>=(const fraction& other)const;
		bool operator<=(const fraction& other)const;
		bool operator==(const fraction& other)const;
		bool operator!=(const fraction& other)const;

		//casting operators
		operator int();
		operator float();
		operator double();

		//functions
		fraction get_reciprocal()const;
		void reciprocal();
		static long double gcd(const long double& x, const long double& y);

		//    static long double lcm(std::initializer_list<fraction> fracs);
		fraction get_simplify()const;
		const fraction& simplify();


		//public accessors
		long double get_nr()const;
		long double get_dr()const;
		void set_nr(const long double& n);
		void set_dr(const long double& d);


		//defaults for the big 5
		fraction(const fraction& other) = default;
		fraction& operator=(const fraction& other) = default;
		fraction(fraction&& other) = default;
		fraction& operator=(fraction&& other) = default;
		virtual ~fraction() = default;
	};

	//global overloads
	std::ostream& operator<<(std::ostream &out, const fraction &frac);


	template<class number_t>
	fraction operator+(const number_t& number, const fraction& frac) {
		return fraction(number, 1) + frac;
	}

	template<class number_t>
	fraction operator+(const fraction& frac, const number_t& number) {
		return fraction(number, 1) + frac;
	}

	template<class number_t>
	fraction operator-(const number_t& number, const fraction &frac) {
		return  fraction(number, 1) - frac;
	}

	template<class number_t>
	fraction operator-(const fraction &frac, const number_t& number) {
		return frac - fraction(number, 1);
	}

	template<class number_t>
	fraction operator*(const number_t& number, const fraction &frac) {
		return fraction(number, 1) * frac;
	}

	template<class number_t>
	fraction operator*(const fraction &frac, const number_t& number) {
		return fraction(number, 1) * frac;
	}

	template<class number_t>
	fraction operator/(const number_t& number, const fraction &frac) {
		return fraction(number, 1) / frac;
	}

	template<class number_t>
	fraction operator/(const fraction &frac, const number_t& number) {
		return frac / fraction(number, 1);
	}

}
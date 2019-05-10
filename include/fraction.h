#pragma once
#include<iostream>		// ostream operator<< overload
#include <stdexcept>	//std::invalid_argument()
#include <cmath>		// fmod()
#include <vector> 
#include <string>
#include <initializer_list>

namespace math_custom {
	class fraction
	{
	private:
		long double nr;
		long double dr;

	public:
		fraction(long double n = 0, long double d = 1);

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
		explicit operator int();
		explicit operator float();
		explicit operator double();

		//functions
		fraction get_reciprocal()const;
		void reciprocal();
		static long double gcd(const long double& x, const long double& y);

		//static long double lcm(std::initializer_list<fraction> fracs);
		fraction get_simplify()const;
		const fraction& simplify();

		//public accessors
		long double numerator()const;
		long double denominator()const;
		void numerator(const long double& n);
		void denominator(const long double& d);


		//defaults for the big 5
		fraction(const fraction& other) = default;
		fraction& operator=(const fraction& other) = default;
		fraction(fraction&& other) = default;
		fraction& operator=(fraction&& other) = default;
		virtual ~fraction() = default;
	};

	//global overloads
	std::ostream& operator<<(std::ostream &out, const fraction &frac);

	fraction operator+(const fraction& f1, const fraction& f2);
	fraction operator-(const fraction& f1, const fraction& f2);
	fraction operator/(const fraction& f1, const fraction& f2);
	fraction operator*(const fraction& f1, const fraction& f2);
}

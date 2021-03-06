#include <iostream>
#include <string>
#include <typeinfo>

#include "fraction.h"

using namespace std;
using namespace math_custom;
using fr = fraction;

class Matrix final:public fr{
public:
	Matrix() :fraction() {}

	template<class T>
	Matrix(const T& n) :fraction(n) {}
	Matrix(long double n, long double d) :fraction(n, d) {}
	~Matrix() {
		std::cout << *this << " matrix destroyed \n";
	}
};



class test_frac{
public:
    static void addition(){
		//fr x(1,2);
		//x.denominator(3);
		//x.numerator(-5);
		
		fr x = 1 + fr(1, 2);

        cout << x.simplify() << "\n";
    }

    static void subtraction(){
        fr x = 0 - fr(1,2) - 1;
        cout << x << "\n";
    }

    static void multiplication(){
        fr x = -0.1 * fr{1,2};
        cout << x << "\n";
    }

    static void division(){
        fr x = fr(1,2) / 0;
        cout << x << "\n";
    }

    static void the_big_five(){
		//fr x(fr(1,0.1)); //copy ctor
		//fr y = x; //copy assignment
		//fr a = std::move(y); // move ctor
		//a = std::move(y); // move assignment

		std::unique_ptr<fr> z = make_unique<Matrix>(Matrix(1, 2));
        cout << *z << "\n";
    }


    static void copy_assignment(){
        fr x = fr{8,12};
        fr y{1,0};
        y = x;
        cout << y << "\n";
    }

    static void misc(){
        fr x(1.5,3);
        cout << x << "\n";
        cout << (double)x << "\n";
        fr y(x);
        cout << y << "\n";
        cout << y.simplify() << " \n";
    }

    static void gcd(){
        fr x;
        cout << x.gcd(27,33);
    }

    static void ast(){
//        fr x = "1/2+1/2*1/2";
    }

	static void shorthand_and_unary() {
		fr y(1, 2);
		y = y++;
		fr x = 1.1;
		cout << y << "\n";
	}
};






int main() {
	//cout << (fr(999.234, 5656.123) > fr(999.234, 5656.123));
	test_frac::addition();
	//test_frac::subtraction();
	//test_frac::multiplication();
	//test_frac::division();
	//test_frac::the_big_five();
	//test_frac::copy_assignment();
	//test_frac::misc();
	//test_frac::gcd();
	//test_frac::shorthand_and_unary();
	
	
	std::cin.get();
    return 0;
}

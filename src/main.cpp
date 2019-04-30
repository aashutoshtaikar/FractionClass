#include <iostream>
#include "fraction.h"

using namespace std;
using fr = fraction;

class Matrix final:public fr{
public:
	Matrix() :fraction() {}
	Matrix(long double n, long double d) :fraction(n, d) {}
	~Matrix() {
		std::cout << *this << " dummy destroyed \n";
	}
};

class test_fractions{
public:
    static void addition(){
        fr r = (2/2);
        fr x = 1 + fr(-1,2) + fr(1,2);
        fr a(2,2);

        try {
            a /= fr(0,1);
            a.simplify();
        } catch (std::exception& e) {
            cerr << e.what() << "caught\n";
        }

        cout << x << "\n";

    }

    static void subtraction(){
        fr x = fr(1,2) - fr(1,2);
        cout << x << "\n";
    }

    static void multiplication(){
        fr x = fr{1,2} * fr{1,2};
        cout << x << "\n";
    }

    static void division(){
        fr x = fr{1,2} / fr{1,2};
        cout << x << "\n";
    }

    static void the_big_five(){
		/*fr x(fr(1,0.1)); //copy ctor
		fr y = x; //copy assignment
		fr a = std::move(y); // move ctor
		fr a = std::move(y); // move assignment
*/
		std::unique_ptr<fr> z = make_unique<Matrix>(Matrix(1, 2));
        cout << *z << "\n";
    }

    static void simplify(){
        fr x = fr{8,12};
        cout << x << "\n";
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
        fr y((double)x);
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
};


int main() {

    test_fractions::addition();
//       test_fractions::subtraction();
//     test_fractions::multiplication();
//     test_fractions::division();
     //test_fractions::the_big_five();
//    test_fractions::copy_assignment();
//    test_fractions::misc();
//       test_fractions::gcd();
	std::cin.get();
    return 0;
}

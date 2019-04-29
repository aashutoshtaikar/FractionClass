#include <iostream>
#include <sstream>
#include <math.h>
#include <assert.h>
#include <limits>
#include "fraction.h"
using namespace std;
typedef fraction fr;

class test_fractions{
public:
    static void addition(){
        // (1/(2+(4)) / (9/8)
        // x (y/z)
        // to decimal
        //
        fr r = 0;
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

    static void copy_ctor(){
        fr x(fr(1,0.1));
        cout << x << "\n";
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
//     test_fractions::copy_ctor();
//    test_fractions::copy_assignment();
//    test_fractions::misc();
//       test_fractions::gcd();

    return 0;
}

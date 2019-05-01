#include "fraction.h"
/////////////////
//Constructors//
///////////////
fraction::fraction()noexcept:nr(0),dr(1ll){}

fraction::fraction(double n, double d) 
{
    while(fmod(n,10)!=0 && fmod(d,10)!=0){
        n *= 10;
        d *= 10;
    }

    if(fmod(n,10)==0 && fmod(d,10)==0){
        n/=10;
        d/=10;
    }

    int sign = 1;
    if(d<0){
        sign *= -1;
        d *= -1;
    }
    if(n<0){
        sign *= -1;
        n *= -1;
    }
   
	set_dr(d);
	set_nr(n*sign);

}

////////////////////////////////
//fraction operator overloads//
//////////////////////////////
fraction fraction::operator+(const fraction &other) const
{
    fraction temp;
    if(dr==other.dr){
        temp.set_nr(nr + other.nr);
        temp.set_dr(dr);
    }
    else{
        temp.set_nr(nr * other.dr + dr * other.nr);
        temp.set_dr(dr * other.dr);
    }
    return temp;
}

fraction fraction::operator-(const fraction &other) const
{
    fraction temp;
    if(dr==other.dr){
        temp.set_nr(nr - other.nr);
        temp.set_dr(dr);
    }
    else{
        temp.nr = nr * other.dr - dr * other.nr;
        temp.dr = dr * other.dr;
    }
    return temp;
}

fraction fraction::operator/(const fraction &other) const{
    fraction temp;
    temp.set_nr(nr * other.dr);
    temp.set_dr(dr * other.nr);
    return temp;
}

fraction fraction::operator*(const fraction &other) const{
    fraction temp;
    temp.set_nr(nr * other.nr);
    temp.set_dr(dr * other.dr);
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
fraction& fraction::operator+=(const fraction &other){
    *this = *this + other;
    return *this;
}

fraction& fraction::operator-=(const fraction &other){
    *this = *this - other;
    return *this;
}

fraction& fraction::operator/=(const fraction &other){
    *this = *this/other;
    return *this;
}

fraction& fraction::operator*=(const fraction &other){
   *this = *this*other;
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

bool fraction::operator==(const fraction &other) const{
    return ((double)this->get_simplify() == (double)other.get_simplify());
}

bool fraction::operator!=(const fraction &other) const{
    return ((double)this->get_simplify() != (double)other.get_simplify());
}

///////////////////
//cast operators//
/////////////////
fraction::operator double(){
    return (double)nr/dr;
}

fraction::operator float(){
    return (float)nr/dr;
}

fraction::operator int(){
    return (int)nr/dr;
}


/////////////////////
//public accessors//
///////////////////
long long fraction::get_nr() const{
    return nr;
}

long long fraction::get_dr() const{
    return dr;
}

void fraction::set_nr(const long long& n)
{
   nr = n;
   if(nr==0) set_dr(1);
}

void fraction::set_dr(const long long& d)
{
    if(d!=0) dr = d;
    else{
        throw std::invalid_argument("demonimator cannot be zero(0)");
    }
}


//////////////
//functions//
////////////
fraction fraction::get_reciprocal()const{
	return (fraction(dr, nr));
}

void fraction::reciprocal(){
	*this = get_reciprocal();
}

long long fraction::gcd(const long long& x,const long long& y)
{
    long long divisor = x<y?x:y;
    long long divident = x>y?x:y;
    long long remainder = 1; //dummy remainder

    while(remainder){
        remainder = fmod(divident,divisor);
        divident = divisor;
        if (remainder) divisor = remainder;
    }
    return divisor;
}

std::vector<long long> fraction::get_prime_factors(long long n)
{
	std::vector<long long> prime_factors;
	
	//for no of 2s that divide n
	while (n % 2 == 0) {
		prime_factors.push_back(2);
		n = n / 2;
	}

	//for all odd prime factors
	for (long long i = 3; i <= sqrt(n); i = i+2)
	{
		while (n % i == 0) {
			prime_factors.push_back(i);
			n = n / i;
		}
	}

	//if n is a prime no. greater than 2
	if (n > 2) {
		prime_factors.push_back(n);
	}

	return prime_factors;
}

std::vector<long long> fraction::lcm(std::initializer_list<fraction> fracs)
{
    std::vector<long long> denominators;
    for (auto fr : fracs) {
		denominators.push_back(fr.get_dr());
    }

	std::map<long long, std::vector<int>> primefac_count;
	

	for (int i=0 ;i<denominators.size();i++)
	{
		std::vector<long long> prime_factors = get_prime_factors(denominators[i]);
	
		std::vector<long long> temp;
		temp.push_back(0ll);
		for (const auto& factor : prime_factors) {
			std::cout << i << " "<<temp[i] << "\n";
			primefac_count.insert(std::make_pair(factor,++temp[i]));
		}
	}

	std::vector<long long> lcm;
	for (const auto& primefac : primefac_count )
	{
		std::vector<int> temp = primefac.second;
		std::sort(temp.begin(), temp.end(), [](int i, int j) { return i > j; });

		int it = temp[0];
		for (int i = 0; i <it ; i++)
		{
			lcm.push_back(primefac.first);
		}
	}

	return lcm;
}

fraction fraction::get_simplify() const
{
    if(nr!=0ll){
        long long divisor = gcd(nr,dr);
        long long num = nr/divisor;
        long long denom = dr/divisor;
        return fraction(num,denom);
    }
    return fraction(0,1);
}


const fraction& fraction::simplify()
{
    *this = get_simplify();
    return *this;
}

//////////////////////////////
//global operator overloads//
////////////////////////////
std::ostream& operator<<(std::ostream &out, const fraction &frac)
{
    if(frac.get_dr()==1ll || frac.get_nr()==0ll){
        out << frac.get_nr();
    }
    else{
        out << frac.get_nr() <<"/"<< frac.get_dr();
    }
    return out;
}






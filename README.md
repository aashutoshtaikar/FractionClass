# A Fraction class  

## Building  
(cmake minimum v2.8 required)
### Windows (cmake and VC++/minGW) 
Open Visual Studio    
File > Open > CMake > (browse to the dir and select CMakeLists.txt file)  

### Linux (cmake and gcc/clang)  
mkdir build && cd build && cmake ../ && make  

### Overview  
1. Accepts a long double
2. Removes the decimal points
3. User has a simplify option to reduce it to simplest form
4. (WIP) User can make the denominator common using LCM method     


### functions:
#### operators:  
addition +  
subtraction -  
multiplication *  
division /  

#### relational operators:  
greater than > , greater than or equal >=  
less than < , less than or equal <=  
is_equal ==  
not equal !=  

#### casting operators:  
casts to integer (int)  
casts to float (float)  
casts to double (double)  

#### other functions:  


##### this modifiers:  
simplify  
reciprocal  

##### static helper functions:  
gcd   
lcm (WIP)

### WIP
AST for string input   
Mixed fractions display  
GCD (handle multiples using initializer list / var template)  
LCM (handle multiples using initializer list / var template)  
 
 


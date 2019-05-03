# A Fraction class  

### To build on Windows (cmake minimum v2.8 with ninja and MSVC/minGW)   

1. In Visual Studio 2017 goto File > Open > CMake > (browse to the dir and select CMakeLists.txt file)   
2. Keep the same CMakeSettings.json if you wish to keep everything organized under one folder bin/  
OR  
2. Configurations(toolbar x64-Debug) > Manage Configurations > generates CMakeSettings.json   
https://docs.microsoft.com/en-us/cpp/build/customize-cmake-settings?view=vs-2019  
 
    

### Building on Linux (cmake minimum v2.8 and gcc/clang)    
Navigate to the cloned repository directory  
rm -rfd build && mkdir build && cd build && cmake ../ && make  

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
 
 


// initializerlists.cpp
// Ólafur Aron Jóhannsson

#include <iostream>
#include <vector>
#include <list>
#include <string>


// C++11 new features
// Template alias



/*
    Create own types

*/
 template<int>
 struct int_exact_traits { typedef int type; };

 template<>
 struct int_exact_traits<8> { typedef char type; };

 template<>
 struct int_exact_traits<16> { typedef char type[2]; };

template<>
struct int_exact_traits<24> { typedef char type[3]; };

template<int N>
using int_exact = typename int_exact_traits<N>::type;



int main() {
    std::cout << sizeof(int_exact<8>) << std::endl;  // 1 byte
    std::cout << sizeof(int_exact<16>) << std::endl; // 2 bytes
    std::cout << sizeof(int_exact<24>) << std::endl; // 3 bytes
    std::cout << sizeof(int) << std::endl;           // 4 bytes

    return 0;
}


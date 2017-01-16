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


// create templated pointer
template<class T>
using ptr = T*;


template<class T>
using mystring = std::basic_string<T, std::char_traits<T>>;
using characters = mystring<char>;
/*
    Similar to typedef, instead of writing 
        int_exact_traits<8>::type we write int_exact<8>
*/
template<int N>
using int_exact = typename int_exact_traits<N>::type;

void func_ptr(int, int) {}

int main() {
    std::cout << sizeof(int_exact<8>) << std::endl;  // 1 byte
    std::cout << sizeof(int_exact<16>) << std::endl; // 2 bytes
    std::cout << sizeof(int_exact<24>) << std::endl; // 3 bytes
    std::cout << sizeof(int) << std::endl;           // 4 bytes


    ptr<int> x;
    int* x2;

    characters chars = "asdf";
    std::cout << chars << std::endl;

    // alias away template param
    

    // type alias
    using flags = std::ios_base::fmtflags;
    flags fl = std::ios_base::dec;


    // func ptrs
    using func1 = void(*) (int, int); // same as below
    typedef void (*func2)(int, int);
    // same thing
    func1 f1 = func_ptr;
    func2 f2 = func_ptr;


    typedef void (*PDF)(double);
    using PF = void(*)(double);
    //using P = [](double)->void;

    return 0;
}



#include <string>
#include <iostream>
#include <type_traits>
#include <memory>
#include <cxxabi.h>
// is T is a fundamental type (arithmetic type, void or nullptr_t)

    template<class T>
typename std::enable_if<std::is_fundamental<T>::value, std::string>::type stringify(const T& t)
{
    std::cout << "1\n";
    return std::to_string(t);
}

    template<class T>
typename std::enable_if<!std::is_fundamental<T>::value, std::string>::type stringify(const T& t)
{
    std::cout << "2\n";
    return std::to_string(t);
}

template<typename T>
struct is_ptr { static const bool value = false; };
template<typename T>
struct is_ptr<T*> { static const bool value = true; };

template <typename T> std::string type_name()
{
    typedef typename std::remove_reference<T>::type TR;

    std::unique_ptr<char, void(*)(void*)> own
        (

        );
}
namespace t
{
    int test()
    {
        std::cout << __func__ << std::endl;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::cout << __FUNCTION__ << std::endl;
        std::cout << stringify(3.0f) << std::endl;
        std::cout << stringify(false) << std::endl;
        int i;
        typedef decltype(i) i_type;
    }
}

int main()
{
    t::test();
}


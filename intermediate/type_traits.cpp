
#include <string>
#include <iostream>
#include <type_traits>
#include <memory>
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

template <typename T, typename A1>
std::unique_ptr<T> factory(A1&& a1)
{
    return std::unique_ptr<T>(std::forward<T>(new T(a1)));
}
void test() {}
int main()
{
    std::cout << stringify(3.0f) << std::endl;
    std::cout << stringify(false) << std::endl;


}


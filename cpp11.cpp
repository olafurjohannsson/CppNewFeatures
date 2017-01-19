
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

void lambda();

int main() 
{

    lambda();
    return 0;
}

void lambda()
{
    auto cntr = [] (std::string c) -> uint32_t {
        uint32_t cntr = 0;
        for (; cntr < c.size(); cntr )
            ;
        return cntr;
    };

    std::cout << "cntr: " << cntr("test") << '\n';

    char s[] = "HerRo";
    int total_uppercase = 0;
    std::for_each(s, s + sizeof(s), [&total_uppercase] (char c) {
        if (std::isupper(c))
        {
            total_uppercase++;
        }
    });
    //std::map
    std::cout << "upper: " << total_uppercase << '\n';
}
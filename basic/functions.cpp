
#include <iostream>

/*
 * Functions
 * A function definition consists of a header and body. 
 * A function is said to return a value if the return type of said function has a specific data type. If the function computes it's value without return, it's said to return void, it simply being a "void" function.
 * A function has a name and an optional argument list, which constitute the function signature.
 * Parameters are inputs into the function, when a function is invoked you pass a value to a function, in the form of a parameter, which acts as a placeholder. 
 * The function body of a function is the collection of statements and expression that make of what the function does.
 */

int getFourtyTwo()
{
 return 42;
}

int doubleMe(int value)
{
    return value + value;
}

void addToMe(int &val, int add)
{
    val += add;
}
void printMe(int value)
{
    std::cout << value << std::endl;
}
bool isPositive(int value)
{
    return value > 0;
}
// call by value (value is copied to the arg in the function list)
// call by poirnter (copy address of arg into param of function)
// call by reference

int main()
{
    int value;

    value = getFourtyTwo();
    
    addToMe(value, 2);
    printMe(value);
    
    printMe(doubleMe(value));
    
    
    // vlaue
    int x = 0;

}


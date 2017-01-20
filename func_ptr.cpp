
#include <iostream>
#include <string>


void func1(int var)
{
    std::cout << var << '\n';
}

static void func2(int var)
{
    std::cout << var << '\n';
}

void my_func(int (*cb)(void*), void *param)
{
    std::cout << cb(param) << '\n';
}

int my_cb(void *param)
{
    int *p = (int*)param;
    return *p;
}

double cb_1(double p)
{
    std::cout << "p * 2\n";
    return p*p;
}
double cb_2(double p)
{
    std::cout << "p + 2\n";
    return p + p;
}
double (*my_dbl(int idx))(double)
{
    if (idx==0)
        return cb_1;
    return cb_2;

}

int main() 
{

    // as a variable
    void (*var1)(int) = func1;
    var1(1);

    // as a static const var
    static void (*const var2)(int) = func2;
    var2(2);

    // as an array
    void (*arr1[])(int) = { func1, func2 };
    arr1[1](2);

    // as an arg to a func
    int p = 2;
    my_func(my_cb, (void*)&p); 


    // as a ret value from a func
    double (*fnc)(double) = my_dbl(0);
    fnc(5);
    
    return 0;
}

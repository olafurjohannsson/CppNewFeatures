#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
void log(const std::string &message)
{
    std::cout << message << std::endl;
}

template<class T>
class vectr
{
public:
    vectr() 
    {
        this->size = 2;
        this->container = new T[this->size];
        this->current_index = -1;
    }
    ~vectr()
    {
        delete[] this->container;
    }
    void resize()
    {
        if (this->size - 1 == this->current_index) {
            this->size <<= 2;
            T *t = new T[this->size];
            std::memcpy(t, this->container, sizeof(T));
            this->container = &t[0];
            delete[] t;
        }
    }
    int get_index()
    {
        return ++this->current_index;
    }
    void push_back(const T& val)
    {
        this->resize();
        this->container[get_index()] = val;
    }
    void push_back(T&& val) // rvalue reference
    {
        this->resize();
        this->container[get_index()] = val;
    }
    void print()
    {
        for (int i = 0; i < this->current_index; i++)
        {
            T t = this->container[i];
            log(std::to_string(t));
        }
    }
private:
    int size;
    T *container;
    int current_index;
};

int main() {
    vectr<int> v;
    v.push_back(2);
    int i = 3;
    v.push_back(i);
    v.print();
    //v.push_back(5);
    //v.print();
}


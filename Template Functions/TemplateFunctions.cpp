#include <iostream>

template<typename T> // template<class T>
void print(T n)
{
    std::cout << n << std::endl;
}

int main()
{
    print<int>(5);
    print<std::string>("Hello");

    print("Hi there");
    
    return 0;
}
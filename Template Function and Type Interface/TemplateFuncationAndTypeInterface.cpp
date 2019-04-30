#include <iostream>

template<typename T> // template<class T>
void print(T n)
{
    std::cout << "Template version: " << n << std::endl;
}

void print(int value)
{
    std::cout << "Non-Template version: " << value << std::endl;
}

template<typename T> // template<class T>
void show()
{
    std::cout << T() << std::endl;
}

int main()
{
    print<int>(5);
    print<std::string>("Hello");

    print("Hi there");

    print<>(6);

    print(7);

    show<double>();
    
    return 0;
}
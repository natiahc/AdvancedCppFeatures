#include <iostream>
#include <typeinfo>

int main()
{
    std::string value;
    std::cout << typeid(value).name() << std::endl;

    decltype(value) name = "Bob";
    std::cout << typeid(name).name() << std::endl;

    std::cout << name << std::endl;

    return 0;
}
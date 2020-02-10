#include <iostream>

template<typename T>
void print(const T& v)
{
    std::cout << v << std::endl;
}

template<typename T, typename ... Types>
void print(const T& first, const Types&... args)
{
    std::cout << first << ", ";

    print(args...);
}

template<typename T>
T SumUp(const T& v) 
{ 
    //std::cout << "In SumUp Base: size of args: " << sizeof(T) << std::endl;
    return v; 
}

template<typename T, typename ... Types>
T SumUp(const T& first, const Types&... args)
{
    //std::cout << "In SumUp Main: size of args: " << sizeof...(Types) << std::endl;
    return first + SumUp(args...);
}

int main()
{
 //   print(1, 2, 3, 4, 5);
 //   std::cout << SumUp(1);
    std::cout << SumUp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)<< std::endl;

    return 0;
}
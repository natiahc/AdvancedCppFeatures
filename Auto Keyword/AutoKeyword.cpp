#include <iostream>

template<class T, class S>
auto test(T value1, S value2) -> decltype(value1 + value2)
{
    return value1 + value2;
}

int get()
{
    return 999;
}

auto test2() -> decltype(get())
{
    return get();
}

int main()
{
    //auto int value = 7;

    auto value = 7;
    auto text = "Hello";

    std::cout << test(5, 6) << std::endl;
    std::cout << test2() << std::endl;

    return 0;
}
#include <iostream>

template<class T, class K>
class Test
{
private:
    T obj;

public:
    Test(T obj)
    {
        this->obj = obj;
    }

    void print()
    {
        std::cout << obj << std::endl;
    }
};

int main()
{
    Test<std::string, int> test1("Hello");
    test1.print();

    return 0;
}
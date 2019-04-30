#include <iostream>

void test()
{
    std::cout << "Hello" << std::endl;
}

void test1(int value)
{
    std::cout << "value: " << value << std::endl;
}

int main()
{
    test();
    //void (*pTest)(); // a variable pTest which is a pointer to a function with a void return type and no parameters

    void (*pTest)(int) = test1; // we could initialize this variable

   // pTest = &test; // or pTest = test; also works!!

    //(*pTest)(); // pr pTest(); 

    pTest(5);

    return 0;
}
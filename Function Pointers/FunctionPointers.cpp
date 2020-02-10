#include <iostream>
#include <cmath>

int sum(int a, int b)
{
    return a + b;
}

int prod(int a, int b)
{
    return a * b;
}

int CallFunc(int(*pFunc)(int, int), int a, int b)
{
    return pFunc(a, b);
}

void test()
{
    std::cout << "Hello" << std::endl;
}

void test1(int value)
{
    std::cout << "value: " << value << std::endl;
}

double CallDblFunc(double(*pFunc)(double), double arg)
{
    return pFunc(arg);
}

int main()
{
    test();
    //void (*pTest)(); // a variable pTest which is a pointer to a function with a void return type and no parameters

    //void (*pTest)(int) = test1; // we could initialize this variable

   // pTest = &test; // or pTest = test; also works!!

    //(*pTest)(); // pr pTest(); 

    //pTest(5);

    std::cout << CallFunc(sum, 1, 2) << std::endl;
    std::cout << CallFunc(prod, 3, 2) << std::endl;

    double pi = atan(1.0)*4.0;
    std::cout << pi << std::endl;

    std::cout << CallDblFunc(sin, pi/2.0) << std::endl;
    std::cout << CallDblFunc(cos, pi/2.0) << std::endl;

    int intg;
    typedef int(*IntFuncPtr) (int, int);
    IntFuncPtr fpt = sum;
    std::cout << fpt(3, 4);

    return 0;
}
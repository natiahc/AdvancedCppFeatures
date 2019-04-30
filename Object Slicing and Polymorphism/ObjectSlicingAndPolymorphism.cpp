#include <iostream>

class Parent
{

private:
    int one;

public:
    Parent() : one(0)
    {}

    Parent(const Parent &other) : one(0)
    {
        one = other.one;
        std::cout << "Copy Parent" << std::endl;
    }


    virtual void print()
    {
        std::cout << "Parent" << std::endl;
    }

    virtual ~Parent()
    {}
};

class Child : public Parent
{

private:
    int two;

public:
    Child() : two(0)
    {}

    void print()
    {
        std::cout << "Child" << std::endl;
    }

};

int main()
{
    Child c1;
    Parent &p1 = c1;
    p1.print();

    Parent p2 = Child();
    p2.print();

    return 0;
}
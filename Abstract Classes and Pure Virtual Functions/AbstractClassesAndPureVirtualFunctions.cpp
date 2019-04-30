#include <iostream>

class Animal
{

public:
    virtual void run() = 0;
    virtual void speak() = 0;
};

class Dog : public Animal
{
public:
    virtual void speak()
    {
        std::cout << "Woof!" << std::endl;
    }
};

class Labrador : public Dog
{
public:
    Labrador()
    {
        std::cout << "new Labrador";
    }

    virtual void run()
    {
        std::cout << "Labrador running" << std::endl;
    }
};

void test(Animal &a)
{
    a.run();
}

int main()
{
    Labrador lab;
    lab.run();
    lab.speak();
    
    Animal *animals[5];
    animals[0] = &lab;

    animals[0]->speak();
    animals[0]->run();

    test(lab);

    return 0;
}
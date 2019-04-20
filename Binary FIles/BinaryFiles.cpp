#include <iostream>
#include <string>

#pragma pack(push, 1)

struct Person
{
    char name[50];
    int age;
    double weight;
};

#pragma pack(pop)

int main()
{
    std::cout << sizeof(Person) << std::endl; 
    return 0;
}
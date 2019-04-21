#include <iostream>
#include <map>

class Person
{
private:
    std::string name;
    int age;

public:
    Person() : name(""), age(0)
    {}

    Person(const Person &other)
    {
        std::cout << "Copy constructor running!" << std::endl;
        name = other.name;
        age = other.age;
    }

    Person(std::string name, int age) :
    name(name), age(age)
    {}

    void print() const 
    {
        std::cout << name << ": " << age << std::endl;
    }

};

int main()
{
    std::map<int, Person> people;
    people[52] = Person("Noel", 29);
    people[30] = Person("Mike", 40);
    people[2] = Person("Raj", 40);

    people.insert(std::make_pair(55, Person("Bob", 45)));
    people.insert(std::make_pair(55, Person("Sue", 24)));
    people.insert(std::make_pair(55, Person("anna", 24)));

    for (std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++)
    {
        std::cout << it->first << ": " << std::flush; 
        it->second.print();
    }

    return 0;
}
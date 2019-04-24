#include <iostream>
#include <set>

class Test
{
    int id;
    std::string name;

public:
    Test() : id(0), name("")
    {}

    Test(int id, std::string name) : id(id), name(name)
    {

    }

    void print() const
    {
        std::cout << id << ": " << name << std::endl;
    }

    const Test &operator=(const Test &other)
    {        
        id = other.id;
        name = other.name;

        return *this;
    }

    Test(const Test &other)
    {
        *this = other;
    }

    friend std::ostream &operator<<(std::ostream &out, const Test &test);
};

std::ostream &operator<<(std::ostream &out, const Test &test)
{
    out << test.id << ": " << test.name;
    return out;
}

int main()
{
    Test test1(10, "Mike");
    
    std::cout << test1 << std::endl;

    return 0;
}
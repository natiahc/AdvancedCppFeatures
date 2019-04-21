#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> ages;
    ages["Noel"] = 29;
    ages["Mike"] = 40;
    ages["Raj"] = 30;

    ages["Mike"] = 70;

    //ages.insert(std::pair<std::string, int>("Peter", 100));
    ages.insert(std::make_pair("Peter", 100));

    std::cout << ages["Raj"] << std::endl;
    std::cout << ages["Sue"] << std::endl;

    if (ages.find("Vicky") != ages.end())
    {
        std::cout << "found Vicky" << std::endl;
    }
    else 
    {
        std::cout << "Key not found" << std::endl;
    }
    
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ": " << age.second << std::endl;
    }

    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }


    return 0;
}
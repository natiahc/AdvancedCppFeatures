#include <iostream>
#include <string>
#include <fstream>

#pragma pack(push, 1)

struct Person
{
    char name[50];
    int age;
    double height;
};

#pragma pack(pop)

int main()
{
    Person someone = {"Chaitan", 30, 1.8};

    std::string fileName = "test.bin";

    //// Write Binary file /////////////

    //std::ofstream outputFile;
    //outputFile.open(fileName, std::ios::binary);

    std::fstream outputFile;
    outputFile.open(fileName, std::ios::binary | std::ios::out);

    if (outputFile.is_open())
    {
        //outputFile.write((char *)&someone, sizeof(Person));
        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        outputFile.close();    
    }
    else 
    {
        std::cout << "could not create file " + fileName;
    }

    //// Read Binary file /////////////

    Person someoneElse = {};

    std::ifstream inputFile;
    inputFile.open(fileName, std::ios::binary);

    if (inputFile.is_open())
    {
        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
        inputFile.close();    
    }
    else 
    {
        std::cout << "could not read file " + fileName;
    }
    
    std::cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << std::endl;

    return 0;
}
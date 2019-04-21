#include <iostream>
#include <vector>

int main()
{
    std::vector<double> numbers(0);

    std::cout << "Size: " << numbers.size() << std::endl;

    int capacity = numbers.capacity();
    std::cout << "Capacity: " << capacity << std::endl; 
    for(int i=0; i<10000; i++)
    {
        if(numbers.capacity() != capacity)
        {
            capacity = numbers.capacity();
            std::cout << "Capacity: " << capacity << std::endl;
        }

        numbers.push_back(i);
    }

    numbers.clear();
    //numbers.resize(100); 
    //numbers.reserve(10000); // increase capacity
    std::cout << numbers[2] << std::endl;
    std::cout << "Size: " << numbers.size() << std::endl;
    std::cout << "Capacity: " << numbers.capacity() << std::endl; 

    return 0;
}
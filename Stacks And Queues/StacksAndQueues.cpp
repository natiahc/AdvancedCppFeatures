#include <iostream>
#include <stack>
#include <queue>

class Test
{
    std::string name;

public:
    Test() : name("")
    {}

    Test(std::string name) : name(name)
    {}

    ~Test()
    {
        //std::cout << "Object destroyed" << std::endl;
    }

    void print()
    {
        std::cout << name << std::endl;
    }

};

int main()
{
    // LIFO
    std::stack<Test> testStack;
    testStack.push(Test("Mike"));
    testStack.push(Test("John"));
    testStack.push(Test("Sue"));

    std::cout << std::endl;

    /*
     * This is invalid code! Object is destroyed.
    Test test1 = testStack.top();
    testStack.pop();
    test1.print(); // Reference refers to destroyed objects
    */

   while(testStack.size() > 0)
   {
       Test &test = testStack.top();
       test.print();
       testStack.pop();
   }

   std::cout << std::endl;

    // FIFO
    std::queue<Test> testQueue;
    testQueue.push(Test("Mike"));
    testQueue.push(Test("John"));
    testQueue.push(Test("Sue"));

    std::cout << std::endl;

    testQueue.back().print();

    std::cout << std::endl;

    while(testQueue.size() > 0)
    {
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }

    return 0;
}
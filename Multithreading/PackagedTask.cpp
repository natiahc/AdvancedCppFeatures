#include "thread_inc.h"

/*
    std::packages_task, std::promise, std::future
*/

int main()
{
    // step 1 : does not start thread yet
    std::packaged_task<int(int, int)> task1(sum);
    std::packaged_task<int(int, int)> task2(sum);
    
    // step 2: create future using task 
    std::future<int> ft1 = task1.get_future();
    std::future<int> ft2 = task2.get_future();

    // step 3 : we have to start the thread
    // start the thread
    task1(1, 11);
    task2(1, 101);

    try {
        // step 4 : now get the result of processing
        int a = ft1.get();
        int b = ft2.get();

        std::cout << a << " + " << b << " = " << a+b << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout<< e.what()<< std::endl; 
    }

    return 0;
}
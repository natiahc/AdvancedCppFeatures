#include "thread_inc.h"

/*
    std::async, std::future
*/

int main()
{
    // step 1: possibily starts thread immediately
    std::future<int> ft1(std::async(sum, 1, 11));
    std::future<int> ft2(std::async(sum, 1, 101));

    try{
        // step 2: to get result we have to call future.get()
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
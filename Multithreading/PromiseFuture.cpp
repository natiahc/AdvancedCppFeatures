#include "thread_inc.h"

/*
    std::thread, std::promise, std::future
*/

int main()
{
    // step 1 : create promise with return type
    std::promise<int> prm, prm2;

    // step 2 : create a future using promise
    std::future<int> ft = prm.get_future();
    std::future<int> ft2 = prm2.get_future();

    // step 3 : create a thread using promise
    std::thread thr(sum_prm, std::ref(prm), 1, 11);
    std::thread thr2(sum_prm, std::ref(prm2), 1, 101);

    // step 4 : detach thread
    // you should not forget this step
    thr.detach();
    thr2.detach();

    try {
        // step 5: now get the result of processing
        int a = ft.get();
        int b = ft2.get();

        std::cout << a << " + " << b << " = " << a+b << std::endl; 
    }
    catch(std::exception& e)
    {
        std::cout<< e.what()<< std::endl; 
    }

    return 0;
}
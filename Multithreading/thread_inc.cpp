#include "thread_inc.h"

int sum(int st, int ed)
{
    int rlt = 0;
    for (int i = st; i < ed; ++i)
    {
        if(i == (st+ed)/2)
        {
            std::ostringstream os;
            os << "sum(" << st << ", " << ed << ") - throw exception at: " << i;
            throw std::runtime_error(os.str());
        }

        rlt += i;
    }

    return rlt; 
}

void sum_prm(std::promise<int>& prm, int st, int ed)
{
    try{
        int rlt = 0;
        for (int i = st; i < ed; ++i)
        {
            if(i == (st+ed)/2)
            {
                std::ostringstream os;
                os << "sum(" << st << ", " << ed << ") - throw exception at: " << i;
                throw std::runtime_error(os.str());
            }

            rlt += i;
        }

        //prm.set_value(rlt);
        prm.set_value_at_thread_exit(rlt);
    }
    catch(...)
    {
        //prm.set_exception(std::current_exception());
        prm.set_exception_at_thread_exit(std::current_exception());
    }
}
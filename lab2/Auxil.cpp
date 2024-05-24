#include "Auxil.h" 
#include <ctime>    
namespace auxil
{
    void start()                          
    {
        srand((unsigned)time(NULL));
    };
    double dget(double rmin, double rmax) 
    {
        return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
    };
    int iget(int rmin, int rmax)          

    {
        return (int)dget((double)rmin, (double)rmax);
    };

    int fibonacci(int number)
    {
        if (number == 0)
            return 0; 
        if (number == 1)
            return 1; 
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}
#include "Auxil.h"                           
#include <iostream>
#include <fstream>
#include <ctime>
#define N 46

clock_t SS[N];

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    setlocale(LC_ALL, "rus");
    for (int n = 0; n < N; n++)
    {
        SS[n] = clock();
        int result = fibonacci(n);
        SS[n] = -(SS[n] - clock());
        std::cout << std::endl << "n = " << n << ", Fibonacci = " << result << ", Время выполнения: " << SS[n] << " мс";
    }
    system("pause");
    return 0;
}
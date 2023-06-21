#include <omp.h>
#include <stdio.h>

int main()
{
#pragma omp parallel
#pragma omp for schedule(auto)
    for (int i = 0; i < 10; i++)
    {
        printf("Hi from thread %d, I am iteration %d\n", omp_get_thread_num(), i);
    }
    return 0;
}
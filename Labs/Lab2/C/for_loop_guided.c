#include <omp.h>
#include <stdio.h>

int main()
{
#pragma omp parallel
#pragma omp for schedule(guided, 3)
    for (int i = 0; i < 20; i++)
    {
        printf("Hi from thread %d, I am iteration %d\n", omp_get_thread_num(), i);
    }
    return 0;
}
#include <stdio.h>
#include <omp.h>

int main()
{
    int i = 0, j[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    #pragma omp parallel
    {
        #pragma omp critical
        {
            i++;
            j[i] = omp_get_thread_num();
            #pragma omp flush
        }
    }

    for (i = 0; i < 10; i++)
        printf("Thread %d was the %d to execute the critical section.\n", j[i], i + 1);

    return 0;
}

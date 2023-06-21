#include <omp.h>
#include <stdio.h>

int main()
{
    int arr[10];
#pragma omp parallel num_threads(10)
    {
        arr[omp_get_thread_num()] = omp_get_thread_num();
#pragma omp barrier
#pragma omp single
        {
            for (int i = 0; i < 10; i++)
            {
                printf("arr[%d] = %d\n", i, arr[i]);
            }
        }
    }
}
#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(5)
    {
        #pragma omp single
            printf("1, I am thread %d\n", omp_get_thread_num());
        #pragma omp single
            printf("2, I am thread %d\n", omp_get_thread_num());
        #pragma omp single
            printf("3, I am thread %d\n", omp_get_thread_num());
    }
    return 0;
}

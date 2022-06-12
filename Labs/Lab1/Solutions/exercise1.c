#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel num_threads(10)
    {
        if (omp_get_thread_num() % 2)
            printf("Hello from thread %d I am Even\n",omp_get_thread_num());
        else
            printf("Hello from thread %d I am Odd\n",omp_get_thread_num());
    }
    return 0;
}
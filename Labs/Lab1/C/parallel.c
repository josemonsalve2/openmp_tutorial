#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel num_threads(10)
    {
        printf("Hello from thread %d\n",omp_get_thread_num());
    }
    return 0;
}
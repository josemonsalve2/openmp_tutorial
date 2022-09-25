#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel if(0) num_threads(1000)
    {
        printf("Hi from %d out of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
    return 0;
}
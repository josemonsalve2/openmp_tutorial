#include <stdio.h>
#include <omp.h>

int main() {

    #pragma omp parallel
    {
        printf("Using default or OMP_NUM_THREADS from %d out of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
    
    omp_set_num_threads(2);
    #pragma omp parallel
    {
        printf("Using omp_set_num_threads(2) from %d out of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }

    #pragma omp parallel num_threads(4)
    {
        printf("using num_threads(4) clause from %d out of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
    return 0;
}
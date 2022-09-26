#include <stdio.h>
#include <omp.h>

int main() {
    printf("Setting the number of threads to 4\n");
    // Setting the number of threads
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        printf("Hi from %d out of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
    return 0;
}
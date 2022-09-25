#include <omp.h>
#include <stdio.h>

int main() {
    int a_var = 0;
    
    // Check if the number of threads is adequate.
    int num_threads_to_create = omp_get_max_threads();
    if (num_threads_to_create <2) {
        printf("Early termination. insufficient number of threads\n");
        return -1;
    }

    printf("I'm starting\n");
    #pragma omp parallel shared(a_var)
    {
        if (omp_get_thread_num()==0) {
            printf("running with %d threads\n", omp_get_num_threads());
            printf("I'm waiting for any other thread\n");
            while(a_var == 0);
        } else {
            #pragma omp atomic
            a_var++;
        }
    }
    printf("I've finished\n");
    return 0;
}
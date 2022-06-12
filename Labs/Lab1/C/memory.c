#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main() {
    int i;
    double share;
    int Array[10];

    printf("Address of i prior to the parallel region is: %lx\n",(unsigned long)&i);
    printf("Address of shared prior to the parallel region is: %lx\n",(unsigned long)&share);
    printf("Address of Array prior to the parallel region is: %lx\n",(unsigned long)Array);

    #pragma omp parallel private(i, Array) shared(share)
    {
        printf("Address of i as seen by thread %d: %lx\n", omp_get_thread_num(), (unsigned long)&i);
        printf("Address of Array as seen by thread %d: %lx\n", omp_get_thread_num(), (unsigned long)Array);
        printf("Address of share as seen by thread %d: %lx\n", omp_get_thread_num(), (unsigned long)&share);
    }
    return 0;
}
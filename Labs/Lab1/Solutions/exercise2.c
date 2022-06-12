#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define PRINT_ARR(A, size) { \
   printf("["); \
   int i;\
   for (i = 0; i < size; ++i && printf(" %d ",A[i-1]));\
   printf("]\n"); \
}


int main() {
    int Array[100];
    int max = 0;
    int min = 100000;
    int avg;

    #pragma omp parallel num_threads(100)
    {
        Array[omp_get_thread_num()] = rand() % 10000;
    }

    PRINT_ARR(Array,100);

    #pragma omp parallel reduction(max:max)
    {
        max = Array[omp_get_thread_num()];
    }
    printf("max is %d\n",max);

    #pragma omp parallel reduction(min:min)
    {
        min = Array[omp_get_thread_num()];
    }
    printf("min is %d\n",min);

    #pragma omp parallel reduction(+:avg)
    {
        avg = Array[omp_get_thread_num()]/100;
    }
    printf("Avg is %d\n",avg);

    return 0;
}
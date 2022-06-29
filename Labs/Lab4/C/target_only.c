#include <omp.h>
#include <stdio.h>

#define N 1000000

int main () {

    int *A;
    A = (int*) malloc(sizeof(int)*N);

    // Initializing array
    for (int i = 0; i < N; i++)
        A[i] = 0;

    double start, end;

    start = omp_get_wtime();

    for (int i = 0; i < N; i++)
        A[i]++;
    
    end = omp_get_wtime();

    printf("CPU Time = %f\n", end-start);


    start = omp_get_wtime();

    #pragma omp target map(tofrom:A[0:N])
    for (int i = 0; i < N; i++)
        A[i]++;
    
    end = omp_get_wtime();

    printf("GPU Time = %f\n", end-start);

    #pragma omp target enter data map(to:A[0:N])
    start = omp_get_wtime();

    #pragma omp target
    for (int i = 0; i < N; i++)
        A[i]++;
    
    end = omp_get_wtime();

    #pragma omp target exit data map(delete:A[0:N])

    printf("GPU no data move Time = %f\n", end-start);
    return 0;
}
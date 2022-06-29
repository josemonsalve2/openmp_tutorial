#include <omp.h>
#include <stdio.h>
#include <math.h>

#define N 100000

void f(double *A, double *B, int i) {
    A[i] = (B[i+1] * B[i] * B[i-1])/3;
    A[i] = A[i]/0.03;
    A[i] = sin(A[i]);
}


int main () {

    double *A, *B;
    A = (double*) malloc(sizeof(double)*N);
    B = (double*) malloc(sizeof(double)*N);

    // Initializing array
    for (int i = 0; i < N; i++)
    {
        A[i] = 1;
        B[i] = i;
    }

    double start, end;

    start = omp_get_wtime();

    for (int i = 1; i < N-1; i++) {
        f(A,B,i);
    }
    
    end = omp_get_wtime();

    printf("CPU Time = %f\n", end-start);


    start = omp_get_wtime();

    #pragma omp target map(tofrom:A[0:N],B[0:N])
    for (int i = 1; i < N-1; i++)
        f(A,B,i);
    
    end = omp_get_wtime();

    printf("GPU Time = %f\n", end-start);

    #pragma omp target enter data map(to:A[0:N],B[0:N])
    start = omp_get_wtime();

    #pragma omp target
    for (int i = 1; i < N-1; i++)
        f(A,B,i);
    
    end = omp_get_wtime();

    #pragma omp target exit data map(delete:A[0:N],B[0:N])

    printf("GPU no data move Time = %f\n", end-start);
    return 0;
}
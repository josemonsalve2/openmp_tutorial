#include <omp.h>
#include <stdio.h>

#define N 10000
#define STEPS 50000

void simFunction(double* A) {
    A[0]++;
}

void withoutTargetData(double* A) {
    for (int step = 0; step < STEPS; step++)
        #pragma omp target map(tofrom:A[0:N])
            simFunction(A);
}

void withTargetData(double* A) {
    #pragma omp target data map(tofrom: A[0:N])
    {
        for (int step = 0; step < STEPS; step++)
        #pragma omp target // data is not copied here
            simFunction(A);
    }
}

int main() {
    double *A = (double*) malloc(N*sizeof(double));
    double time_start, time_end;
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }

    time_start = omp_get_wtime();
    withoutTargetData(A);
    time_end = omp_get_wtime();
    printf("Exec time without target data = %lf\n", time_end - time_start);

    time_start = omp_get_wtime();
    withTargetData(A);
    time_end = omp_get_wtime();
    printf("Exec time with target data = %lf\n", time_end - time_start);

    return 0;
}
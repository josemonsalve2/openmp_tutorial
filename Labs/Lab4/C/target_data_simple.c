#include <omp.h>
#include <stdio.h>

#define PRINT(A,N)              \
    printf("%s = [",#A);        \
    for (int i = 0; i < N; i++) \
        printf(" %d ", A[i]);   \
    printf("]\n");

int main() {
    int A[100];
    for (int i = 0; i < 100; i++) {
        A[i] = i;
    }

    PRINT(A, 100);

    #pragma omp target data map(tofrom: A)
    {
        for (int i = 0; i < 100; i++) // EXECUTED IN THE HOST
        A[i] = 0;
    }

    PRINT(A, 100);
    
    return 0;
}
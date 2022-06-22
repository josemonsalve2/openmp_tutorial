#include <omp.h>
#include <stdio.h>

#define PRINT(A,N)              \
    printf("%s = [",#A);        \
    for (int i = 0; i < N; i++) \
        printf(" %d ", A[i]);   \
    printf("]\n");

int main() {
    int A[100];
    int B[100];
    for (int i = 0; i < 100; i++) {
        A[i] = i;
        B[i] = 0;
    }

    PRINT(A, 100);
    PRINT(B, 100);

    #pragma omp target map(to: A[0:50]) map(from: B[50:50])
    {
        for (int i = 50; i < 100; i++)
            B[i] = A[i-50];
    }

    PRINT(A, 100);
    PRINT(B, 100);
    
    return 0;
}
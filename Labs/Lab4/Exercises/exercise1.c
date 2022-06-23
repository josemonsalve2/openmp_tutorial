#include <stdio.h>
#include <omp.h>

#define PRINT(A,N)              \
    printf("%s = [",#A);        \
    for (int i = 0; i < N; i++) \
        printf(" %d ", A[i]);   \
    printf("]\n");

int main() {
    int A[100];

    // Write your code here

    PRINT(A,100);
    return 0;
}
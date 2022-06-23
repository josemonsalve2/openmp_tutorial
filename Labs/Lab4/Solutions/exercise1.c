#include <stdio.h>
#include <omp.h>

#define PRINT(A,N)              \
    printf("%s = [",#A);        \
    for (int i = 0; i < N; i++) \
        printf(" %d ", A[i]);   \
    printf("]\n");

int main() {
    int A[100];

    for (int i = 0; i < 100; i++) {
        #pragma omp target if(i%2 == 0)
            A[i] = omp_get_device_num();
    }

    PRINT(A,100);
    return 0;
}
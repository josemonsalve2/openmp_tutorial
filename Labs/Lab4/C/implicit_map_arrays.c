#include <stdio.h>
#include <omp.h>

int main() {
    int A[] = {1,2,3};

    printf("Host {%d, %d, %d}\n", A[0],A[1],A[2]);

    #pragma omp target // default map(tofrom:A[0:3])
    {
        printf("Device {%d, %d, %d}\n", A[0],A[1],A[2]);
        A[0]++; A[1]++; A[2]++;
    }

    printf("Host {%d, %d, %d}\n", A[0],A[1],A[2]);
    return 0;
}
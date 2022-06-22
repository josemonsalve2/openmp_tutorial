#include <stdio.h>
#include <omp.h>

int main() {
    int *A = (int*) malloc(3*sizeof(int));
    A[0] = 1; A[1] = 2; A[2] = 3;

    printf("Host A = {%d, %d, %d}\n", A[0],A[1],A[2]);

    #pragma omp target // implicit map(tofrom:A[0:0])
    {
        // printf("Device A = {%d, %d, %d}\n", A[0],A[1],A[2]); Error since pointer is not mapped. 
        // A[0]++; A[1]++; A[2]++; Error since pointer is not mapped
        printf("Cannot access A[]\n");
    }

    #pragma omp target data map(tofrom: A[0:3])
    {
        #pragma omp target // implicit mapping map(tofrom:A[0:0])
        {
            // A is automatically translated to a previously mapped location
            printf("Device A = {%d, %d, %d}\n", A[0],A[1],A[2]); 
            A[0]++; A[1]++; A[2]++;
        }
    }

    printf("Host A = {%d, %d, %d}\n", A[0],A[1],A[2]);
    return 0;
}
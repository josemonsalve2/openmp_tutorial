#include <stdio.h>
#include <omp.h>


int main() {
    int A[1];

    A[0] = 0;
    #pragma omp target enter data map(to:A[:]) // Data copied
        
    A[0] = 1;
    // Data not copied (reference = 2)
    #pragma omp target enter data map(to:A[:]) 
    // Let's see the value on the device
    #pragma omp target
        printf("Device A[0] = %d\n", A[0]);

    // Update always copies
    #pragma omp target update to(A[0:1])
    
    // Let's see the value on the device and modify
    #pragma omp target
    {
        printf("Device A[0] = %d\n", A[0]);
        A[0] = 99;
    }
    
    // data not copied because reference is not 0
    #pragma omp target exit data map(from:A[:])

    printf("Host A[0] = %d\n", A[0]);

    // Update always copies
    #pragma omp target update from(A[0:1]) // data copied

    // Let's see the value on the device and modify
    #pragma omp target
    {
        printf("Device A[0] = %d\n", A[0]);
        A[0] = 66;
    }

    // Reference reaches 0. Data is copied
    #pragma omp target exit data map(from:A[:])

    printf("Host A[0] = %d\n", A[0]);

    return 0;
}
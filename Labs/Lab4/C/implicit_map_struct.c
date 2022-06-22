#include <stdio.h>
#include <omp.h>

typedef struct myS{
    int a;
    double *b;
}myS_t;

int main() {
    myS_t myStruct = {1, NULL};

    myStruct.b = (double *) malloc(sizeof(double));
    *(myStruct.b) = 11.1;

    printf("Host {%d, %lx}\n", myStruct.a, (unsigned long) myStruct.b);

    #pragma omp target
    {
        myStruct.a = 10;
        // printf("%f\n", myStruct.b); error since b is not deep copied
        printf("Device {%d, %lx}\n", myStruct.a, (unsigned long) myStruct.b);
    }

    printf("Host {%d, %lx}\n", myStruct.a, (unsigned long) myStruct.b);
    return 0;
}
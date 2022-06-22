#include <stdio.h>
#include <omp.h>

int main() {
    int a[1];
    printf("Addres of a in host = %lx\n", (unsigned long)a);
    #pragma omp target
    {
        printf("Addres of a in device = %lx\n", (unsigned long)a);
    }
    return 0;
}
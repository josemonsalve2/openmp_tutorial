#include <stdio.h>
#include <omp.h>

int main() {
    int a = 10;
    #pragma omp target // implicit firsprivate(a)
    {
        printf("a = %d",a);
        a = 20
    }
    printf("a = %d",a);
    return 0;
}
#include <stdio.h>
#include <omp.h>

int main() {
    int a = 10;
    #pragma omp target // implicit firsprivate(a)
    {
        printf("a = %d\n",a);
        a = 20;
    }
    printf("a = %d\n",a);
    return 0;
}
#include <stdio.h>
#include <omp.h>


int main() {
    int Array[10];
    int i, b;

    for (i = 0; i < 10; i++) {
        Array[i] = i;
    }

    #pragma omp parallel for lastprivate(b)
    for (i = 0; i < 10; i++)
    {
        b = Array[i];
    }
    printf("b is %d after the parallel region\n", b);

    return 0;
}
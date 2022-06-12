#include <stdio.h>
#include <omp.h>


int main() {
    int i = 0;

    #pragma omp parallel shared(i) num_threads(10000)
    {
        #pragma omp atomic
        i++;
    }

    printf("i = %d\n",i);
    return 0;
}
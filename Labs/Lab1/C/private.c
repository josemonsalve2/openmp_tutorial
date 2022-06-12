#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main() {
    int i = 999;

    printf("i is %d before parallel region\n",i);

    #pragma omp parallel private(i) num_threads(10)
    {
        printf("Thread %d sees %d on memory %lx\n", omp_get_thread_num(), i, (unsigned long)&i);
    }

    return 0;
}
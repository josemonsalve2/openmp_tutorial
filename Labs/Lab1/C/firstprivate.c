#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main() {
    int i[3] = {999,888,666};

    printf("i is [%d,%d,%d] before parallel region\n",i[0],i[1],i[2]);

    #pragma omp parallel firstprivate(i) num_threads(10)
    {
        printf("Thread %d sees [%d,%d,%d] on memory %lx\n", omp_get_thread_num(), i[0],i[1],i[2], (unsigned long)i);
    }

    return 0;
}
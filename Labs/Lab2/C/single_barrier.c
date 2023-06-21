#include <stdio.h>
#include <omp.h>

int main()
{
    int i = 0;
    #pragma omp parallel num_threads(10)
    {
        #pragma omp single
            i = omp_get_num_threads();
        #pragma omp atomic
            i = i - 1;
    }
    printf("i = %d\n", i);
    return 0;
}

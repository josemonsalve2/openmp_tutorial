#include <stdio.h>
#include <omp.h>

int main()
{
    int i, j[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    #pragma omp parallel
    {
        i = omp_get_thread_num();
        j[i] = 99;
    }

    for (i = 0; i < 10; i++)
        printf("j[%d] = %d\n", i, j[i]);

    return 0;
}

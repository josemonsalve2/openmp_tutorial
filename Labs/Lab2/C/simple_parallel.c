#include <stdio.h>
#include <omp.h>

int main()
{
    int i = 0;
    #pragma omp parallel num_threads(4)
    {
        // This is the work associated to each thread
        #pragma omp atomic
        i = i + 1;
    }
    printf("i = %d\n", i);
    return 0;
}

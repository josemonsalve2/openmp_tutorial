#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(5)
    {
        #pragma omp masked
            printf("Hi, I am thread 0\n");
        #pragma omp masked filter(4)
            printf("And I am thread 4\n");
    }
    return 0;
}

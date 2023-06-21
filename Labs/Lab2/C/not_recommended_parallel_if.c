#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(5)
    {
        if (omp_get_thread_num() == 0)
        {
            printf("Hi, I am thread 0\n");
        }
        if (omp_get_thread_num() == 4)
        {
            printf("And I am thread 4\n");
        }
    }
    return 0;
}

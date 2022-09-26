#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(1)
    {
        printf("Level %d\n", omp_get_level());
        #pragma omp parallel num_threads(1)
        {
            printf("Level %d\n", omp_get_level());
            #pragma omp parallel num_threads(1)
            {
                printf("Level %d\n", omp_get_level());
            }
        }
    }
    return 0;
}
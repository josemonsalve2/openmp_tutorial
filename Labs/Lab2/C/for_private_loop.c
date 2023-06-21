#include <omp.h>
#include <stdio.h>

int main()
{
    int x;
    int arr[10];
    #pragma omp parallel
        #pragma omp for schedule(static, 3) firstprivate(x)
        for (int i = 0; i < 10; i++)
            arr[i] = x++;

    for (int i = 0; i < 10; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
    return 0;
}
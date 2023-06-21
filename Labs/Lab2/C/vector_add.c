#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main()
{
    int a[1000];
    int b[1000];
    int c[1000];

    for (int i = 0; i < 1000; i++)
    {
        a[i] = i;
        b[i] = i;
    }

#pragma omp parallel for
    for (int i = 0; i < 1000; i++)
        c[i] = a[i] + b[i];

    return 0;
}

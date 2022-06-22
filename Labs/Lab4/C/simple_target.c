#include <stdio.h>
#include <omp.h>

int main() {
    int a[1] = {0};
    #pragma omp target
    {
        a[0] = omp_is_initial_device();
    }
    printf("Code executed in the %s\n",a[0] ? "Host":"Device");
    return 0;
}
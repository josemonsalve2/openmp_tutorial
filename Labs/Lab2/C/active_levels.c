#include <stdio.h>
#include <omp.h>

void foo(int a) {
    if (a == 0) return;
    printf("Level %d is %s\n", omp_get_level(), 
            (omp_get_level() == omp_get_active_level()) ? "Active": "Inactive");
    #pragma omp parallel num_threads(2)
    {
        #pragma omp single
        foo(a-1);
    }
}


int main() {
    foo(5);
    return 0;
}

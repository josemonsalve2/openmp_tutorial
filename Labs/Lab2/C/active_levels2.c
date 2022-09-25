#include <stdio.h>
#include <omp.h>

void foo(int a) {
    if (a == 0) return;
    int i = 0;
    // Check if all my ancestors are thread 0
    while(omp_get_ancestor_thread_num(i) == 0 && i++ <= omp_get_level());
    if (omp_get_level() == i)
        printf("Level %d is %s\n", omp_get_level(), 
            (omp_get_level() == omp_get_active_level()) ? "Active": "Inactive");
    #pragma omp parallel num_threads(2)
    {
        foo(a-1);
    }
}


int main() {
    foo(5);
    return 0;
}

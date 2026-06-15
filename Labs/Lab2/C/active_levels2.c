#include <stdio.h>
#include <omp.h>

void foo(int a) {
    if (a == 0) return;
    int i = 0;
    // Walk up the levels while every ancestor is thread 0. The bound is
    // checked before the ancestor query so we never call
    // omp_get_ancestor_thread_num() with a level past omp_get_level().
    while (i <= omp_get_level() && omp_get_ancestor_thread_num(i) == 0)
        i++;
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

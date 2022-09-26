#include <stdio.h>
#include <omp.h>

void foo() {
    #pragma omp parallel num_threads(12)
    {
        printf("hello from %d\n", omp_get_thread_num());
    }
}

int main() {
    printf("No teams:\n");
    foo();
    printf("With teams:\n");
    #pragma omp teams num_teams(2) thread_limit(6)
    {
        foo();
    }
}
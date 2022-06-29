#include <omp.h>
#include <stdio.h>

int main () {

    #pragma omp target teams distribute parallel for num_teams(3) num_threads(3)
    for(int i = 0; i < 10; i++) {
        printf("iteration %d executed by team %d thread %d\n", i, omp_get_team_num(), omp_get_thread_num());
    }

    return 0;
}
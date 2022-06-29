#include <omp.h>
#include <stdio.h>

int main () {

    #pragma omp target teams distribute num_teams(3)
    for(int i = 0; i < 10; i++) {
        printf("iteration %d executed by team %d\n", i, omp_get_team_num());
    }

    return 0;
}
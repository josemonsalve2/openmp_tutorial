#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp teams num_teams(6)
    {
        printf("Hi from team %d and I have %d threads\n", omp_get_team_num(), omp_get_num_threads());
    }
    return 0;
}

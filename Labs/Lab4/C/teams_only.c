#include <omp.h>
#include <stdio.h>

int main () {

    #pragma omp target teams
    {
        int teamNum = omp_get_team_num();
        int threadNum = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        int numTeams = omp_get_num_teams();
        if ( teamNum == 0)
            printf("There are %d teams in total\n", numTeams);
        printf("I am thread %d in team %d and there are %d threads inside me\n", threadNum, teamNum, numThreads);
    }

    return 0;
}
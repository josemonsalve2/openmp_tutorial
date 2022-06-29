#include <omp.h>
#include <stdio.h>

int main () {

    #pragma omp target parallel
    {
        int teamNum = omp_get_team_num();
        int threadNum = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        int numTeams = omp_get_num_teams();
        //#pragma omp master -- there's a bug in clang
        if (threadNum == 0)
            printf("There are %d teams in total and %d threads\n", numTeams, numThreads);
        printf("I am thread %d out of %d in team %d \n", threadNum, numThreads, teamNum);

        #pragma omp barrier

        //#pragma omp single -- there's a bug in clang
        if (threadNum == 0)
            printf("This message is guaranteed to go at the end\n");
    }

    return 0;
}
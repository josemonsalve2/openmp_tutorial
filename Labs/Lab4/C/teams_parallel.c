#include <omp.h>
#include <stdio.h>

int main () {

    #pragma omp target
    {
        #pragma omp teams num_teams(5)
        {
            #pragma omp parallel num_threads(32)
            {
                int teamNum = omp_get_team_num();
                int threadNum = omp_get_thread_num();
                int numThreads = omp_get_num_threads();
                int numTeams = omp_get_num_teams();
                //#pragma omp master -- there's a bug in clang
                if (threadNum == 0)
                    printf("There are %d teams in total and %d threads in this team\n", numTeams, numThreads);
                printf("I am thread %d out of %d in team %d \n", threadNum, numThreads, teamNum);

                #pragma omp barrier

                //#pragma omp single -- there's a bug in clang
                if (threadNum == 0)
                    printf("This message is guaranteed to go at the end of parallel but not across teams\n");
            }
        }
    }

    return 0;
}
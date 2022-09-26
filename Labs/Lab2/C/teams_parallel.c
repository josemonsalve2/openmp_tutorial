#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp teams num_teams(6)
    {
        #pragma omp parallel num_threads(2)
        {
            printf("Hi from thread %d in team %d\n", omp_get_thread_num(), omp_get_team_num());
        }
    }
    return 0;
}

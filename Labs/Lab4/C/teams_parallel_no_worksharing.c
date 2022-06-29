#include <omp.h>
#include <stdio.h>

int main () {

    int a = 0;

    #pragma omp target map(tofrom:a)
    {
        #pragma omp teams num_teams(5)
        {
            #pragma omp parallel num_threads(32)
            {
                for (int i = 0; i < 100; i++)
                    #pragma omp atomic
                        a++;
                if (omp_get_thread_num() == 0 && omp_get_team_num() == 0)
                    printf("Num Threads = %d, Num Teams = %d\n", omp_get_num_threads(), omp_get_num_teams());
            }
        }
    }

    printf ("a was incremented %d times\n", a);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1300

void sequentian(int *A, int *B, int *C)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            *(C + i * N + j) = 0;
            for (int k = 0; k < N; k++)
            {
                *(C + i * N + j) += *(A + i * N + k) * *(B + k * N + j);
            }
        }
    }
}

void parallel(int *A, int *B, int *C)
{
#pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            *(C + i * N + j) = 0;
            for (int k = 0; k < N; k++)
            {
                *(C + i * N + j) += *(A + i * N + k) * *(B + k * N + j);
            }
        }
    }
}

int main()
{
    int *A, *B, *C;

    // Allocate memory for matrices A, B, and C
    A = (int *)malloc(N * N * sizeof(int));
    B = (int *)malloc(N * N * sizeof(int));
    C = (int *)malloc(N * N * sizeof(int));

    // Initialize matrices A and B with a simple loop
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            *(A + i * N + j) = i + j;
            *(B + i * N + j) = i - j;
        }
    }

    // Perform matrix multiplication
    double start = omp_get_wtime();
    sequentian(A, B, C);
    double end = omp_get_wtime();
    double time_spent = end - start;
    printf("Time spent in sequential: %f\n", time_spent);

    start = omp_get_wtime();
    parallel(A, B, C);
    end = omp_get_wtime();
    time_spent = end - start;
    printf("Time spent in parallel: %f\n", time_spent);

    // Print the result matrix C
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         printf("%d ", *(C + i * N + j));
    //     }
    //     printf("\n");
    // }

    // Free memory allocated for matrices A, B, and C
    free(A);
    free(B);
    free(C);

    return 0;
}

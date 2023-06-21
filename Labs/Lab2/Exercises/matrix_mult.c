#include <stdio.h>
#include <stdlib.h>

#define N 10

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

    // Print the result matrix C
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", *(C + i * N + j));
        }
        printf("\n");
    }

    // Free memory allocated for matrices A, B, and C
    free(A);
    free(B);
    free(C);

    return 0;
}

#include <omp.h>
#include <stdio.h>
#include <chrono>

void f()
{
    int a = 0;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
#pragma omp parallel
            f();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    printf("Time independent parallel regions: %f\n", diff.count());

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++)
#pragma omp parallel
    {
        for (int j = 0; j < 1000; j++)
        {
            f();
#pragma omp barrier
        }
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    printf("Time single parallel region with barriers: %f\n", diff.count());
}
#include <omp.h>
#include <stdio.h>

struct someStruct
{
    int a;
    int b;
    int c;
};

int main()
{
    struct someStruct s[10];
#pragma omp parallel num_threads(5)
    {
#pragma omp sections
        {
#pragma omp section
            for (int i = 0; i < 10; i++)
            {
                s[i].a = i;
            }
#pragma omp section
            for (int i = 0; i < 10; i++)
            {
                s[i].b = i;
            }
#pragma omp section
            for (int i = 0; i < 10; i++)
            {
                s[i].c = i;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("s[%d].a = %d\n", i, s[i].a);
        printf("s[%d].b = %d\n", i, s[i].b);
        printf("s[%d].c = %d\n", i, s[i].c);
    }

    return 0;
}
#include <stdio.h>
#include <omp.h>
#include <string.h>

typedef struct myStr_s{
    char a[10];
    int b;
}myStr;


int main() {
    int x = 3;
    int y[3] = {1,2,3};
    int *z = (int*)malloc(3 * sizeof(int));
    z[0] = 1; z[1] = 2; z[2] = 3;
    myStr s = {"aaa",0};
    myStr sa[3] = {{"hola", 1},{"chao", 2},{"hello", 3}};

    printf("In host: \nx = %d,\ny = {%d, %d, %d},\nz = {%d, %d, %d},\ns = {%s, %d},\nsa = [{%s, %d},{%s, %d},{%s, %d}]\n", 
            x, y[0], y[1], y[2], z[0], z[1], z[2], s.a, s.b, sa[0].a, sa[0].b, sa[1].a, sa[1].b, sa[2].a, sa[2].b);

    #pragma omp target          \
            map (alloc: y[:])   \
            map (to: z[0:3])    \
            map (from: sa[0:3])
    {
        printf("In device:\nx = %d,\ny = {%d, %d, %d},\nz = {%d, %d, %d},\ns = {%s, %d},\nsa = [{%s, %d},{%s, %d},{%s, %d}]\n", 
           x, y[0], y[1], y[2], z[0], z[1], z[2], s.a, s.b, sa[0].a, sa[0].b, sa[1].a, sa[1].b, sa[2].a, sa[2].b);

        printf("modifying variables\n");
        x = 44;
        y[0] = 1; y[1] = 44; y[2] = 2;
        z[0] = 99; z[1] = 44; z[2] = 2;
        sa[0].a[0] = 'h'; sa[0].a[1] = '\0'; // strcpy not supported yet
        sa[0].b = 3;
        sa[1].a[0] = 'y'; sa[1].a[1] = '\0'; // strcpy not supported yet
        sa[1].b = 4;
        sa[2].a[0] = 't'; sa[2].a[1] = '\0'; // strcpy not supported yet
        sa[2].b = 5;
        s.a[0] = 'k'; s.a[1] = '\0'; // strcpy not supported yet
        s.b = 42;

        printf("In device modified:\nx = %d,\ny = {%d, %d, %d},\nz = {%d, %d, %d},\ns = {%s, %d},\nsa = [{%s, %d},{%s, %d},{%s, %d}]\n", 
           x, y[0], y[1], y[2], z[0], z[1], z[2], s.a, s.b, sa[0].a, sa[0].b, sa[1].a, sa[1].b, sa[2].a, sa[2].b);
    }

    printf("In host: \nx = %d,\ny = {%d, %d, %d},\nz = {%d, %d, %d},\ns = {%s, %d},\nsa = [{%s, %d},{%s, %d},{%s, %d}]\n", 
            x, y[0], y[1], y[2], z[0], z[1], z[2], s.a, s.b, sa[0].a, sa[0].b, sa[1].a, sa[1].b, sa[2].a, sa[2].b);

    return 0;
}
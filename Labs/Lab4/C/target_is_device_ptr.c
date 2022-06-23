#include <omp.h>
#include <stdio.h>

#define PRINT(A,N)              \
    printf("%s = [",#A);        \
    for (int i = 0; i < N; i++) \
        printf(" %d ", A[i]);   \
    printf("]\n");

int main () {

    int *A; int B[100];

    for (int i = 0; i < 100; i++) {
        B[i] = i;
    }
    printf("Values of B in the host are:\n");
    PRINT(B,20);

    int dev_id = omp_get_default_device();
    int host_id = omp_get_initial_device();

    A = omp_target_alloc(/*size*/ sizeof(int)*100,
                        /*dest_dev_id*/ dev_id);
    printf("Allocating a device pointer with address A = 0x%lX:\n",(unsigned long)A);

    omp_target_memcpy(/*dest_ptr*/ A,
                    /*src_ptr*/ B, 
                    /*length*/ sizeof(int)*100, 
                    /*offset_dst*/ 0, 
                    /*offset_src*/ 0, 
                    /*dest_dev_id*/ dev_id, 
                    /*src_dev_id*/ host_id);

    #pragma omp target
    {
        printf("With no is_device_ptr() device sees (invalid) A = 0x%lX:\n",(unsigned long)A);
    }

    #pragma omp target is_device_ptr(A)
    {
        printf("With is_device_ptr() we can access the address of A = 0x%lX:\n",(unsigned long)A);
        for (int i = 0; i < 100; i++)
            A[i]++;
    }

    // Manually copying data back into B
    omp_target_memcpy(/*dest_ptr*/ B,
                /*src_ptr*/ A, 
                /*length*/ sizeof(int)*100, 
                /*offset_dst*/ 0, 
                /*offset_src*/ 0, 
                /*dest_dev_id*/ host_id, 
                /*src_dev_id*/ dev_id);
    printf("Copying back A = 0x%lX: to B = 0x%lX\n",(unsigned long)A, (unsigned long)B);
    
    printf("Freeing A = 0x%lX from device \n",(unsigned long)A);
    omp_target_free(/*dev_ptr*/ A,
                    /*dev_id*/  dev_id);

    printf("Values of B in the host are:\n");
    PRINT(B,20);

    return 0;
}
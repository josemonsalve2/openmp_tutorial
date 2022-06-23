#include <omp.h>

int main () {

    int *A; int B[100];
    int dev_id = omp_get_default_device();
    int host_id = omp_get_initial_device();

    A = omp_target_alloc(/*size*/ sizeof(int)*100,
                        /*dest_dev_id*/ dev_id);

    // This will generate a runtime error if not unified shared memory
    // A is a pointer to the device
    // *A = 5; ERROR

    omp_target_memcpy(/*dest_ptr*/ A,
                    /*src_ptr*/ B, 
                    /*length*/ sizeof(int)*100, 
                    /*offset_dst*/ 0, 
                    /*offset_src*/ 0, 
                    /*dest_dev_id*/ dev_id, 
                    /*src_dev_id*/ host_id);

    omp_target_free(/*dev_ptr*/ A,
                    /*dev_id*/  dev_id);

    return 0;
}
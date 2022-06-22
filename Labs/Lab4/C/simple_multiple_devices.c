#include <stdio.h>
#include <omp.h>

int main() {
    int device_num[omp_get_num_devices()+1] = {0};
    int i;
    // Iterate over each available device and execute code
    // If i == omp_get_num_devices(), execute on the host.
    for (i = 0; i <= omp_get_num_devices(); i++) {
        #pragma omp target device(i) if(i!=omp_get_num_devices())
        {
            device_num[0] = omp_get_device_num();
        }
    }

    // Print which device was used for each region.
    for (i = 0; i <= omp_get_num_devices(); i++)
        printf("Code executed for i = %d in device %d\n", i,device_num[i]);
    return 0;
}
#include <stdio.h>
#include <omp.h>

int main() {
    int i, num_dev = omp_get_num_devices();
    // Max num dev to 10 just for simpler code
    num_dev = num_dev > 10 ? 10 : num_dev;
    int device_num[11];
    int initial_device[11];

    // Iterate over each available device and execute code
    // If i == omp_get_num_devices(), execute on the host.
    for (i = 0; i <= num_dev; i++) {
        #pragma omp target device(i) if(i!=num_dev)
        {
            device_num[i] = omp_get_device_num();
            initial_device[i] = omp_is_initial_device();
        }
    }

    // Print which device was used for each region.
    for (i = 0; i <= num_dev; i++)
        printf("Code executed for i = %d in device %d that is%s the initial device\n", 
                                                        i, device_num[i], initial_device[i]?"":" not");
    return 0;
}
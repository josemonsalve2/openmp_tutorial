#include <iostream>
#include <omp.h>

class exercise2 {
    private:
        int numElements;
        int sum;
        int *A;
    public:
        exercise2() = delete;
        exercise2(int numElmts) : numElements(numElmts), sum(0), A(nullptr) {
            std::cout << "Allocating array in the device" << std::endl;
            // Hint: classes need to map all its members
            // Add here
        }

        void init_array() {
            std::cout << "Initializing array in the device" << std::endl;
            // Add here
            {
                for (int i = 0; i < numElements; i++)
                {
                    A[i] = 1;
                }
            }
        }

        void compute_sum() {
            std::cout << "Computing sum" << std::endl;
            // Add here
            {
                for (int i = 0; i < numElements; i++)
                {
                    sum += A[i];
                }
            }
            // Hint: classes need to map all its members, sum may be mapped to the device already
            // Add here
            std::cout << "Sum of array with "  << numElements << " elements is " << sum << std::endl;
        }

        ~exercise2() {
            // Add here
            std::cout << "Deallocating array in the device" << std::endl;
        }
};

int main() {

    exercise2 Ex2(1000);

    Ex2.init_array();
    Ex2.compute_sum();

}  
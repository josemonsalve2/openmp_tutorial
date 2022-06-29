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
            #pragma omp target enter data map(to:numElements, sum) map(alloc:A[0:numElements])
        }

        void init_array() {
            std::cout << "Initializing array in the device" << std::endl;
            #pragma omp target
            {
                for (int i = 0; i < numElements; i++)
                {
                    A[i] = 1;
                }
            }
        }

        void compute_sum() {
            std::cout << "Computing sum" << std::endl;
            #pragma omp target
            {
                for (int i = 0; i < numElements; i++)
                {
                    sum += A[i];
                }
            }
            #pragma omp target update from(sum)
            std::cout << "Sum of array with "  << numElements << " elements is " << sum << std::endl;
        }

        ~exercise2() {
            std::cout << "Deallocating array in the device" << std::endl;
            #pragma omp target exit data map(delete:this[0:1], A)
        }
};

int main() {

    exercise2 Ex2(1000);

    Ex2.init_array();
    Ex2.compute_sum();

}  
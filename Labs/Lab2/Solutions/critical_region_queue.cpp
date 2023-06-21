#include <iostream>
#include <vector>
#include <omp.h>
#include <random>

// This will be our global queue
std::vector<int> queue;

// This function will produce 10 random elements and push them to the queue
void produce_elements()
{
    for (int i = 0; i < 10; i++)
    {
#pragma omp critical
        {
            int random = rand() % 100;
            queue.push_back(random);
        }
    }
}

// This function will consume from the queue until it has consumed the expected number of elements
void consume_elements(int expectedElemets)
{
    int i = 0;
    while (i < expectedElemets)
    {
        int value;
        if (queue.size() == 0)
            continue;
#pragma omp critical
        {
            i++;
            value = queue.front();
            queue.erase(queue.begin());
        }
        std::cout << "Consumer took " << value << " from the queue." << std::endl;
    }
}

int main()
{
#pragma omp parallel num_threads(10)
    {

        // Each thread adds 10 elements to the queue
        produce_elements();

#pragma omp masked
        {
            // A single thread consumes all the elements from the queue
            int expectedElements = 10 * omp_get_num_threads();
            consume_elements(expectedElements);
        }
    }
    return 0;
}

// Algorytm Fishera-Yatesa

#include <iostream>
#include <vector>
#include <random>

void sampleData(std::vector<int> &A, int k)
{
    std::random_device seed;  // seed
    std::mt19937 gen(seed()); // random seeded number generator

    for (size_t i = 0; i < k; i++)
    {
        std::uniform_int_distribution<int> distrib(i, A.size() - 1); // pack the generated number into the correct distribution
        std::swap(A[i], A[distrib(gen)]);
    }
}

int main()
{
    std::vector<int> A = {1, 2, 3, 4, 5};
    int k = 3;

    sampleData(A, k);

    std::cout << "Generated subseries : ";
    for (size_t i = 0; i < k; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
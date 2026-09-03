#include <vector>
#include <iostream>

std::vector<int> multiplyArrays(std::vector<int> &A, std::vector<int> &B)
{
    std::vector<int> result(A.size() + B.size(), 0);

    // sign handling
    int sign = A[0] * B[0] >= 0 ? 1 : -1;
    A[0] = std::abs(A[0]);
    B[0] = std::abs(B[0]);

    // arytmetyka
    for (int i = A.size() - 1; i >= 0; --i)
    {
        for (int j = B.size() - 1; j >= 0; --j)
        {
            result[i + j + 1] += A[i] * B[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    // obsluga zer
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != 0)
        {
            result[i] *= sign;
            return {result.begin() + i, result.end()};
        }
    }

    // jesli same zera to zwracamy jedno zero
    return {0};
}

int main()
{
    std::vector A1 = {9, 0};
    std::vector B1 = {9, 0};
    std::vector result1 = multiplyArrays(A1, B1);

    for (auto elem : result1)
    {
        std::cout << elem;
    }

    std::cout << std::endl;

    std::vector A2 = {1, 9, 3, 7, 0, 7, 7, 2, 1};
    std::vector B2 = {
        -7,
        6,
        1,
        8,
        3,
        8,
        2,
        5,
        7,
        2,
        8,
        7};
    std::vector result2 = multiplyArrays(A2, B2);

    for (auto elem : result2)
    {
        std::cout << elem;
    }

    std::cout << std::endl;

    std::vector A3 = {0};
    std::vector B3 = {0};
    std::vector result3 = multiplyArrays(A3, B3);

    for (auto elem : result3)
    {
        std::cout << elem;
    }

    std::cout << std::endl;

    std::vector A4 = {1, 9};
    std::vector B4 = {3};
    std::vector result4 = multiplyArrays(A4, B4);

    for (auto elem : result4)
    {
        std::cout << elem;
    }

    std::cout << std::endl;
}
#include <iostream>
#include <vector>

void apply_permutation(std::vector<int> &A, std::vector<int> P)
{
    for (int i = 0; i < A.size(); i++)
    {
        int current = A[i];
        int whereToGoNext = P[i];
        P[i] = -1;

        while (whereToGoNext != -1)
        {
            int temp = A[whereToGoNext];
            A[whereToGoNext] = current;
            current = temp;

            int temp2 = whereToGoNext;
            whereToGoNext = P[whereToGoNext];
            P[temp2] = -1;
        }
    }
}

void run_test(int test_id, std::vector<int> A, std::vector<int> P, const std::vector<int> &expected)
{
    apply_permutation(A, P);
    if (A == expected)
    {
        std::cout << "[TEST " << test_id << "] OK!\n";
    }
    else
    {
        std::cout << "[TEST " << test_id << "] BLAD!\n";
        std::cout << "  Otrzymano: [ ";
        for (int x : A)
            std::cout << x << " ";
        std::cout << "]\n  Oczekiwano: [ ";
        for (int x : expected)
            std::cout << x << " ";
        std::cout << "]\n";
    }
}

int main()
{
    // Test 1
    run_test(1, {10, 20, 30, 40}, {2, 0, 1, 3}, {20, 30, 10, 40});
    // Test 2
    run_test(2, {1, 2, 3, 4}, {1, 0, 3, 2}, {2, 1, 4, 3});
    // Test 3
    run_test(3, {5, 6, 7}, {0, 1, 2}, {5, 6, 7});
    // Test 4
    run_test(4, {99}, {0}, {99});
    // Test 5
    run_test(5, {1, 2, 3, 4, 5}, {4, 3, 2, 1, 0}, {5, 4, 3, 2, 1});

    return 0;
}
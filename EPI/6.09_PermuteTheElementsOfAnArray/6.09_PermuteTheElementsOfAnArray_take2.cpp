#include <vector>
#include <iostream>

std::vector<int> apply_permutation(std::vector<int> &A, std::vector<int> &P)
{
    // - z dodatkowa pamiecia rozwiazania jest trywialne, ale chcemy rozwiazanie in-place
    // - kazda permutacje mozna rozlozyc na k rozlacznych cyklow

    for (int i = 0; i < A.size(); i++)
    {
        // permutacja juz zbadana
        if (P[i] == -1)
        {
            continue;
        }

        int curr = A[i];
        int next = P[i];
        P[i] = -1; // mark odwiedzony

        // idziemy przez cykl
        while (next != -1)
        {
            // zmieniamy A
            int temp = A[next];
            A[next] = curr;

            // aktualizujemy curr, next i zmieniamy wartosc na -1
            curr = temp;
            int temp2 = next;
            next = P[next];
            P[temp2] = -1;
        }
    }

    return A;
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
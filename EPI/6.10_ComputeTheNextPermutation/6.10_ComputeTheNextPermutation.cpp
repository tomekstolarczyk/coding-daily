#include <iostream>
#include <vector>
#include <algorithm> // std::reverse

std::vector<int> nextPermutation(std::vector<int> p)
{
    // 1 szukamy punktu przelamania - pivota - czyli idac od prawej pierwszego mniejszego elementu od pozostalych
    int i = p.size() - 2;
    while (i >= 0)
    {
        if (p[i] < p[i + 1])
        {
            break;
        }

        i--;
    }

    // edge case - max mozliwa permutacja
    if (i == -1)
    {
        return {};
    }

    // 2 znajdujemy w ogonie najmniejszy element ktory jest wiekszy niz pivot
    // wystarczy ze idziemy od prawej bo mamy na pewno porzadek rosnacy
    int j = p.size() - 1;
    while (p[i] >= p[j])
    {
        j--;
    }

    // 3 swap pivota ze znalezionym elementem z kroku 2
    std::swap(p[i], p[j]);

    // 4 reverse ogona
    std::reverse(p.begin() + i + 1, p.end());

    return p;
}

int main()
{
    std::vector<int> p = {1, 0, 3, 2};

    std::vector<int> result = nextPermutation(p);

    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << (i + 1 < result.size() ? ", " : "");
    }
    std::cout << "]\n";

    return 0;
}
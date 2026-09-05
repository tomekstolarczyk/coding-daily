#include <vector>
#include <iostream>

// "a better approach is to compute the primes and when a number is identified as a prime,
// to sieve it i.e., remove all its multiples from future consideration"

std::vector<int>
enumPrimes(int n)
{
    if (n <= 1)
    {
        return {};
    }

    // create numeric vec
    std::vector<int> vec;
    vec.reserve(n);
    for (int i = 0; i < n; i++)
    {
        vec.push_back(i + 1);
    }
    std::cout << "num vec starting out : ";
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // logic mask - zakladamy z gory ze wszystkie sa liczbami pierwszymi poza jedynka
    std::vector<int> mask(n, true);
    mask[0] = false;
    std::cout << "logic mask starting out : ";
    for (const auto &elem : mask)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // faktyczna iteracja gdzie decydujemy co jest liczba pierwsza a co nie
    int iter = 1; // zaczynamy od dwojki
    while (iter < n)
    {
        // dla kazdej liczby po iter sprawdzamy czy podzielne przez vec[iter]
        for (int i = iter + 1; i < n; i++)
        {
            // jesli wiadomo juz ze nie liczba piewsza to skip
            if (mask[i] == false)
            {
                continue;
            }

            // warunek kluczowy
            if (vec[i] % vec[iter] == 0)
            {
                mask[i] = false;
            }
        }

        // na koniec jak przeszlismy przez wektor raz to zwiekszamy iter az nie znajdziemy nastepnej pierwszej
        iter++;
        while (iter < n && mask[iter] == false)
        {
            iter++;
        }
    }

    // wektor wynikowy
    std::vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (mask[i] == true)
        {
            result.push_back(vec[i]);
        }
    }

    return result;
}

int main()
{
    std::cout << "TEST 1:" << std::endl;
    std::vector<int> test1 = enumPrimes(9);
    std::cout << "wektor wynikowy 1 : ";
    for (const auto &elem : test1)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "TEST 2:" << std::endl;
    std::vector<int> test2 = enumPrimes(15);
    std::cout << "wektor wynikowy 2 : ";
    for (const auto &elem : test2)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
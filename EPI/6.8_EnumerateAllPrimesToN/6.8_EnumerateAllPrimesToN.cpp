#include <iostream>
#include <vector>

// sito eratostenesa

std::vector<int> erastothenesLookingForPrimes(int n)
{
    // 1 tworzymy wektor wynikowy <0,1,2...n>
    std::vector<bool> primes(n + 1, true);

    // 2 zero i jedynka odpadaja na start
    primes[0] = false;
    primes[1] = false;

    // 3 lecimy od dwojki i dla kazdego nastepnego prima usuwamy jego wielekrotnosci
    int i = 2;
    while (i <= n)
    {
        if (primes[i] == true)
        {
            int j = i + i; // zaczynamy od pierwszej wielokrtnosci i
            while (j <= n)
            {
                primes[j] = false;
                j += i;
            }
        }

        i++;
    }

    // 4 konwertujemy wektor logiczny <0,1,...n> na liczbowy <2, ...>
    std::vector<int> result;
    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i] == true)
        {
            result.push_back(i);
        }
    }

    return result;
}

// helper
void printVector(const std::vector<int> &v)
{
    std::cout << "{ ";
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    std::cout << "}\n";
}

int main()
{
    // Test 1
    int n1 = 18;
    std::cout << "Primes up to " << n1 << ":\n";
    std::cout << "Expected: { 2, 3, 5, 7, 11, 13, 17 }\n";
    std::cout << "Result:   ";
    printVector(erastothenesLookingForPrimes(n1));
    std::cout << "-----------------------\n";

    // Test 2
    int n2 = 2;
    std::cout << "Primes up to " << n2 << ":\n";
    std::cout << "Expected: { 2 }\n";
    std::cout << "Result:   ";
    printVector(erastothenesLookingForPrimes(n2));
    std::cout << "-----------------------\n";

    // Test 3
    int n3 = 1;
    std::cout << "Primes up to " << n3 << ":\n";
    std::cout << "Expected: { }\n";
    std::cout << "Result:   ";
    printVector(erastothenesLookingForPrimes(n3));
    std::cout << "-----------------------\n";

    // Test 4
    int n4 = 30;
    std::cout << "Primes up to " << n4 << ":\n";
    std::cout << "Expected: { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 }\n";
    std::cout << "Result:   ";
    printVector(erastothenesLookingForPrimes(n4));
    std::cout << "-----------------------\n";

    return 0;
}
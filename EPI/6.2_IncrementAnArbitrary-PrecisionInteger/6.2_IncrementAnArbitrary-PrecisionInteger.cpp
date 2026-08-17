#include <iostream>
#include <vector>

void incrementAnArbitraryPrecisionInteger(std::vector<int>& A)
{
    int i = A.size()-1;
    A[i]++;

    while(i > 0 && A[i] == 10)
    {
        A[i] = 0;
        i--;
        A[i]++;
    }

    // pierwszy element - same dziewiatki : 999 -> 1000
    if(A[i] == 10) 
    {
        A[i] = 1;
        A.push_back(0);
    }
    
}

int main()
{
    // Test 1
    std::vector<int> num1 = {1, 2, 8};
    std::cout << "Test 1: ";
    for (int digit : num1)
    {
        std::cout << digit;
    }
    std::cout << "\n";
    incrementAnArbitraryPrecisionInteger(num1);
    std::cout << "Wynik:  ";
    for (int digit : num1)
    {
        std::cout << digit;
    }
    std::cout << "\n";
    std::cout << "--------------------\n";

    // Test 2
    std::vector<int> num2 = {1, 2, 9, 9};
    std::cout << "Test 2: ";
    for (int digit : num2)
    {
        std::cout << digit;
    }
    std::cout << "\n";
    incrementAnArbitraryPrecisionInteger(num2);
    std::cout << "Wynik:  ";
    for (int digit : num2)
    {
        std::cout << digit;
    }
    std::cout << "\n";
    std::cout << "--------------------\n";

    // Test 3
    std::vector<int> num3 = {9, 9, 9, 9};
    std::cout << "Test 3: ";
    for (int digit : num3)
    {
        std::cout << digit;
    }
    std::cout << "\n";
    incrementAnArbitraryPrecisionInteger(num3);
    std::cout << "Wynik:  ";
    for (int digit : num3)
    {
        std::cout << digit;
    }
    std::cout << "\n";
    std::cout << "--------------------\n";

    return 0;
}
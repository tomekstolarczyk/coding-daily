#include <iostream>
#include <vector>

int deleteDuplicates(std::vector<int> &A)
{
    // empty array edge case
    if (A.empty())
    {
        return 0;
    }

    size_t i = 1; // place for next unique digit
    size_t j = 1; // checker for uniquenes

    while (j < A.size())
    {
        // found a new unique digit
        if (A[j - 1] != A[j])
        {
            A[i] = A[j];
            i++;
        }

        // otherwise just get on with it
        j++;
    }

    // czyscimy reszte
    for (size_t k = i; k < A.size(); k++)
    {
        A[k] = 0;
    }

    return i; // number of unique elements
}

void printResult(const std::string &testName, const std::vector<int> &vec, int validCount)
{
    std::cout << testName << "\nLiczba unikalnych: " << validCount << "\nStan wektora: [ ";
    for (int i = 0; i < vec.size(); ++i)
    {
        if (i == validCount)
            std::cout << "| ";
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n------------------------------------\n";
}

int main()
{
    std::vector<int> test1 = {2, 3, 5, 5, 7, 11, 11, 11, 13};
    int count1 = deleteDuplicates(test1);
    printResult("Test 1", test1, count1);

    std::vector<int> test2 = {};
    int count2 = deleteDuplicates(test2);
    printResult("Test 2", test2, count2);

    std::vector<int> test3 = {1, 2, 3, 4, 5};
    int count3 = deleteDuplicates(test3);
    printResult("Test 3", test3, count3);

    std::vector<int> test4 = {7, 7, 7, 7, 7};
    int count4 = deleteDuplicates(test4);
    printResult("Test 4", test4, count4);

    return 0;
}
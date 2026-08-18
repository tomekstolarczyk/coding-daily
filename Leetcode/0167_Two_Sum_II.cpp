#include <vector>
using namespace std;

class Solution
{
public:
    // oczywiscie mozna bruteforcowo po kolei dla kazdego sprawdzac czy jest jakis ktory sie dodaje ale to potworna zlozonosc
    // mimo to chcemy matchoawc ze soba 2 rozne liczby a tablica jest nondescending order -> 2 pointers
    // "There will always be exactly one valid solution"

    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int index1 = 0, index2 = numbers.size() - 1;

        while (index1 < index2)
        {
            // win condition
            if (numbers[index1] + numbers[index2] == target)
            {
                return {index1 + 1, index2 + 1}; // tablica 1 based
            }

            if (numbers[index1] + numbers[index2] > target)
            {
                index2--;
            }
            else
            {
                index1++;
            }
        }

        return {};
    }
};

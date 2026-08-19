#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 1 oczywiscie one way to do it is bruteforcowo kazdy z kazdym
// 2 mozna tez posortowac + 2 pointers ale to nam wrzuca zlozonosc na O(nlogn)
// 3 wiec sprobujemy jeszcze innej techniki - haszowanie - to da nam dodatkowy narzut na pamiec ale za to zlozonosc O(n)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> haszMapa; // klucz to wartosc elementu, przechowujemy indexy
        // idziemy przez cala tablice - dla kazdego elementu sprawdzamy czy jego dopelnienie znajduje sie w naszej mapie
        for (int i = 0; i < nums.size(); i++)
        {
            int poszukiwanyKlucz = target - nums[i];

            // jesli juz w naszej hasz mapie mamy dopelnienie to zwracamy
            std::unordered_map<int, int>::iterator it = haszMapa.find(poszukiwanyKlucz);
            if (it != haszMapa.end())
            {
                int index = it->second;
                return {index, i};
            }

            // jesli nie to dodajemy ta wartosc do hasz mapy i idziemy dalej
            haszMapa[nums[i]] = i;
        }

        return {};
    }
};

void runTest(Solution &solver, vector<int> nums, int target)
{
    vector<int> result = solver.twoSum(nums, target);
    cout << "nums: [";
    for (size_t i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << (i + 1 < nums.size() ? ", " : "");
    }
    cout << "], target: " << target << " -> wynik: [";
    if (result.size() == 2)
    {
        cout << result[0] << ", " << result[1];
    }
    cout << "]\n";
}

int main()
{
    Solution solver;

    // Test 1: Standardowy przypadek
    runTest(solver, {2, 7, 11, 15}, 9); // Oczekiwane: [0, 1]
    // Test 2: Elementy nie na początku
    runTest(solver, {3, 2, 4}, 6); // Oczekiwane: [1, 2]
    // Test 3: Dwa takie same elementy
    runTest(solver, {3, 3}, 6); // Oczekiwane: [0, 1]
    // Test 4: Liczby ujemne
    runTest(solver, {-1, -2, -3, -4, -5}, -8); // Oczekiwane: [2, 4]

    return 0;
}
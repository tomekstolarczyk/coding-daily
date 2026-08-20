// 3 sum
using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>

// - oczywiscie mozna O(n^3) brute forcowo, ale schodzimy nizej do O(n^2)
// - tutaj w przeciwienstwie do 2sum sorotowanie jest lespze niz petla O(n^2) wiec sorotwanie + 2 pointers super
// bo nie zuzyjemy dodatkowej pamieci O(n) na hash set
// - lecimy z tym sort a ppotem na posortowanej dla kazdego elementu po kolei 2 sum z 2 pointersami essa
// - dodatkowo dzieki sorotowaniu rozwiazuje nam sie mega prosto problem koniecznosci braku duplikatow

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> results;

        // 1 sort
        sort(nums.begin(), nums.end());

        // 2 dla kazdego elementu fixujemy go w pozycji i lecimy dalej z 2 sum
        for (int i = 0; i < nums.size(); i++)
        {
            // problem duplikatow [-1,-1,0,1] zwrociloby dwa razy [-1,0,1] -> pomijamy drugie -1
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // skoro tablica jest posortowana, trójki wystarczy szukać tylko na prawo od elementu i
            // znow, to pomoze nam uniknac duplikatow
            int frst = i + 1;
            int scnd = nums.size() - 1;

            while (frst < scnd)
            {
                if (nums[frst] + nums[i] + nums[scnd] == 0)
                {
                    results.push_back({nums[i], nums[frst], nums[scnd]});

                    // [-2, 0, 0, 2, 2] po znalezieniu sumy zero musimy przesunac powtarzajace sie wartosci
                    while (frst < scnd && nums[frst] == nums[frst + 1])
                    {
                        frst++;
                    }
                    while (frst < scnd && nums[scnd] == nums[scnd - 1])
                    {
                        scnd--;
                    }

                    // przesuwamy oba bo jesli tylko jeden to ten jeden juz nigdy nic nie zrobi z drugim
                    frst++;
                    scnd--;
                }

                else if (nums[frst] + nums[i] + nums[scnd] > 0)
                {
                    scnd--;
                }

                else
                {
                    frst++;
                }
            }
        }

        return results;
    }
};

void printResult(const vector<vector<int>> &res)
{
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i)
    {
        cout << "[";
        for (size_t j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << (j + 1 < res[i].size() ? ", " : "");
        }
        cout << "]" << (i + 1 < res.size() ? ", " : "");
    }
    cout << "]\n";
}

int main()
{
    Solution sol;

    // Test 1
    vector<int> test1 = {-1, 0, 1, 2, -1, -4};
    cout << "Test 1 (Oczekiwane: [[-1, -1, 2], [-1, 0, 1]]): \nWynik: ";
    printResult(sol.threeSum(test1));

    // Test 2
    vector<int> test2 = {0, 0, 0, 0};
    cout << "\nTest 2 (Oczekiwane: [[0, 0, 0]]): \nWynik: ";
    printResult(sol.threeSum(test2));

    // Test 3
    vector<int> test3 = {0, 1, 1};
    cout << "\nTest 3 (Oczekiwane: []): \nWynik: ";
    printResult(sol.threeSum(test3));

    // Test 4
    vector<int> test4 = {-2, 0, 0, 2, 2};
    cout << "\nTest 4 (Oczekiwane: [[-2, 0, 2]]): \nWynik: ";
    printResult(sol.threeSum(test4));

    return 0;
}
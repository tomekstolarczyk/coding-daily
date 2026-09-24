#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int frontier = 0;
        int backtier = numbers.size() - 1;

        while (frontier < backtier)
        {
            if (numbers[frontier] + numbers[backtier] == target)
            {
                return {frontier + 1, backtier + 1};
            }

            else if (numbers[frontier] + numbers[backtier] > target)
            {
                // obsluga duplikatow
                while (frontier < backtier && numbers[backtier] == numbers[backtier - 1])
                {
                    backtier--;
                }

                backtier--;
            }

            else
            {
                // obsluga duplikatow
                while (frontier < backtier && numbers[frontier] == numbers[frontier + 1])
                {
                    frontier++;
                }

                frontier++;
            }
        }

        return {};
    }
};

int main()
{
    Solution sol1;
    vector<int> nums1 = {2, 7, 11, 11, 11, 15};
    int target1 = 9;
    // expected output [1,2]
    vector<int> res1 = sol1.twoSum(nums1, target1);
    for (const auto &elem : res1)
    {
        cout << elem << " ";
    }
    cout << endl;

    Solution sol2;
    vector<int> nums2 = {2, 3, 4};
    int target2 = 6;
    // expected output [1,3]
    vector<int> res2 = sol1.twoSum(nums2, target2);
    for (const auto &elem : res2)
    {
        cout << elem << " ";
    }
    cout << endl;

    Solution sol3;
    vector<int> nums3 = {-1, 0};
    int target3 = -1;
    // expected output [1,2]
    vector<int> res3 = sol1.twoSum(nums3, target3);
    for (const auto &elem : res3)
    {
        cout << elem << " ";
    }
    cout << endl;
}
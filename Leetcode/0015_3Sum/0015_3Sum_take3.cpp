#include <vector>
#include <iostream>
#include <algorithm> // for the sorting algo

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that
// i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// WARNING : Notice that the solution set must not contain duplicate triplets.

// so for regular 2 sum we want to go for the hashmap O(n) + O(n) memory but here were gonna be doing it O(n^2) either way
// sor the O(nlogn) sorting wont make the complexity higher and it will help us deal with duplicates
// so sort + 2 pointers technique easyy

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {

        if (nums.size() < 3)
        {
            return {};
        }

        std::vector<std::vector<int>> results;

        std::sort(nums.begin(), nums.end());

        // 1 n loop and then its just a 2sum problem
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else // == 0
                {
                    results.push_back({nums[i], nums[j], nums[k]});

                    // skip all duplicate numbers
                    while (j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    }

                    while (j < k && nums[k - 1] == nums[k])
                    {
                        k--;
                    }

                    // now we jump to the next number for both of them
                    j++;
                    k--;
                }
            }
        }

        return results;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result1 = solution.threeSum(nums1);
    for (int i = 0; i < result1.size(); i++)
    {
        std::cout << "[ ";
        for (const auto &element : result1[i])
        {
            std::cout << element << " ";
        }
        std::cout << "]" << std::endl;
    }
}
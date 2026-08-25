#include <vector>
#include <iostream>

// return -1 if not in nums, index if in nums

class Solution
{
public:
    int searchRotated(const std::vector<int> &nums, int target, int left, int right)
    {
        // ket trick : zawsze przynajmniej jedna polowka jest idealnie posortowana

        if (left > right)
        {
            return -1;
        }

        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        bool leftSorted;
        if (nums[left] <= nums[mid])
        {
            leftSorted = true;
        }
        else
        {
            leftSorted = false;
        }

        if (leftSorted == true)
        {
            if (target >= nums[left] && target <= nums[mid])
            {
                return searchRotated(nums, target, left, mid - 1);
            }
            else
            {
                return searchRotated(nums, target, mid + 1, right);
            }
        }
        else
        {
            if (target >= nums[mid] && target <= nums[right])
            {
                return searchRotated(nums, target, mid + 1, right);
            }
            else
            {
                return searchRotated(nums, target, left, mid - 1);
            }
        }
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = solution.searchRotated(nums, target, 0, nums.size() - 1);
    // result == 4
    std::cout << result;
}
#include <iostream>
#include <vector>
using namespace std;

// zawsze jedna polowa jest posegregowana - tats the trick 

class Solution {

public:

    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        return searchRotated(nums, target, left, right);
    }

    int searchRotated(vector<int>& nums, int target, int left, int right)
    {
        if(left>right) {return -1;}

        int mid = (left + right) / 2;
        if(nums[mid]==target) {return mid;}

        int leftSorted;
        if(nums[left]<=nums[mid])
        {
           leftSorted=1;
        }
        else
        {
            leftSorted=0;
        }

        if(leftSorted)
        {
            if(target>=nums[left] && target <= nums[mid])
            {
                return searchRotated(nums, target, left, mid-1);
            }
            else
            {
                return searchRotated(nums, target, mid+1,right);
            }
        }
        else
        {
            if(target>=nums[mid] && target <= nums[right])
            {
                return searchRotated(nums, target, mid+1, right);
            }
            else
            {
                return searchRotated(nums,target,left,mid-1);
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


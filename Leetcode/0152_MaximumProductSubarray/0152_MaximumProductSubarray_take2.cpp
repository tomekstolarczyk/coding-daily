#include <vector>
#include <algorithm>

int maxProdSub(const std::vector<int> &nums)
{
    int currMax = nums[0], currMin = nums[0], result = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int temp = currMax;
        currMax = std::max({nums[i], currMax * nums[i], currMin * nums[i]});
        currMin = std::min({nums[i], temp * nums[i], currMin * nums[i]});
        result = std::max(currMax, result); // to trzyma najlepszy wynik w historii
    }

    return result;
}

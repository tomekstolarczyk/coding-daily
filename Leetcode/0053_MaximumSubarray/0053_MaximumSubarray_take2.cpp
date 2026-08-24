#include <vector>

int maximumSubarray(std::vector<int> &A)
{
    int currentSum = 0;
    int maxSum = A[0];

    for (int i = 0; i < A.size(); i++)
    {
        currentSum += A[i];

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    return maxSum;
}
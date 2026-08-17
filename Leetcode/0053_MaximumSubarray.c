#include<stdio.h>
#include<stdlib.h>

int maxSubArray(int* nums, int numsSize) 
{
    int sumRightNow = 0;
    int maxSumOverall = nums[0];

    for (size_t i =0; i<numsSize; i++)
    {
        sumRightNow += nums[i];

        if(sumRightNow > maxSumOverall)
        {
            maxSumOverall = sumRightNow;
        }

        if(sumRightNow < 0)
        {
            sumRightNow = 0;
        }
    }

    return maxSumOverall;
}

int main(void)
{
    int case1[] = {-2,1,-3,4,-1,2,1,-5,4};
    int size1 = sizeof(case1)/sizeof(int);
    int sum1 = maxSubArray(case1,size1);
    printf("sum = %d, expected = 6\n",sum1);

    int case2[] = {1};
    int size2 = sizeof(case2)/sizeof(int);
    int sum2 = maxSubArray(case2,size2);
    printf("sum = %d, expected = 1\n",sum2);

    int case3[] = {5,4,-1,7,8};
    int size3 = sizeof(case3)/sizeof(int);
    int sum3 = maxSubArray(case3,size3);
    printf("sum = %d, expected = 23\n",sum3);

    int case4[] = {-1};
    int size4 = sizeof(case4)/sizeof(int);
    int sum4 = maxSubArray(case4,size4);
    printf("sum = %d, expected = -1\n",sum4);

    int case5[] = {-2,-1};
    int size5 = sizeof(case5)/sizeof(int);
    int sum5 = maxSubArray(case5,size5);
    printf("sum = %d, expected = -1\n",sum5);

}

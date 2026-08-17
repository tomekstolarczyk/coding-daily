#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// qsort requires a compare function
int compare(const void* a, const void* b)
{
    int a_val = *(const int*) a;
    int b_val = *(const int*) b;

    if(a_val>b_val) {return 1;}
    if(b_val>a_val) {return -1;}
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {

    // 1 sort first 
    qsort(nums, numsSize, sizeof(int), compare);

    // 2 just iter through the sorted list [1,2,3,3,4]
    for(size_t i = 0; i< numsSize-1; i++)
    {
        if (nums[i]==nums[i+1])
        {
            return true;
        }
    }
    
    return false;
}
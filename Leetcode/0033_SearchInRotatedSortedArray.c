#include <stdio.h>

// funkcja po naszemu, lepsze argumenty 
int helper(int* nums, int left, int right, int target)
{
    if (left > right) {return -1;} // liczby nie ma w tablicy
    
    int mid = left + (right-left)/2;
    if(nums[mid] == target) {return mid;}

    // jedna polowka na pewno posortowana lub obie
    int rSorted; 
    if(nums[mid]<nums[right]) {rSorted = 1;}
    else{rSorted =0;} 

    if(rSorted) 
    {
        if(target > nums[mid] && target <= nums[right]) 
        {
            return helper(nums,mid+1, right, target);
        }
        else
        {
            return helper(nums,left, mid-1, target);
        }
    }

    else // jak prawa nie jest posortowana to lewa musi byc
    {
        if(target < nums[mid] && target >= nums[left]) 
        {
            return helper(nums,left, mid-1, target); // wszystko co przed midem
        }
        else
        {
            return helper(nums,mid+1, right, target); // wszystko co za midem
        }
    }

}

// Funkcja, której wymaga LeetCode
int search(int* nums, int numsSize, int target) {

    return helper(nums, 0, numsSize-1,target);

}

int main(void)
{
    int nums1[] = {4,5,6,7,0,1,2};
    int numssize1 = sizeof(nums1)/sizeof(int);
    int target11 = 0;
    int res11 = search(nums1,numssize1, target11);
    printf("case 1 : ex = 4 : result = %d\n", res11);
    int target12 = 3;
    int res12 = search(nums1,numssize1, target12);
    printf("case 2 : ex = -1 : result = %d\n", res12);

    int nums2[] = {1};
    int numssize2 = sizeof(nums2)/sizeof(int);
    int target21 = 0;
    int res21 = search(nums2,numssize2, target21);
    printf("case 3 : ex = -1 : result = %d\n", res21);

    int nums3[] = {6, 7, 0, 1, 2, 4, 5};
    int numssize3 = sizeof(nums3)/sizeof(int);
    int target31 = 0;
    int res31 = search(nums3,numssize3, target31);
    printf("case 4 : ex = 2 : result = %d\n", res31);

    int nums4[] = {6, 7, 0, 1, 2, 4, 5};
    int numssize4 = sizeof(nums4)/sizeof(int);
    int target41 = 9;
    int res41 = search(nums4,numssize4, target41);
    printf("case 5 : ex = -1 : result = %d\n", res41);
}
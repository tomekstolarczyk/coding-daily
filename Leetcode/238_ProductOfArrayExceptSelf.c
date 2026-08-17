#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    //prefix
    int* p = malloc(sizeof(int)*numsSize);
    int runningPreProduct;
    p[0] = 1;
    for(size_t i = 1; i<numsSize; i++)
    {
        p[i] = p[i-1]*nums[i-1];
    }

    //sufix
    int* s = malloc(sizeof(int)*numsSize);
    int runningSufProduct;
    s[numsSize-1] = 1;
    for(int i = numsSize-2; i>=0; i--)
    {
        s[i] = nums[i+1]*s[i+1];
    }

    //result
    *returnSize = numsSize;
    int* result = malloc(sizeof(int)*(*returnSize));
    for(size_t i = 0; i<numsSize; i++)
    {
        result[i] = p[i]*s[i];
    }

    free(p);
    free(s);

    

    return result;
    
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {

    // --- TEST CASE 1 ---
    int nums1[] = {1, 2, 3, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1 = 0;
    
    printf("=== Test Case 1 ===\n");
    printf("Input:    ");
    printArray(nums1, size1);
    
    int* result1 = productExceptSelf(nums1, size1, &returnSize1);
    
    printf("Output:   ");
    printArray(result1, size1); 
    printf("Expected: [24, 12, 8, 6]\n\n");
    
    if (result1 != NULL) free(result1);

    // --- TEST CASE 2 ---
    int nums2[] = {-1, 1, 0, -3, 3};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2 = 0;
    
    printf("=== Test Case 2 ===\n");
    printf("Input:    ");
    printArray(nums2, size2);
    
    int* result2 = productExceptSelf(nums2, size2, &returnSize2);
    
    printf("Output:   ");
    printArray(result2, size2);
    printf("Expected: [0, 0, 9, 0, 0]\n\n");
    
    if (result2 != NULL) free(result2);

    return 0;
}
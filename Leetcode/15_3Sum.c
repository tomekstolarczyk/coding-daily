#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    int* elementA = (int*) a;
    int* elementB = (int*) b;
    int A = *elementA;
    int B = *elementB;
    if(A>B) {return 1;}
    if(A<B) {return -1;}
    else {return 0;}
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = 0;
    if(numsSize<3)
    {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // 1. sortujemy - konieczne do 2 pointers bedzie
    qsort(nums, numsSize, sizeof(int), compare);

    // 2. dla kazdej trojki fixujemy jeden, dalej to juz jak 2sum tylko lekko rozbudowany
    int target, p1, p2;

    // mallocujemy w ciemno poki co
    int capacity = 100000;
    int** results = malloc(sizeof(int*)*(capacity));
    int d = 0; 
    *returnColumnSizes = malloc(capacity*(sizeof(int)));
    
    // i teraz jeszcze raz to samo ale juz wypelniamy dedicated trojkami
    for(size_t i = 0; i < numsSize; i++)
    {
        // skipujemy duplikaty zwiazane z fixem
        if (i>0) {if(nums[i]==nums[i-1]) {continue;}}
    
        target = -nums[i];
        p1 = i+1;
        p2 = numsSize-1;

        while(p1<p2)
        {
            if(nums[p1] + nums[p2] == target) 
            {
                // zbieramy wynik
                *returnSize += 1;
                (*returnColumnSizes)[d] = 3;
                results[d] = malloc(sizeof(int)*3);
                results[d][0] = nums[i];
                results[d][1] = nums[p1];
                results[d][2] = nums[p2];
                d++;

                // obsluga duplikatow zwiazanych z wartosciami na pointerach
                while(p1<p2 && nums[p2-1] == nums[p2]) {p2 -= 1;}
                while(p1<p2 && nums[p1+1] == nums[p1]) {p1 += 1;}
                // przesuwamy oba bo na pewno jak przesuniemy tylko 1 to w nastepnym kroku przesunie drugi
                p2--, p1++;
            }
            else if(nums[p1] + nums[p2] > target) {p2--;}
            else {p1++;} 
        }
    }
    return results;
}

int main(void)
{
    int returnSize;
    int* returnColumnSizes;

    int nums1[] = {-1,0,1,2,-1,-4};
    int size1 = sizeof(nums1)/sizeof(int);
    int** results1 = threeSum(nums1, size1, &returnSize, &returnColumnSizes);
    printf("case 1:\n");
    for(size_t i = 0; i<returnSize; i++)
    {
        printf("[%d, %d, %d]\n", results1[i][0], results1[i][1], results1[i][2]);
    }
    // czyscimy results1
    for(int i = 0; i < returnSize; i++) {free(results1[i]);}

    int nums2[] = {0,0,0};
    int size2 = sizeof(nums2)/sizeof(int);
    int** results2 = threeSum(nums2, size2, &returnSize, &returnColumnSizes);
    printf("case 2:\n");
    for(size_t i = 0; i<returnSize; i++)
    {
        printf("[%d, %d, %d]\n", results2[i][0], results2[i][1], results2[i][2]);
    }
    for(int i = 0; i < returnSize; i++) {free(results2[i]);}

    free(returnColumnSizes);
    return 0;
}
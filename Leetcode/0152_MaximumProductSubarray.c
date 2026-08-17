#include <stdio.h>

int maxProduct(int* nums, int numsSize) {
    
    int productRightNow = nums[0];
    int maxProduct1 = productRightNow;

    // zabezpieczenie przed zerem na poczatku
    if(productRightNow == 0) {productRightNow = 1;}

    // raz od przodu
    for (size_t i = 1; i<numsSize;i++)
    {
        productRightNow *= nums[i];
        if(productRightNow > maxProduct1) {maxProduct1 = productRightNow;}

        // na zerze musimy zrobic reset
        if(productRightNow == 0) {productRightNow = 1;}
    }

    // case 5 [3,-1,4] sie psuje - zapobiegniemy temu by travering from the right

    productRightNow = nums[numsSize-1];
    int maxProduct2 = productRightNow;

    if(productRightNow == 0) {productRightNow = 1;}

    for (int i = numsSize-2; i>=0;i--)
    {
        productRightNow *= nums[i];
        if(productRightNow > maxProduct2) {maxProduct2 = productRightNow;}

        // na zerze musimy zrobic reset
        if(productRightNow == 0) {productRightNow = 1;}
    }

    return maxProduct1 > maxProduct2 ? maxProduct1 : maxProduct2;
}

int main(void)
{   
    int case1[] = {2,3,-2,4};
    int size1 = sizeof(case1)/sizeof(int);
    int prod1 = maxProduct(case1,size1);
    printf("case 1 : max product = %d, expected = 6\n",prod1);

    int case2[] = {-2,0,-1};
    int size2 = sizeof(case2)/sizeof(int);
    int prod2 = maxProduct(case2,size2);
    printf("case 2 : max product = %d, expected = 0\n",prod2);

    int case3[] = {-2,0,1,2,-1};
    int size3 = sizeof(case3)/sizeof(int);
    int prod3 = maxProduct(case3,size3);
    printf("case 3 : max product = %d, expected = 2\n",prod3);

    int case4[] = {0,2};
    int size4 = sizeof(case4)/sizeof(int);
    int prod4 = maxProduct(case4,size4);
    printf("case 4 : max product = %d, expected = 2\n",prod4);

    int case5[] = {3,-1,4};
    int size5 = sizeof(case5)/sizeof(int);
    int prod5 = maxProduct(case5,size5);
    printf("case 5 : max product = %d, expected = 4\n",prod5);

    int case6[] = {-1,-2,-3,0};
    int size6 = sizeof(case6)/sizeof(int);
    int prod6 = maxProduct(case6,size6);
    printf("case 6 : max product = %d, expected = 6\n",prod6);
}
#include <stdio.h>

int buynsell(int* stox, int size)
{
    // idziemy sobie przez ta tablice zainteresowani dwoma rzeczami
    int minSoFar = stox[0];
    int result = 0;

    for(size_t i = 1; i < size; i++)
    {

        if(minSoFar > stox[i])
        {
            minSoFar = stox[i];
        }

        if (result < stox[i]-minSoFar)
        {
            result = stox[i]-minSoFar;
        }
    }

    return result;
}

int main(void)
{
    int prices1[] = {7,1,5,3,6,4};
    int size1 = sizeof(prices1)/sizeof(prices1[0]);
    int result1 = buynsell(prices1,size1);
    printf("case 1: %d\n",result1);

    int prices2[] = {7,6,4,3,1};
    int size2 = sizeof(prices2)/sizeof(prices2[0]);
    int result2 = buynsell(prices2,size2);
    printf("case 2: %d",result2);
}
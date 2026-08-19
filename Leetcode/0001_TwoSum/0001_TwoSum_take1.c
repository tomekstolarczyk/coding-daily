#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
 } TabulaRaza;

int comp(const void* a, const void* b)
{
    const TabulaRaza* elementA = (const TabulaRaza*) a;
    const TabulaRaza* elementB = (const TabulaRaza*) b;

    int val_a = elementA -> value;
    int val_b = elementB -> value;


    // robimy na odwrot niz w docsach bo chcemy sortowanie rosnace
    if(val_a < val_b) {return -1;}
    if(val_a > val_b) {return 1;}
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    // sortujemy
    // budujemy tablice structow zeby nie stracic informacji o indeksach

    TabulaRaza* tabulaRaza = malloc(numsSize * sizeof(TabulaRaza));
    if (tabulaRaza == NULL) {return NULL;}


    for (size_t i = 0; i<numsSize; i++)
    {
        tabulaRaza[i].value = nums[i];
        tabulaRaza[i].index = i;
    }

    qsort(tabulaRaza, numsSize, sizeof(TabulaRaza), comp);

    // posortowane juz

    // szukamy wyniku z two pointer technique

    TabulaRaza* pointer1 = tabulaRaza;
    TabulaRaza* pointer2 = &tabulaRaza[numsSize-1];

    int sum;
    int i = 0;
    int j = numsSize-1;

    do 
    {
        sum = pointer1 -> value + pointer2 -> value;

        if(sum < target)
        {
            i += 1;
            pointer1 = &tabulaRaza[i];
        }

        if(sum > target)
        {
            j -= 1;
            pointer2 = &tabulaRaza[j];
        }
    } while (i < j);

    // mamy wynik

    *returnSize = 2;
    int* wynikowa = (int*)malloc(sizeof(int)*2);
    wynikowa[0] = pointer1->index;
    wynikowa[1] = pointer2->index;

    free(tabulaRaza);

    return wynikowa;

}

int main() {
    
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize; 

    printf("Testowanie dla: nums = [2, 7, 11, 15], target = 9\n");
    int* result = twoSum(nums, numsSize, target, &returnSize);

    printf("Wynik: [%d, %d]\n", result[0], result[1]);
    int sum = nums[result[0]] + nums[result[1]];

    if (sum == target) {printf("STATUS: SUKCES! (Suma się zgadza)\n");} 
    else {printf("STATUS: BLAD! (Suma wynosi %d, a powinna %d)\n", sum, target);}

    free(result);
    return 0;
}
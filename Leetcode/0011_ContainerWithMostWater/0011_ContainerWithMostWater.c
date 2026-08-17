#include <stdio.h>

int maxArea(int* height, int heightSize) {
    
    // zastosujemy two pointer technique
    int i =  0;
    int j = heightSize-1;
    int H, length, Area, iBigger;
    int maxArea = 0;
    while(i<j)
    {
        // liczymy nowe parametry
        H = height[i] < height[j] ? height[i] : height[j]; 
        length = j-i;
        Area = H*length;

        // aktualizacja wyniku
        maxArea = maxArea < Area ? Area : maxArea;

        // przesuwamy odpowiedni pointer
        if(height[i] < height[j]) {i++;}
        else{j--;}
    }
    
    
    return maxArea;
}

int main(void)
{
    int height1[] = {1,8,6,2,5,4,8,3,7};
    int size1 = 9;
    int result1= maxArea(height1, size1);
    printf("result : %d\n", result1);

    int height2[] = {8,7,2,1};
    int size2 = 4;
    int result2= maxArea(height2, size2);
    printf("result : %d\n", result2);
    
}
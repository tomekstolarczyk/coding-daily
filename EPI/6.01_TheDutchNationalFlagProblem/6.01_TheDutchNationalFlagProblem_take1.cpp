#include <iostream>
#include <utility>
#include <vector>

void dutchNationalFlagPartition(std::vector<int>& A, int pivot_index)
{
    int pivot = A[pivot_index];
    int smaller = 0; int equal = 0; int larger = A.size()-1;      

    while(equal<=larger)
    {
        if(A[equal]<pivot) {std::swap(A[equal++], A[smaller++]);}
        else if(A[equal]==pivot) {equal++;}
        else {std::swap(A[equal], A[larger--]);}
    }
}

int main()
{
    std::vector<int> A = {0, 1, 2, 0, 2, 1, 1};
    int pivot_index = 3;

    std::cout << ("Przed partycja: ");
    for(int x : A)
    {
        std::cout << x << " ";
    }
    std:: cout << ("\n");

    dutchNationalFlagPartition(A,pivot_index);

    std::cout << ("Po partycji:    ");
    for(int x : A)
    {
        std::cout << x << " ";
    }
    std:: cout << ("\n");

}
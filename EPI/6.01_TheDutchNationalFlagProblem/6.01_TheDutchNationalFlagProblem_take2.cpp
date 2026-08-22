#include <vector>
#include <utility>
using namespace std;

void dutchPartition(vector<int> &A, int pivotIndex)
{
    int smallerPlace = 0;            // // granica elementow mniejszych niz pivot
    int equalPlace = 0;              // aktualnie badany element
    int greaterPlace = A.size() - 1; // granica elementow wiekszych niz pivot

    int pivot = A[pivotIndex];

    while (equalPlace < greaterPlace)
    {
        if (A[equalPlace] > pivot)
        {
            swap(A[greaterPlace], A[equalPlace]);
            greaterPlace--;
        }

        if (A[equalPlace] < pivot)
        {
            equalPlace++;
            smallerPlace++;
        }

        if (A[equalPlace] == pivot)
        {
            equal++;
        }
    }
}
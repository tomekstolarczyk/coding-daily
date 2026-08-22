#include <vector>
#include <utility>
using namespace std;

void dutchPartition(vector<int> &A, int pivotIndex)
{
    if (A.empty())
    {
        return;
    }

    int smallerPlace = 0;            // // granica elementow mniejszych niz pivot
    int equalPlace = 0;              // aktualnie badany element
    int greaterPlace = A.size() - 1; // granica elementow wiekszych niz pivot

    int pivot = A[pivotIndex];

    while (equalPlace <= greaterPlace)
    {
        if (A[equalPlace] > pivot)
        {
            swap(A[greaterPlace], A[equalPlace]);
            greaterPlace--;
        }

        else if (A[equalPlace] < pivot)
        {
            swap(A[smallerPlace], A[equalPlace]);
            equalPlace++;
            smallerPlace++;
        }

        else // (A[equalPlace] == pivot)
        {
            equalPlace++;
        }
    }
}
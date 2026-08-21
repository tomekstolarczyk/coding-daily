
#include <vector>

bool advanceArray(const std::vector<int> &A)
{

    int maxFinalDestination = 0;

    for (int i = 0; i < A.size(); i++)
    {

        // czy w ogole tam dojdziemy
        if (maxFinalDestination < i)
        {
            return false;
        }

        // 2 update max final
        maxFinalDestination = std::max(maxFinalDestination, A[i] + i);

        // 3 win condition
        if (maxFinalDestination >= A.size() - 1)
        {
            return true;
        }
    }

    return false;
}
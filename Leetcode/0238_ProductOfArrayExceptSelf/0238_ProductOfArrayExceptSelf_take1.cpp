#include <vector>

/* WITHOUT USING THE DIVISION OPERATOR !!!

std::vector<int> productArray(std::vector<int> &A)
{
    // 1 initial value for A[0]
    int productZero = 1;
    for (int i = 1; i < A.size(); i++)
    {
        productZero *= A[i];
    }
    std::vector<int> answer;
    answer.push_back(productZero);

    // 2 teraz dalej bedziemy zawsze dzielic poprzednia wartosc przez A[i] oraz mnozyc przez A[i-1] i essa
    for (int i = 1; i < A.size(); i++)
    {
        int product = answer[i - 1];
        product = product / A[i];
        product = product * A[i - 1];
        answer.push_back(product);
    }

    // ^^ dwa pojedyncze przejscia petli wiec zlozonosc O(n) essa

    return answer;
}
*/

std::vector<int> productArray(std::vector<int> &A)
{
    std::vector<int> answer(A.size(), 1);

    // 1 prefix
    for (int i = 1; i < A.size(); i++)
    {
        answer[i] = answer[i - 1] * A[i - 1];
    }

    // 2 suffix
    int suff = 1;
    for (int i = A.size() - 2; i >= 0; i--)
    {
        suff *= A[i + 1];
        answer[i] = answer[i] * suff;
    }

    return answer;
}

// zlota zasada programowania dynamicznego : nie licz dwa razy tego samego - zapamiętaj i wykorzystaj ponownie
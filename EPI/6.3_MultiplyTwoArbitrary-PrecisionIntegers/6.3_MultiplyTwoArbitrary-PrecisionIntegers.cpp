#include <iostream>
#include <vector>

// A * B = C

std::vector<int> multiplyAB(std::vector<int> A, std::vector<int> B)
{
    // 1 result sign
    int sign = (A[0] < 0) ^ (B[0] <0) ? -1 : 1; // XOR operator - returns true when signs are different and false if the same
    A[0] = std::abs(A[0]);
    B[0] = std::abs(B[0]);

    // 2 result (maxymalnie bedzie mial dlugosc sumy obu 900x90=81000)
    std::vector<int> result(A.size() + B.size(),0);

    // 3 actual multiplication
    for(int i = A.size()-1; i >= 0; i--)
    {
        for(int j = B.size()-1; j >= 0; j--)
        {
            result[i+j+1] += A[i] * B[j];
            result[i+j] += result[i+j+1] / 10;
            result[i+j+1] %= 10;
        }
    }
    
    // 4 teraz musimy pozbyc sie nadmiernych zer
    int first_nonzero = 0;
    while(first_nonzero < result.size() && result[first_nonzero] == 0)
    {
        first_nonzero++;
    }

    // 5 zero result
    if(first_nonzero == result.size())
    {
        return {0};
    }

    // 6 result
    std::vector<int> finalResult(result.begin() + first_nonzero, result.end());
    finalResult[0] *= sign;
    return finalResult;
}


int main() {

    // Test: 193707721 * -761838257287
    std::vector<int> A = {1, 9, 3, 7, 0, 7, 7, 2, 1};
    std::vector<int> B = {-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};

    std::vector<int> res = multiplyAB(A, B);

    // should return -147573952589676412927.
    std::cout << "Wynik mnozenia: ";
    for (int x : res) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
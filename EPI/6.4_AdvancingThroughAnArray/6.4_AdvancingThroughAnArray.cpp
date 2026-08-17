#include <iostream>
#include <vector>

bool advancingThroughAnArray(std::vector<int>& wektor)
{
    int maxFinalDestination = 0; // max distance jaki mozemy zrobic stad gdzie stoimy
    for(int i = 0; i < wektor.size(); i++)
    {
        // czy w ogole dotrzemy do tego indeksu?
        if (maxFinalDestination < i) {return false;}
    
        maxFinalDestination = maxFinalDestination > wektor[i] + i ? maxFinalDestination : wektor[i] + i;
        // same as :
        // maxFinalDestination = std::max(maxFinalDestination, wektor[i] + i);
        
        // win condition
        if(maxFinalDestination >= wektor.size()-1) {return true;}
    }   

    // jesli petla przeszla a sie nie zworcilo wciaz true to znaczy ze sie nie udalo
    return false;
}

int main() {
    // Test 1
    std::vector<int> A1 = {3, 3, 1, 0, 2, 0, 1};
    std::cout << "Test 1 (Oczekiwane: 1): " << advancingThroughAnArray(A1) << "\n";

    // Test 2
    std::vector<int> A2 = {3, 2, 0, 0, 2, 0, 1};
    std::cout << "Test 2 (Oczekiwane: 0): " << advancingThroughAnArray(A2) << "\n";

    // Test 3
    std::vector<int> A3 = {5, 0, 0, 0, 0};
    std::cout << "Test 3 (Oczekiwane: 1): " << advancingThroughAnArray(A3) << "\n";

    // Test 4 
    std::vector<int> A4 = {0, 2, 3};
    std::cout << "Test 4 (Oczekiwane: 0): " << advancingThroughAnArray(A4) << "\n";

    // Test 5
    std::vector<int> A5 = {0};
    std::cout << "Test 5 (Oczekiwane: 1): " << advancingThroughAnArray(A5) << "\n";

    return 0;
}
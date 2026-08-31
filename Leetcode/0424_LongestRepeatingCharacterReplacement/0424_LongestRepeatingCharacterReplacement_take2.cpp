#include <string>
#include <array>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
    int characterReplacement(const string &s, int k)
    {

        // sliding window
        int left = 0;
        int maxFreq = 0;
        int worldRecord = 0;
        array<int, 26> zliczenia{};
        for (int right = 0; right < s.size(); right++)
        {

            // aktualizujemy licznik wystepowan
            zliczenia[s[right] - 'A']++;
            if (zliczenia[s[right] - 'A'] > maxFreq)
            {
                maxFreq = zliczenia[s[right] - 'A'];
            }

            // pytanie czy sliding window wciaz okej czy trzeba pociagnac do przodu
            if ((maxFreq + k) < (right + 1 - left))
            {
                zliczenia[s[left] - 'A']--;
                left++;
                // zawyżone maxFreq w niczym nie szkodzi
            }

            // jesli okno poprawne to aktualizujemy dotychaczasowy rekord jesli trzeba
            worldRecord = max(worldRecord, right - left + 1);
        }

        return worldRecord;
    }
};

int main()
{
    Solution sol;

    struct TestCase
    {
        string s;
        int k;
        int expected;
    };

    vector<TestCase> tests = {
        {"ABAB", 2, 4},
        {"AABABBA", 1, 4},
        {"AAAA", 0, 4},
        {"AAAA", 2, 4},
        {"ABCDE", 1, 2},
        {"ABCDE", 0, 1},
        {"A", 0, 1},
        {"ABBB", 2, 4},
        {"BAAAB", 2, 5}};

    for (size_t i = 0; i < tests.size(); ++i)
    {
        int result = sol.characterReplacement(tests[i].s, tests[i].k);
        cout << "Test " << i + 1 << ": s = \"" << tests[i].s
             << "\", k = " << tests[i].k
             << " | Wynik: " << result
             << " | Oczekiwano: " << tests[i].expected;

        if (result == tests[i].expected)
        {
            cout << " -> [OK]\n";
        }
        else
        {
            cout << " -> [BLAD!]\n";
        }
    }

    return 0;
}
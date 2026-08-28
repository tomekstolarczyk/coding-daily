#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int backer = 0;
        int currLength = 0;
        int maxLength = 0;

        unordered_map<char, int> mapka;

        for (int frontier = 0; frontier < s.size(); frontier++)
        {
            // zwiekszamy licznik wystepowan
            mapka[s[frontier]]++;

            // znaleziono duplikat w ciagu
            if (mapka[s[frontier]] != 1)
            {
                // dopoki nie znajdziemy danego duplikatu wywalamy caly ogon
                while (s[backer] != s[frontier])
                {
                    mapka[s[backer]] -= 1;
                    backer++;
                    currLength -= 1;
                }

                // jeszcze raz gdy juz znalezlismy sam dany duplikat
                mapka[s[backer]] -= 1;
                backer++;
                currLength -= 1;
            }

            currLength++;

            if (maxLength < currLength)
            {
                maxLength = currLength;
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution solution;

    int test1 = solution.lengthOfLongestSubstring("");
    cout << test1;

    int test2 = solution.lengthOfLongestSubstring("abcabcbb");
    cout << test2;

    int test3 = solution.lengthOfLongestSubstring("bbbbb");
    cout << test3;

    int test4 = solution.lengthOfLongestSubstring("pwwkew");
    cout << test4;
}
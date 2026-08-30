#include <vector>
using namespace std;
#include <string>
#include <array>
#include <iostream>

// s and p consist of lowercase English letters
// a wiec prowynywanie tablic ze soba bedzie w O(1) - czas staly !! letsgoo
vector<int> findAnagrams(const string &s, const string &p)
{
    vector<int> result;

    // zabezpiecznie
    if (p.size() > s.size())
    {
        return {};
    }

    // 1 najpierw zliczmy p
    array<int, 26> tablicaP{};
    for (int i = 0; i < p.size(); i++)
    {
        tablicaP[p[i] - 'a']++;
    }

    // 2 teraz zliczmy pierwsze pare wyrazow dla s
    array<int, 26> tablicaS{};
    int j = 0;
    while (j < p.size())
    {
        tablicaS[s[j] - 'a']++;
        j++;
    }
    // sprawdzmy pierwsze okno
    int i = 0;
    if (tablicaP == tablicaS)
    {
        result.push_back(i);
    }

    // 3 teraz do konca lecimy juz ze sliding window
    while (j < s.size())
    {
        tablicaS[s[i] - 'a']--;
        i++;

        // tutaj z kroku 2 j jest juz o jeden do przodu - zamieniamy miejscami!!
        tablicaS[s[j] - 'a']++;
        j++;

        if (tablicaP == tablicaS)
        {
            result.push_back(i);
        }
    }

    // i wreszcie returnujemy essaa
    return result;
}

int main()
{
    string s1 = "cbaebabacd";
    string p1 = "abc";
    vector<int> res1 = findAnagrams(s1, p1);
    for (int i = 0; i < res1.size(); i++)
    {
        cout << res1[i];
    }
    cout << endl;

    string s2 = "abab";
    string p2 = "ab";
    vector<int> res2 = findAnagrams(s2, p2);
    for (int i = 0; i < res2.size(); i++)
    {
        cout << res2[i];
    }
    cout << endl;

    string s3 = "eloeloelo";
    string p3 = "elo";
    vector<int> res3 = findAnagrams(s3, p3);
    for (int i = 0; i < res3.size(); i++)
    {
        cout << res3[i];
    }
    cout << endl;
}
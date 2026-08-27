#include <string>
#include <unordered_map>

// - 1 opcja O(nlogn) - posortowalbym a potem po kolei sprawdzal
// - 2 nizsza zlozonosc ale narzut pamieciowy - dodatkowa tablica do zliczania
// "s and t consist of lowercase English letters" dlatego wystarczy tablica 26 elementowa
// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
// -> std::unordered_map i w takie rozwiazanie wlasnie pojdziemy

bool anagram(const std::string &s, const std::string &t)
{
    // check for same size
    if (s.size() != t.size())
    {
        return false;
    }
    int n = s.size();

    // Kluczem jest znak (char), a wartością liczba jego wystąpień (int)
    std::unordered_map<char, int> haszMapka;

    // idziemy przez s i wypelniamy hasz mape
    for (int i = 0; i < n; i++)
    {
        haszMapka[s[i]]++;
    }

    // idziemy przez t
    for (int i = 0; i < n; i++)
    {
        haszMapka[t[i]]--;

        if (haszMapka[t[i]] < 0)
        {
            return false;
        }
    }

    return true;
}

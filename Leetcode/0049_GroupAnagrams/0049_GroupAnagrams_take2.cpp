#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        // przygotowujemy tablica haszujaca
        unordered_map<string, vector<string>> map;

        // dla kazdego slowa bedziemy tworzyc klucz do hasz mapy
        for (int i = 0; i < strs.size(); i++)
        {
            string klucz(26, 0); // strs[i] consists of lowercase English letters only (hence 26)

            for (int j = 0; j < strs[i].size(); j++)
            {
                klucz[strs[i][j] - 'a']++;
            }

            map[klucz].push_back(strs[i]);
        }

        // na finito
        vector<vector<string>> result;
        result.reserve(map.size());
        for (auto &pair : map)
        {
            result.push_back(move(pair.second));
        }

        return result;
    }
};

int main()
{
    Solution solution;

    vector<string> test1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> test2 = {""};
    vector<string> test3 = {"a"};

    auto printResult = [](const string &testName, vector<vector<string>> groups)
    {
        cout << "=== " << testName << " ===" << endl;
        cout << "[" << endl;
        for (const auto &group : groups)
        {
            cout << "  [ ";
            for (const auto &word : group)
            {
                cout << "\"" << word << "\" ";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl
             << endl;
    };

    printResult("Test 1 (Standardowy)", solution.groupAnagrams(test1));
    printResult("Test 2 (Pusty)", solution.groupAnagrams(test2));
    printResult("Test 3 (Pojedynczy)", solution.groupAnagrams(test3));

    return 0;
}
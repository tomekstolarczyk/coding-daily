// Leetcode 49 - group anagrams

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{

public:
    // oczywsicie mozemy to zbrutforcowac
    // - dla kazdego slowa zliczamy tablica 26 elementow
    // - kazda tablice porownujemy ze soba czy ta sama -> ale to mega nam stworzy glupia zlozonosc -> hasz mapa i wuala

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;

        // 1. zliczamy kazde slowo
        for (int i = 0; i < strs.size(); i++)
        {
            // 2. klucz do zliczania do tablicy haszujacej
            string key(26, 0);

            for (int j = 0; j < strs[i].size(); j++)
            {
                key[strs[i][j] - 'a']++;
            }

            // 3. wrzucamy do tablicy haszujacej
            map[key].push_back(strs[i]);
        }

        // 4. wyciagamy z hasz mapy do wektora wynikow
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
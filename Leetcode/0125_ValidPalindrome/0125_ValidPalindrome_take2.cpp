#include <string>
#include <iostream>

class Solution
{
public:
    bool isPalindrome(const std::string &s)
    {
        int i = 0;
        int j = static_cast<int>(s.size()) - 1;

        while (i < j)
        {
            while (i < j && !std::isalnum(s[j]))
            {
                j--;
            }

            while (i < j && !std::isalnum(s[i]))
            {
                i++;
            }

            if (std::tolower(s[i]) != std::tolower(s[j]))
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};

int main()
{
    Solution solution;

    std::cout << "expected : 11101" << std::endl;

    bool test1 = solution.isPalindrome("amanaplanacanalpanama");
    std::cout << test1;

    bool test2 = solution.isPalindrome("A man, a plan, a canal: Panama");
    std::cout << test2;

    bool test3 = solution.isPalindrome("");
    std::cout << test3;

    bool test4 = solution.isPalindrome("race a car");
    std::cout << test4;

    bool test5 = solution.isPalindrome(" ");
    std::cout << test5;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> vowelsInString;

        for (int i = 0; i < s.length(); i++)
        {
            if (vowels.find(s[i]) != vowels.end())
            {
                vowelsInString.push_back(s[i]);
            }
        }

        int n = vowelsInString.size();

        for (int i = 0; i < s.length(); i++)
        {
            if (vowels.find(s[i]) != vowels.end())
            {
                s[i] = vowelsInString[n - 1];
                n--;
            }
        }

        return s;
    }
};

int main()
{

    return 0;
}
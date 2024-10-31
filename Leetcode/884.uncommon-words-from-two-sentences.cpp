#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> mp1, mp2;

        string word = "";

        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == ' ')
            {
                mp1[word]++;
                word = "";
            }
            else
            {
                word += s1[i];
            }
        }

        mp1[word]++;

        word = "";

        for (int i = 0; i < s2.length(); i++)
        {
            if (s2[i] == ' ')
            {
                mp2[word]++;
                word = "";
            }
            else
            {
                word += s2[i];
            }
        }

        mp2[word]++;

        vector<string> res;

        for (auto it : mp1)
        {
            if (it.second == 1 && mp2.find(it.first) == mp2.end())
            {
                res.push_back(it.first);
            }
        }

        for (auto it : mp2)
        {
            if (it.second == 1 && mp1.find(it.first) == mp1.end())
            {
                res.push_back(it.first);
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}
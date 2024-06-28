#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(unordered_set<string> &words, string &s, int idx)
    {
        if (idx == s.length())
        {
            return true;
        }

        string t = "";
        for (int i = idx; i < s.length(); i++)
        {
            t += s[i];
            if (words.find(t) != words.end())
            {
                if (solve(words, s, i + 1))
                {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return solve(words, s, 0);
    }
};

int main()
{

    return 0;
}
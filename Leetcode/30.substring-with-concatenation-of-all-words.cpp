#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_set<string> set(words.begin(), words.end());

        int wordLen = words[0].length();
        int strLen = s.length();

        vector<int> ans;
        if (strLen < wordLen)
        {
            return ans;
        }

        string curr = "";

        for (int i = 0; i < wordLen; i++)
        {
            curr += s[i];
        }

        if (set.find(curr) != set.end())
        {
            ans.push_back(0);
        }

        for (int i = 1; i < strLen - wordLen + 1; i++)
        {
            curr.erase(curr.begin());
            curr += s[i + wordLen - 1];

            if (set.find(curr) != set.end())
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}
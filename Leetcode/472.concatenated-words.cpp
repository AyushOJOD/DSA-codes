#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isConcat(string s, unordered_set<string> &st, unordered_map<string, bool> &dp)
    {
        int len = s.length();

        if (dp.find(s) != dp.end())
        {
            return dp[s];
        }

        for (int i = 0; i < len; i++)
        {
            string prefix = s.substr(0, i + 1, dp);
            string suffix = s.substr(i + 1, dp);

            if (((st.find(prefix) != st.end()) && st.find(suffix) != st.end()) || ((st.find(prefix) != st.end()) && isConcat(suffix, st, dp)))
            {
                return dp[s] = true;
            }
        }
        return dp[s] = false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        int n = words.size();
        unordered_set<string> st(words.begin(), words.end());
        unordered_map<string, bool> dp;

        vector<string> res;

        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];

            if (isConcat(word, st, dp))
            {
                res.push_back(word);
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}
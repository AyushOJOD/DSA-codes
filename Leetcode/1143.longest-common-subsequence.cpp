#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(string s, string t, int sIdx, int tIdx, vector<vector<int>> &dp)
    {
        if (sIdx < 0 || tIdx < 0)
        {
            return 0;
        }

        if (dp[sIdx][tIdx] != -1)
        {
            return dp[sIdx][tIdx];
        }

        if (s[sIdx] == t[tIdx])
        {
            return dp[sIdx][tIdx] = 1 + helper(s, t, sIdx - 1, tIdx - 1);
        }

        return dp[sIdx][tIdx] = max(helper(s, t, sIdx - 1, tIdx), helper(s, t, sIdx, tIdx - 1));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {

        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int helper(string s, string s2, int i, int j, vector<vector<int>> &dp)
{
    // Base case

    if (i == 0 || j == 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i - 1] == s2[j - 1])
    {
        return dp[i][j] = 1 + helper(s, s2, i - 1, j - 1, dp);
    }

    return dp[i][j] = max(helper(s, s2, i - 1, j, dp), helper(s, s2, i, j - 1, dp));
}

int longestPalindromeSubseq(string s)
{
    int n = s.length();

    string s2 = s;
    reverse(s2.begin(), s2.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int main()
{

    return 0;
}
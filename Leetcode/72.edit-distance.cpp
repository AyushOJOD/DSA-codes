#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(string s, string t, int i, int j, vector<vector<int>> &dp)
    {
        // Base case
        if (j >= t.length())
        {
            return s.length() - i;
        }

        if (i >= s.length())
        {
            return t.length() - j;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            return dp[i][j] = helper(s, t, i + 1, j + 1, dp);
        }

        int del = 1 + helper(s, t, i + 1, j, dp);
        int insert = 1 + helper(s, t, i, j + 1, dp);
        int replace = 1 + helper(s, t, i + 1, j + 1, dp);

        return dp[i][j] = min({del, insert, replace});
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        if (n == 0 || m == 0)
        {
            return max(m, n);
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word[i - 1] == word[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int del = 1 + dp[i - 1][j];
                    int insert = 1 + dp[i][j - 1];
                    int replace = 1 + dp[i - 1][j - 1];

                    dp[i][j] = min({del, insert, replace});
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{

    return 0;
}
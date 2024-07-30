#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool helper(string s, string t, int i, int j, vector<vector<int>> &dp)
    {
        // Base case
        if (i == 0 && j == 0)
            return 1;
        if (i == 0 && j > 0)
            return 0;
        if (i > 0 && j == 0)
        {
            for (int idx = 1; idx <= i; idx++)
            {
                if (s[idx - 1] != '*')
                {
                    return 0;
                }
            }
            return 1;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Recursion

        if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
        {
            return dp[i][j] = helper(s, t, i - 1, j - 1, dp);
        }
        if (s[i - 1] == '*')
        {
            return dp[i][j] = helper(s, t, i - 1, j, dp) || helper(s, t, i, j - 1, dp);
        }

        return dp[i][j] = 0;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= m; i++)
        {
            bool flag = true;
            for (int idx = 1; idx <= i; idx++)
            {
                if (s[idx - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
    }
};

int main()
{

    return 0;
}
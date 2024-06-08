#include <bits/stdc++.h>
using namespace std;

bool helper(string s, string p, int i, int j, vector<vector<int>> &dp)
{
    // Base case

    if (i < 0 && j < 0)
    {
        return true;
    }
    if (i >= 0 && j < 0)
    {
        return false;
    }
    if (i < 0 && j >= 0)
    {
        for (int x = 0; x <= j; x++)
        {
            if (p[x] != '*')
            {
                return false;
            }
        }
        return true;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == p[j] || p[j] == '?')
    {
        return dp[i][j] = helper(s, p, i - 1, j - 1, dp);
    }

    if (p[j] == '*')
    {
        return dp[i][j] = helper(s, p, i - 1, j, dp) | helper(s, p, i, j - 1, dp);
    }

    return dp[i][j] = false;
}

bool isMatch(string s, string p)
{
    int ns = s.length();
    int np = p.length();

    vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1, false));

    dp[0][0] = false;

    for (int x = 1; x <= np; x++)
    {
        dp[0][j] = false;
    }
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool helper(string s, string p, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
        {
            return 1;
        }
        if (i >= 0 && j < 0)
        {
            return 0;
        }
        if (i < 0 && j >= 0)
        {
            for (int a = 0; a <= j; a++)
            {
                if (p[a] != '*')
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

        if (s[i] == p[j] || p[j] == '.')
        {
            return dp[i][j] = helper(s, p, i - 1, j - 1, dp);
        }
        if (p[j] == '*')
        {
            return dp[i][j] = helper(s, p, i - 1, j, dp) || helper(s, p, i, j - 1, dp);
        }

        return dp[i][j] = 0;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(s, p, n - 1, m - 1, dp);
    }
};

int main()
{

    return 0;
}
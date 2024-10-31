#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(string p, string s, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
        {
            return 0;
        }

        if (i < 0)
        {
            return j + 1;
        }

        if (j < 0)
        {
            return i + 1;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (p[i] == s[j])
        {
            return dp[i][j] = helper(p, s, i - 1, j - 1, dp);
        }

        int remove = 1 + helper(p, s, i - 1, j, dp);
        int insert = 1 + helper(p, s, i, j - 1, dp);

        return dp[i][j] = min(insert, remove);
    }

public:
    int minOperations(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(str1, str2, n - 1, m - 1, dp);
    }
};

int main()
{

    return 0;
}
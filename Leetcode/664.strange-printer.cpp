#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;

    int helper(string &s, int left, int right, vector<vector<int>> &dp)
    {
        if (left == right)
        {
            return 1;
        }
        if (left > right)
        {
            return 0;
        }

        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int i = left + 1;

        while (i <= right && s[i] == s[left])
        {
            i++;
        }

        if (i == right + 1)
        {
            return 1;
        }

        int app1 = 1 + helper(s, i, right, dp);

        int app2 = INT_MAX;

        for (int j = i; j <= right; j++)
        {
            if (s[j] == s[left])
            {
                int ans = helper(s, i, j - 1, dp) + helper(s, j, right, dp);

                app2 = min(ans, app2);
            }
        }

        return dp[left][right] = min(app2, app1);
    }

    int strangePrinter(string s)
    {
        n = s.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return helper(s, 0, n - 1, dp);
    }
};

int main()
{

    return 0;
}
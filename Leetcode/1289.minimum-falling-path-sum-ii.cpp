#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = grid[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> min1(m, INT_MAX);
        vector<int> min2(m, INT_MAX);
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (j != k)
                {
                    if (dp[i - 1][k] < min1[j])
                    {
                        min2[j] = min1[j];
                        min1[j] = dp[i - 1][k];
                    }
                    else if (dp[i - 1][k] < min2[j])
                    {
                        min2[j] = dp[i - 1][k];
                    }
                }
            }
        }
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = grid[i][j] + min1[j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    return ans;
}

int main()
{

    return 0;
}
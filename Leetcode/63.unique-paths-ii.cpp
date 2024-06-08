#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp)
{

    // Base case
    if (n == 0 && m == 0)
    {
        return grid[n][m] = 1 ? 0 : 1;
    }

    if (n < 0 || m < 0 || grid[m][n] == 1)
    {
        return 0;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    int up = 0, left = 0;

    if (grid[n - 1][m] == 0 && n > 0)
    {
        up = helper(grid, n - 1, m, dp);
    }

    if (grid[n][m - 1] == 0 && m > 0)
    {
        left = helper(grid, n, m - 1, dp);
    }

    return dp[n][m] = left + up;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = !dp[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
        }
    }
}

int main()
{

    return 0;
}
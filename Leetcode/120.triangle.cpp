#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &triangle, int i, int j)
{
    if (i == triangle.size() - 1)
    {
        return triangle[i][j];
    }

    int down = triangle[i][j] + helper(triangle, i + 1, j);
    int diag = triangle[i][j] + helper(triangle, i + 1, j + 1);

    return min(down, diag);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diag = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diag);
        }
    }

    return dp[n - 1][n - 1];
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &matrix, int n, int i, int j, vector<vector<int>> &dp)
{
    // Base case: if we're out of bounds
    if (i < 0 || j < 0 || j >= n)
    {
        return 1e9;
    }

    // Base case: if we're at the top row, return ,the matrix value
    if (i == 0)
    {
        return matrix[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // Recursive case: calculate the minimum path sum of the three possible paths
    int topL = matrix[i][j] + helper(matrix, n, i - 1, j - 1, dp);
    int topR = matrix[i][j] + helper(matrix, n, i - 1, j + 1, dp);
    int top = matrix[i][j] + helper(matrix, n, i - 1, j, dp);

    // Return the current cell value plus the minimum of the three paths
    return dp[i][j] = min(top, min(topL, topR));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j < m; j++)
    {
    }
}

int main()
{

    return 0;
}
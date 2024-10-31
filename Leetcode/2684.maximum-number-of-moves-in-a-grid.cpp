#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
    {
        if (col == grid[0].size() - 1)
        {
            return 0;
        }

        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        int topRight = 0, right = 0, bottomRight = 0;

        if (row - 1 >= 0 && col + 1 < grid[0].size() && grid[row][col] < grid[row - 1][col + 1])
        {
            topRight = 1 + helper(grid, row - 1, col + 1, dp);
        }

        if (col + 1 < grid[0].size() && grid[row][col] < grid[row][col + 1])
        {
            right = 1 + helper(grid, row, col + 1, dp);
        }

        if (row + 1 < grid.size() && col + 1 < grid[0].size() && grid[row][col] < grid[row + 1][col + 1])
        {
            bottomRight = 1 + helper(grid, row + 1, col + 1, dp);
        }

        return dp[row][col] = max({topRight, right, bottomRight});
    }

public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxVal = INT_MIN;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            maxVal = max(maxVal, helper(grid, i, 0, dp));
        }

        return maxVal;
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValid(int row, int col, int n, int m)
    {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

    int helper(vector<vector<int>> &grid, int row, int col)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (row == 0 && col == 0)
        {
            return max(1, 1 - grid[row][col]);
        }

        int up = INT_MAX, left = INT_MAX;

        if (isValid(row - 1, col, n, m))
        {
            up = helper(grid, row - 1, col);
        }

        if (isValid(row, col - 1, n, m))
        {
            left = helper(grid, row, col - 1);
        }

        int minHealth = min(left, up) - grid[row][col];

        return max(1, minHealth);
    }

public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int n = dungeon.size();
        int m = dungeon[0].size();

        return helper(dungeon, n - 1, m - 1);
    }
};

int main()
{

    return 0;
}
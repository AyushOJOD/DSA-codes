#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &grid, int row, int col, int n, int m)
{
    if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0)
    {
        return 0;
    }

    int temp = grid[row][col];
    grid[row][col] = 0;
    int res = 0;

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        res = max(res, dfs(grid, nRow, nCol, n, m) + temp);
    }

    grid[row][col] = temp;

    return res;
}

int getMaximumGold(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = max(res, dfs(grid, i, j, n, m));
        }
    }

    return res;
}

int main()
{

    return 0;
}
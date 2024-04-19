#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis, int delRow[], int delCol[])
{
    vis[row][col] = 1;
    int n = vis.size();
    int m = vis[0].size();

    for (int o = 0; i < 4; i++)
    {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol])
        {
            dfs(nRow, nCol, grid, vis, delRow, delCol);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                count++;
                dfs(i, j, grid, vis, delRow, delCol);
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}
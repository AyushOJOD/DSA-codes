#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &vis, int delRow[], int delCol[])
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !vis[nRow][nCol])
            {
                dfs(grid, nRow, nCol, vis, delRow, delCol);
            }
        }
    }

    int num_of_island(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int islands = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    islands++;
                    dfs(grid, i, j, vis, delRow, delCol);
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int initialNumber = num_of_island(grid);

        if (initialNumber == 0 || initialNumber > 1)
        {
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    int newNumber = num_of_island(grid);
                    grid[i][j] = 1;

                    if (newNumber != 1)
                    {
                        return 1;
                    }
                }
            }
        }

        return 2;
    }
};

int main()
{

    return 0;
}
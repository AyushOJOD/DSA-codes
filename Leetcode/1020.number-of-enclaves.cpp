#include <bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int, int>> q; // {row, col}

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 1)
        {
            vis[0][i] = 1;
            q.push({0, i});
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1)
        {
            vis[i][0] = 1;
            q.push({i, 0});
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][m - 1] == 1)
        {
            vis[i][m - 1] = 1;
            q.push({i, m - 1});
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[n - 1][i] == 1)
        {
            vis[n - 1][i] = 1;
            q.push({n - 1, i});
        }
    }

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
            {
                vis[nRow][nCol] = 1;
                q.push({nRow, nCol});
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{

    return 0;
}
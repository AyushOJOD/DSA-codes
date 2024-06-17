#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    int vis[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
            {
                grid[i][j] = 0;
            }
        }
    }

    int time = 0;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto node = q.front();

        int row = node.first.first;
        int col = node.first.second;
        int tm = node.second;
        q.pop();

        time = max(tm, time);

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow > 0 && nRow < n && nCol > 0 && nCol < m && vis[nRow][nCol] != 2 && vis[nRow][nCol] != 0)
            {
                q.push({{nRow, nCol}, tm + 1});
                vis[nRow][nCol] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] != 2)
            {
                return -1;
            }
        }
    }

    return time;
}

int main()
{

    return 0;
}
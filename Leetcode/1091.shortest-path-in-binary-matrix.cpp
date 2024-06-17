#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
    {
        return -1;
    }

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    queue<pair<int, pair<int, int>>> q; // {dist, {row, col}}

    q.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!q.empty())
    {
        int dis = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        int delRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < 8; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !grid[nRow][nCol] && dist[nRow][nCol] > 1 + dis)
            {
                dist[nRow][nCol] = 1 + dis;
                if (nRow == n - 1 && nCol == m - 1)
                {
                    return 1 + dis;
                }
                q.push({1 + dis, {nRow, nCol}});
            }
        }
    }

    return dist[n - 1][m - 1];
}

int main()
{

    return 0;
}
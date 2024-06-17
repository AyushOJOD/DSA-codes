#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O')
        {
            vis[0][i] = 1;
            q.push({0, i});
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
        {
            vis[i][0] = 1;
            q.push({i, 0});
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (board[i][m - 1] == 'O')
        {
            vis[i][m - 1] = 1;
            q.push({i, m - 1});
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (board[n - 1][i] == 'O')
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

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && board[nRow][nCol] == 'O')
            {
                vis[nRow][nCol] = 1;
                q.push({nRow, nCol});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}

int main()
{

    return 0;
}
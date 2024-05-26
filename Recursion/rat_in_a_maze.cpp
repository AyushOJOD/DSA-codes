#include <bits/stdc++.h>
using namespace std;

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<vector<int>> vis(n, vector<int>(n, 0));

    vector<string> res;
    string path = "";
    if (m[0][0] == 1)
    {
        solve(0, 0, n, m, vis, path, res);
    }

    return res;
}

void solve(int i, int j, int n, vector<vector<int>> &m, vector<vector<int>> &vis, string &path, vector<string> &res)
{
    if (i == n - 1 && j == n - 1)
    {
        res.push_back(path);
        return;
    }

    // We go lexicographically in the order of DLRU

    // Down

    if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j] == 1)
    {
        vis[i][j] = 1;
        string newPath = path + 'D';
        solve(i + 1, j, n, m, vis, newPath, res);
        vis[i][j] = 0;
    }

    // Left

    if (j - 1 >= 0 & !vis[i][j - 1] && m[i][j - 1] == 1)
    {
        vis[i][j] = 1;
        string newPath = path + 'L';
        solve(i, j - 1, n, m, vis, newPath, res);
        vis[i][j] = 0;
    }

    // Right

    if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1)
    {
        vis[i][j] = 1;
        string newPath = path + 'R';
        solve(i, j + 1, n, m, vis, newPath, res);
        vis[i][j] = 0;
    }

    // Up

    if (i - 1 >= 0 && !vis[i - 1][j] && m[i - 1][j] == 1)
    {
        vis[i][j] = 1;
        string newPath = path + 'U';
        solve(i - 1, j, n, m, vis, newPath, res);
        vis[i][j] = 0;
    }
}

int main()
{

    return 0;
}
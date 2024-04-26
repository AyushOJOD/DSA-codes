#include <bits/stdc++.h>
using namespace std;

int bfs(int row, int col, vector<vector<int>> &adj, vector<vector<int>> &vis)
{
    queue<pair<pair<int, int>, int>> q;

    vis[row][col] = 1;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n, vector<int>(n, 0));
    vector<vector<int>> vis(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (adj[i][j] != 0 && !vis[i][j])
            {
                bfs(i, j, adj, vis);
            }
        }
    }
}

int main()
{

    return 0;
}
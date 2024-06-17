#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<int> adj[], vector<int> &vis, vector<vector<int>> &bridges)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            dfs(it, node, tin, low, adj, vis, bridges);
            low[node] = min(low[node], low[it]);

            if (low[node] < low[it])
            {
                bridges.push_back({node, it});
            }
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];

    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> tin(n);
    vector<int> low(n);
    vector<int> vis(n, 0);
    vector<vector<int>> bridges;

    dfs(0, -1, tin, low, adj, vis, bridges);
    return bridges;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis, check))
            {
                return true;
            }
            else if (pathVis[it])
            {
                return true;
            }
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();

    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);

    vector<int> safeNodes;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfsCheck(i, adj, vis, pathVis, check);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (check[i])
        {
            safeNodes.push_back(i);
        }
    }

    return safeNodes;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> adj(n);

    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> vis(n, 0);
    queue<int> q;
    vis[source] = 1;
    q.push(source);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == destination)
        {
            return true;
        }

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}
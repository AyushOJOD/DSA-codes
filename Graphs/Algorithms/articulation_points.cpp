#include <bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(int node, int parent, int tin[], int low[], vector<int> &vis, vector<int> &mark, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            dfs(it, node, tin, low, vis, mark, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] >= low[node] && parent != -1)
            {
                mark[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }

    if (child > 0 && parent == -1)
    {
        mark[node] = 1;
    }
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    int tin[V];
    int low[V];
    vector<int> mark(V, 0);

    timer = 1;

    dfs(0, -1, tin, low, vis, mark, adj);

    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (mark[i] == 1)
        {
            ans.push_back(i);
        }
    }

    if (ans.size() == 0)
        return {-1};

    return ans;
}

int main()
{

    return 0;
}
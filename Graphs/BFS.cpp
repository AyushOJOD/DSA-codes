#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> bfs;
    vis[0] = 1;

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return bfs;
}

int main()
{

    int V = 5;
    int E = 4;

    vector<int> adj = {{1, 2, 3},
                       {},
                       {4},
                       {},
                       {}};

    vector<int> bfs = bfsOfGraph(V, adj);
    for (auto i : bfs)
    {
        cout << i << " ";
    }

    return 0;
}
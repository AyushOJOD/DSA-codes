#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int node, stack<int> &st, int vis[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(adj, it, st, vis);
        }
    }

    st.push(node);
}

void topoSort(int V, vector<int> adj[])
{
    // code here
    int vis[V] = {0};
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(adj, i, st, vis);
        }
    }

    vector<int> topo;

    while (!st.empty())
    {
        int val = st.top();
        topo.push_back(val);
        st.pop();
    }

    // topo is the sorted list

    if (topo.size() != V)
    {
        // There is a cycle
    }
}

int main()
{

    return 0;
}
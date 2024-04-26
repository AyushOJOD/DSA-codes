#include <bits/stdc++.h>
using namespace std;

// Step 1: Do a DFS traversal of the graph and push the nodes in a stack after visiting all the nodes of a particular node.

// Step 2: Create a transpose of the graph.

// Step 3: Pop the nodes from the stack and do a DFS traversal of the transpose graph.

// Step 4: Count the number of DFS traversal.

// Step 5: The count will be the number of strongly connected components.

// Time Complexity: O(V+E)

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    }

    st.push(node);
}

void dfsT(int node, vector<int> adjT[], vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfsT(it, adjT, vis);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    // code here

    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> transpose[V];

    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    int cnt = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!vis[node])
        {
            cnt++;
            dfsT(node, transpose, vis);
        }
    }

    return cnt;
}

int main()
{

    return 0;
}
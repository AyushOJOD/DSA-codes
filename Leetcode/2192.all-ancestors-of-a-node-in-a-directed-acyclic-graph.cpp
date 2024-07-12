#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> dfs(vector<vector<int>> adj, vector<int> &vis, int node)
    {
        vector<int> res;

        vis[node] = 1;
        res.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(adj, vis, it);
            }
        }

        return res;
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<vector<int>> res;

        for (auto edge : edges)
        {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                if (!vis[it])
                {
                    res.push_back(dfs(adj, vis, it));
                }
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}
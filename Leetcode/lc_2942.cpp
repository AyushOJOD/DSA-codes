#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> topoSort(vector<vector<int>> &adj, int V)
    {
        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (int it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return (topo.size() == V) ? topo : {-1};
    }

public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);

        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        return topoSort(adj, n);
    }
};

int main()
{

    return 0;
}
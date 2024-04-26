#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, rank;
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int rootU = findUPar(u);
        int rootV = findUPar(v);

        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int Solve(int n, vector<vector<int>> &edge)
{
    DisjointSet ds(n);

    int extraEdges = 0;

    for (auto it : edge)
    {
        if (ds.findUPar(it[0]) == ds.findUPar(it[1]))
        {
            extraEdges++;
        }
        else
        {
            ds.unionByRank(it[0], it[1]);
        }
    }

    int connectedComponents = 0;

    for (int i = 0; i < n; i++)
    {
        if (ds.parent[i] == i)
        {
            connectedComponents++;
        }
    }

    if (extraEdges >= connectedComponents - 1)
    {
        return connectedComponents - 1;
    }
    else
    {
        return -1;
    }
}

int main()
{

    return 0;
}
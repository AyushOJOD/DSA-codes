#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int makeConnected(int n, vector<vector<int>> &connections)
{
    int initConnections = connections.size();

    if (initConnections < n - 1)
    {
        return -1;
    }

    DisjointSet ds(n);

    for (auto connection : connections)
    {
        int u = connection[0];
        int v = connection[1];

        ds.unionBySize(u, v);
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (ds.findUPar(i) == i)
        {
            count++;
        }
    }

    return count - 1;
}

int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    cout << makeConnected(n, connections) << endl;

    return 0;
}

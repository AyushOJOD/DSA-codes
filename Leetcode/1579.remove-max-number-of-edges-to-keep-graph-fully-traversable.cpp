#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;
    int components;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        components = n;

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int getComponents()
    {
        return components;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
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

        components--;
    }
};

// Check if the UlP is same then dont add the edge
//

class Solution
{
private:
    static bool comp(vector<int> &v1, vector<int> &v2)
    {
        return v1[0] > v2[0];
    }

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DisjointSet dsA(n);
        DisjointSet dsB(n);

        sort(edges.begin(), edges.end(), comp);

        int count = 0;

        for (auto &edge : edges)
        {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (type == 3)
            {
                bool isEdgeAdded = false;

                // Alice
                if (dsA.findUPar(u) != dsA.findUPar(v))
                {
                    dsA.unionBySize(u, v);
                    isEdgeAdded = true;
                }

                if (dsB.findUPar(u) != dsB.findUPar(v))
                {
                    dsB.unionBySize(u, v);
                    isEdgeAdded = true;
                }

                if (isEdgeAdded)
                {
                    count++;
                }
            }

            else if (type == 2)
            {
                // bob
                if (dsB.findUPar(u) != dsB.findUPar(v))
                {
                    dsB.unionBySize(u, v);
                    count++;
                }
            }
            else
            {
                // alice
                if (dsA.findUPar(u) != dsB.findUPar(v))
                {
                    dsA.unionBySize(u, v);
                    count++;
                }
            }
        }

        return (dsA.getComponents() == 1 && dsB.getComponents() == 1) ? n - count : -1;
    }
};

int main()
{

    return 0;
}
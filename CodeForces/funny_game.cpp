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

    int findUlP(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUlP(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUlP(u);
        int ulp_v = findUlP(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

void solve()
{
    int n;
    cin >> n;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
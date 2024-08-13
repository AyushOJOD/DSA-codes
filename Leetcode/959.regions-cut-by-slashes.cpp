#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    class DisjointSet
    {
    public:
        vector<int> parent, size;

        DisjointSet(int n)
        {
            size.resize(n + 1, 1);
            parent.resize(n + 1);

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

    int getNode(int row, int col, int n)
    {
        return col + (row * (n + 1));
    }

public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();

        DisjointSet ds(n * (n + 1));

        for (int i = 1; i <= n * n; i++)
        {
            ds.parent[i] = 0;
        }

        int count = 1;

        for (int i = 0; i < n; i++)
        {
            string curr = grid[i];

            for (int j = 0; j < curr.length(); j++)
            {
                if (grid[i][j] == '/')
                {
                    int u = getNode(i + 1, j, n);
                    int v = getNode(i, j + 1, n);

                    if (ds.findUlP(u) == ds.findUlP(v))
                    {
                        count++;
                    }

                    ds.unionBySize(u, v);
                }
                else if (grid[i][j] == '\\')
                {
                    int u = getNode(i, j, n);
                    int v = getNode(i + 1, j + 1, n);

                    if (ds.findUlP(u) == ds.findUlP(v))
                    {
                        count++;
                    }
                    ds.unionBySize(u, v);
                }
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        size.resize(n, 1);
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

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u != ulp_v)
        { // Only merge if different components.
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
    }
};

bool isValid(int row, int col, int n)
{
    return (row >= 0 && row < n && col >= 0 && col < n);
}

int MaxConnection(vector<vector<int>> &grid)
{
    // Step - 1 : Create a disjoint set and initialize it
    int n = grid.size();
    DisjointSet ds(n * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
                continue;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for (int it = 0; it < 4; it++)
            {
                int nRow = i + dr[it];
                int nCol = j + dc[it];

                if (isValid(nRow, nCol, n) && grid[nRow][nCol] == 1)
                {
                    int node = i * n + j;
                    int adjNode = nRow * n + nCol;

                    ds.unionBySize(node, adjNode);
                }
            }
        }
    }

    // Step - 2 : Change the 0 to 1 and check the maximum connected groups

    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                continue;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            set<int> connectedGroups;

            for (int it = 0; it < 4; it++)
            {
                int nRow = i + dr[it];
                int nCol = j + dc[it];

                if (isValid(nRow, nCol, n) && grid[nRow][nCol] == 1)
                {
                    int adjNode = nRow * n + nCol;
                    connectedGroups.insert(ds.findUPar(adjNode));
                }
            }
            int sizeTotal = 0;
            for (auto x : connectedGroups)
            {
                sizeTotal += ds.size[x];
            }
            mx = max(mx, sizeTotal + 1);
        }
    }

    for (int i = 0; i < n * n; i++)
    {
        mx = max(mx, ds.size[ds.findUPar(i)]);
    }

    return mx;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    cout << MaxConnection(grid) << endl;

    return 0;
}
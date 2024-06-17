#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
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
            if (parent[node] == node)
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

        int getSize(int node)
        {
            return size[node];
        }
    };

    bool isValid(int row, int col, int n)
    {
        return (row >= 0 && row < n && col >= 0 && col < n);
    }

    int getNode(int row, int col, int n)
    {
        return row * n + col;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<int> vis(n * n, 0);
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // First pass to union all connected 1's
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        int nRow = row + delRow[i];
                        int nCol = col + delCol[i];

                        if (isValid(nRow, nCol, n) && grid[nRow][nCol] == 1)
                        {
                            int node = getNode(row, col, n);
                            int adjNode = getNode(nRow, nCol, n);
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        // Second pass to find the maximum island size
        int maxArea = INT_MIN;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                {
                    unordered_set<int> st;
                    int area = 1;
                    for (int i = 0; i < 4; i++)
                    {
                        int nRow = row + delRow[i];
                        int nCol = col + delCol[i];

                        if (isValid(nRow, nCol, n) && grid[nRow][nCol] == 1)
                        {
                            int adjNode = getNode(nRow, nCol, n);
                            int ulp_Node = ds.findUlP(adjNode);

                            if (st.find(ulp_Node) == st.end())
                            {
                                st.insert(ulp_Node);
                                area += ds.getSize(ulp_Node);
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }

        // Check if the entire grid is already one big island
        for (int i = 0; i < n * n; i++)
        {
            if (grid[i / n][i % n] == 1)
            {
                maxArea = max(maxArea, ds.getSize(ds.findUlP(i)));
            }
        }

        return maxArea == INT_MIN ? n * n : maxArea;
    }
};

int main()
{

    return 0;
}
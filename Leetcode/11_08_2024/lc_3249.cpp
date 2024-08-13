#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> adj;
    int cnt;

    int dfs(int node, int parent)
    {
        int totalNodes = 0, subtreeSize = -1;
        bool isGood = true;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue;

            int currSize = dfs(it, node);

            if (subtreeSize == -1)
            {
                subtreeSize = currSize;
            }
            else if (subtreeSize != currSize)
            {
                isGood = false;
            }

            totalNodes += currSize;
        }

        if (isGood)
            cnt++;

        return totalNodes + 1;
    }

    int countGoodNodes(vector<vector<int>> &edges)
    {
        int n = edges.size();

        adj.resize(n + 1);

        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        cnt = 0;
        dfs(0, -1);

        return cnt;
    }
};

int main()
{

    return 0;
}
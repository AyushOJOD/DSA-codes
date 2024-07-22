#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> topoSort(vector<vector<int>> &graph, int k)
    {
        vector<int> inDegree(k + 1, 0), topo;

        for (int i = 1; i <= k; i++)
        {
            for (auto it : graph[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 1; i <= k; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : graph[node])
            {
                if (inDegree[it]-- == 0)
                {
                    q.push(it);
                }
            }
        }

        return (topo.size() == k) ? topo : {};
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<vector<int>> rowGraph(k + 1), colGraph(k + 1);

        for (auto &it : rowConditions)
        {
            rowGraph[it[0]].push_back(it[1]);
        }

        for (auto &it : colConditions)
        {
            colGraph[it[0]].push_back(it[1]);
        }

        vector<int> rowSort = topoSort(rowGraph, k);
        vector<int> colSort = topoSort(colGraph, k);

        if (rowSort.empty() || colSort.empty())
        {
            return vector<int>();
        }

        vector<vector<int>> grid(k, vector<int>(k, 0));

        unordered_map<int, int> rowMap, colMap;

        for (int i = 0; i < k; i++)
        {
            rowMap[rowSort[i]] = i;
            colMap[colSort[i]] = i;
        }

        for (int i = 1; i <= k; i++)
        {
            grid[rowMap[i]][colMap[i]] = i;
        }

        return grid;
    }
};

int main()
{

    return 0;
}
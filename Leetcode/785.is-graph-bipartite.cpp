#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &graph, int idx, int color[], int col)
{
    color[idx] = col;

    for (auto it : graph[idx])
    {
        if (color[it] == -1)
        {
            if (dfs(graph, idx, color, 1 - col) == false)
                return false;
        }
        else if (color[it] == col)
        { // If already colored with the prior color;
            return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();

    int color[n]; // We will use 0 and 1 to color

    fill(color, color + n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(graph, i, color, 0) == false)
                return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}
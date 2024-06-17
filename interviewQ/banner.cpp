#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &adj, vector<int> &res)
{
    int n = adj.size();

    vector<int> inDegree;

    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            inDegree[it]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++)
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
        res.push_back(node);

        for (auto it : adj[node])
        {
            inDegree[it]--;

            if (inDegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;

    vector<vector<string>> grid(n, vector<string>(2));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> grid[i][j];
        }
    }

    int idx = 0;
    unordered_map<string, int> stringVal;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (stringVal.find(grid[i][j]) == stringVal.end())
            {
                stringVal[grid[i][j]] = idx;
                idx++;
            }
        }
    }

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        int u = stringVal[grid[i][0]];
        int v = stringVal[grid[i][1]];

        adj[u].push_back(v);
    }

    vector<int> res;

    solve(adj, res);

    vector<string> final;

    for (int i = 0; i < n; i++)
    {
        int node = res[i];

        for (auto &[k, v] : stringVal)
        {
            if (v == node)
            {
                final.push_back(k);
            }
        }
    }

    for (int i = 0; i < final.size(); i++)
    {
        cout << final[i] << " ";
    }

    return 0;
}
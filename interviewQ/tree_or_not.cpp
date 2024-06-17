// Given a graph with n nodes and n-1 edges, determine if the graph is a tree or not.

#include <bits/stdc++.h>
using namespace std;

bool isTree(int n, vector<int> adj[])
{
    vector<int> inDegree(n, 0);

    for (int i = 0; i < adj->size(); i++)
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

    vector<int> check;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        check.push_back(node);

        for (auto it : adj[node])
        {
            inDegree[it]--;
            if (inDegree == 0)
            {
                q.push(it);
            }
        }
    }

    bool checkCycle = check.size() == n;
}

int main()
{

    return 0;
}

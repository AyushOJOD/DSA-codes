#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> bfs(int start, vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthestNode = start;
        int maxDist = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int it : adj[node])
            {
                if (dist[it] == -1)
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                    if (dist[it] > maxDist)
                    {
                        maxDist = dist[it];
                        farthestNode = it;
                    }
                }
            }
        }

        return {farthestNode, maxDist};
    }

    pair<int, pair<int, int>> treeDiameter(vector<vector<int>> &adj)
    {
        pair<int, int> p1 = bfs(0, adj);
        pair<int, int> p2 = bfs(p1.first, adj);
        return {p2.second, {p1.first, p2.first}};
    }

    int findRadius(int start, vector<vector<int>> &adj)
    {
        pair<int, int> farthest = bfs(start, adj);
        return (farthest.second + 1) / 2;
    }

    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for (auto &edge : edges1)
        {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for (auto &edge : edges2)
        {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        auto dia1 = treeDiameter(adj1);
        auto dia2 = treeDiameter(adj2);

        int radius1 = findRadius(dia1.second.first, adj1);
        int radius2 = findRadius(dia2.second.first, adj2);

        int newDiameter = max({dia1.first, dia2.first, radius1 + radius2 + 1});

        return newDiameter;
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);

    for (auto it : times)
    {
        int src = it[0];
        int end = it[1];
        int wt = it[2];
        adj[src].push_back({end, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {dis, node}

    vector<int> dist(n + 1, 1e9);

    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWt = it.second;

            if (dist[adjNode] > edgeWt + dis)
            {
                dist[adjNode] = edgeWt + dis;
                pq.push({edgeWt + dis, adjNode});
            }
        }
    }

    int maxDist = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == 1e9)
        {
            return -1; // If there's any node that is unreachable
        }
        maxDist = max(maxDist, dist[i]);
    }

    return maxDist;
}

int main()
{

    return 0;
}
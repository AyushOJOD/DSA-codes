#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    int mod = 1000000007;

    vector<pair<int, int>> adj[n];

    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{dis, node}

    vector<int> dist(n, 1e9);
    vector<int> path(n, 0);

    dist[0] = 0;
    path[0] = 1;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWt = it.second;

            if (dist[adjNode] > dis + edgeWt)
            {
                dist[adjNode] = dis + edgeWt;
                pq.push({dis + edgeWt, adjNode});
                path[adjNode] = path[node];
            }
            else if (dis + edgeWt == dist[adjNode])
            {
                path[adjNode] = (path[adjNode] + path[node]) % mod;
            }
        }
    }

    return path[n - 1] % mod;
}

int main()
{

    return 0;
}
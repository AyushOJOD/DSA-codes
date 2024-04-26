#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<pair<int, int>> adj[n];
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    int mod = (int)(1e9 + 7);

    while (!pq.empty())
    {
        auto it = pq.top();
        int dis = it.first;
        int node = it.second;
        pq.pop();

        for (auto iter : adj[node])
        {
            int adjNode = iter.first;
            int adjDis = iter.second;

            if (dis + adjDis < dist[adjNode])
            {
                dist[adjNode] = dis + adjNode;
                pq.push({dis + adjDis, adjNode});
                ways[adjNode] = ways[node];
            }
            else if (dis + adjDis == dist[adjNode])
            {
                ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}

int main()
{

    return 0;
}
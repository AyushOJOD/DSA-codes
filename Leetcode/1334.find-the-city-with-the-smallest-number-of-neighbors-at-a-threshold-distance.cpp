#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int S)
{

    // We store the {distance, node} in the priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, 1e9);

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        int wt = it.first;

        pq.pop();

        for (auto iter : adj[node])
        {
            int adjNode = iter.first;
            int edgeWeight = iter.second;

            if (wt + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = wt + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<pair<int, int>>> adj(n);

    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    int minCities = INT_MAX;
    int minCityIdx = -1;

    for (int i = 0; i < n; i++)
    {
        vector<int> dist = dijkstra(n, adj, i);

        int reachableCities = 0;
        for (int d : dist)
        {
            if (d <= distanceThreshold)
            {
                reachableCities++;
            }
        }

        if (reachableCities <= minCities)
        {
            minCities = reachableCities;
            minCityIdx = i;
        }
    }

    return minCityIdx;
}

int main()
{

    return 0;
}
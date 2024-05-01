#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
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
            int adjNode = iter[0];
            int edgeWeight = iter[1];

            if (wt + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = wt + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<int>> adj[n];

    for (auto i : times)
    {
        adj[i[0]].push_back({i[1], i[2]});
    }

    vector<int> dist = dijkstra(n, adj, k);

    int ans = *max_element(dist.begin(), dist.end());

    return ans == 1e9 ? -1 : ans;
}

int main()
{

    return 0;
}
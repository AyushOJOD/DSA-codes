#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int S)
{

    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, S});
    dist[S] = 0;

    while (!st.empty())
    {
        auto it = *(st.begin());
        int weight = it.first;
        int node = it.second;
        st.erase(it);

        for (auto i : adj[node])
        {
            int adjNode = i.first;
            int edgeWeight = i.second;

            if (weight + edgeWeight < dist[adjNode])
            {
                if (dist[adjNode] != 1e9)
                {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = weight + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    // Your code here
    vector<vector<int>> dist(n, vector<int>(n));
    vector<pair<int, int>> adj[n];

    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> d = dijkstra(n, adj, i);
        dist.push_back(d);
    }

    vector<int> reachable(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] <= distanceThreshold)
            {
                reachable[i]++;
            }
        }
    }

    auto it = min_element(reachable.begin(), reachable.end());
    int minIndex = distance(reachable.begin(), it);

    return minIndex;
}

int main()
{

    return 0;
}
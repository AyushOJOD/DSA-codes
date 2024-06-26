#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
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
            int adjNode = i[0];
            int edgeWeight = i[1];

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

vector<int> dijkstraPQ(int V, vector<vector<int>> adj[], int S)
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

int main()
{

    return 0;
}
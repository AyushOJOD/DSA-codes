#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<pair<int, double>> adj[n];

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq; //{prob, node}
        vector<double> dist(n, INT_MIN);

        pq.push({1.0, start_node});
        dist[start_node] = 1;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            double prob = curr.first;
            int node = curr.second;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                double adjProb = it.second;

                if (dist[adjNode] < prob * adjProb)
                {
                    dist[adjNode] = prob * adjProb;
                    pq.push({prob * adjProb, adjNode});
                }
            }
        }

        if (dist[end_node] != INT_MIN)
        {
            return dist[end_node];
        }

        return 0.00000;
    }
};

int main()
{

    return 0;
}
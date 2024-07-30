#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<pair<int, int>>> getGraph(vector<char> &og, vector<char> &changed, vector<int> &cost)
    {
        int n = og.size();

        vector<vector<pair<int, int>>> adj(26);

        for (int i = 0; i < n; i++)
        {
            int st = og[i] - 'a';
            int en = changed[i] - 'a';
            int charge = cost[i];

            adj[st].push_back({en, charge});
        }

        return adj;
    }

    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {

        int n = adj.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {cost, characterIdx}

        vector<int> dist(n, 1e9);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            int cost = it.first;
            pq.pop();

            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int wt = iter.second;

                if (dist[adjNode] > wt + cost)
                {
                    dist[adjNode] = wt + cost;
                    pq.push({wt + cost, adjNode});
                }
            }
        }
        return dist;
    }

public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<pair<int, int>>> adj = getGraph(original, changed, cost);

        vector<vector<int>> minCost;

        for (int i = 0; i < 26; i++)
        {
            minCost.push_back(dijkstra(adj, i));
        }

        int len = source.length();

        long long charge = 0;

        for (int i = 0; i < len; i++)
        {
            if (source[i] != target[i])
            {
                int start = source[i] - 'a';
                int end = target[i] - 'a';

                if (minCost[start][end] == 1e9)
                {
                    return -1;
                }
                charge += minCost[start][end];
            }
        }

        return charge;
    }
};

int main()
{

    return 0;
}
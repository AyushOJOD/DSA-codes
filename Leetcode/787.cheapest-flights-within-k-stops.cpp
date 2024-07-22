#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];

        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q; //{stops, {node, cost}}

        vector<int> cost(n + 1, 1e9);

        q.push({0, {src, 0}});
        cost[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > k)
            {
                continue;
            }

            for (auto it : adj[node])
            {
                int kharcha = it[1];
                int adjNode = it[0];

                if (cost[adjNode] > cost + kharcha)
                {
                    cost[adjNode] = cost + kharcha;
                    q.push({stops + 1, {adjNode, cost + kharcha}});
                }
            }
        }

        if (cost[dst] == 1e9)
        {
            return -1;
        }

        return cost[dst];
    }
};

int main()
{

    return 0;
}
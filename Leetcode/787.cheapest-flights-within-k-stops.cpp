#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]}); // {end, price]}
    }

    queue<pair<int, pair<int, int>>> q; // {stops, {node, price}}

    vector<int> cost(n + 1, 1e9);

    q.push({0, {src, 0}});
    cost[src] = 0;

    while (!q.empty())
    {
        int stops = q.front().first;
        int node = q.front().second.first;
        int price = q.front().second.second;
        q.pop();

        if (stops > k)
        {
            continue;
        }

        for (auto it : adj[node])
        {
            int destination = it.first;
            int kharcha = it.second;

            if (cost[destination] > kharcha + price)
            {
                cost[destination] = kharcha + price;
                q.push({stops + 1, {destination, kharcha + price}});
            }
        }
    }

    if (cost[dst] == 1e9)
    {
        return -1;
    }

    return cost[dst];
}

int main()
{

    return 0;
}
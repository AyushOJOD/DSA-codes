#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    // {wt, currNode}
    // If the question asked to find the minimum spanning tree made the pq as {wt, nextNode, parent}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int sum = 0;
    vector<int> vis(V, 0);
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto it : pq.top();
        int wt = it.first;
        int currNode = it.second;
        pq.pop();

        if (!vis[currNode])
        {
            sum += wt;
            vis[currNode] = 1;

            for (auto i : adj[currNode])
            {
                int nextNode = i[0];
                int nextWt = i[1];

                if (!vis[nextNode])
                {
                    pq.push({nextWt, nextNode});
                }
            }
        }
    }
    return sum;
}

int main()
{

    return 0;
}
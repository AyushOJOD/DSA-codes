#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                adj[manager[i]].push_back(i);
            }
        }

        queue<pair<int, int>> q; // {node, time elapsed}
        int maxTime = 0;

        q.push({headID, 0});

        while (!q.empty())
        {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();

            maxTime = max(maxTime, time);

            for (int it : adj[node])
            {
                q.push({it, time + informTime[node]});
            }
        }

        return maxTime;
    }
};

int main()
{

    return 0;
}
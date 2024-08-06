#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> timeTaken(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n);

        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> times(n, 0);

        for (int i = 0; i < n; i++)
        {
            vector<int> mark(n, -1);
            queue<pair<int, int>> q; // {node, time}
            q.push({i, 0});
            mark[i] = 0;

            while (!q.empty())
            {
                int node = q.front().first;
                int curr = q.front().second;
                q.pop();

                for (auto it : adj[node])
                {
                    int adjTime = (it % 2 == 0) ? curr + 2 : curr + 1;
                    if (mark[it] == -1 || mark[it] > adjTime)
                    {
                        mark[it] = adjTime;
                        q.push({it, adjTime});
                    }
                }
            }

            times[i] = *max_element(mark.begin(), mark.end());
        }

        return times;
    }
};

int main()
{

    return 0;
}
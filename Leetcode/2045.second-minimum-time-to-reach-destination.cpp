#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }

        vector<int> firstArrival(n, INT_MAX);
        vector<int> secondArrival(n, INT_MAX);

        queue<pair<int, int>> q; // {node, time}
        q.push({0, 0});
        firstArrival[0] = 0;

        while (!q.empty())
        {
            auto [node, curr_time] = q.front();
            q.pop();

            int wait_time = (curr_time / change) % 2 == 1 ? (change - (curr_time % change)) : 0;
            int new_time = curr_time + wait_time + time;

            for (int neighbor : adj[node])
            {
                if (new_time < firstArrival[neighbor])
                {
                    secondArrival[neighbor] = firstArrival[neighbor];
                    firstArrival[neighbor] = new_time;
                    q.push({neighbor, new_time});
                }
                else if (new_time > firstArrival[neighbor] && new_time < secondArrival[neighbor])
                {
                    secondArrival[neighbor] = new_time;
                    q.push({neighbor, new_time});
                }
            }
        }

        return secondArrival[n - 1] == INT_MAX ? -1 : secondArrival[n - 1];
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> topoSort(vector<vector<int>> &adj, int V)
    {
        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return topo;
    }

public:
    string findOrder(string dict[], int n, int k)
    {
        vector<vector<int>> adj(k);

        for (int i = 0; i < n - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int len = min(s1.length(), s2.length());

            for (int idx = 0; idx < len; idx++)
            {
                if (s1[idx] != s2[idx])
                {
                    adj[s1[idx] - 'a'].push_back(s2[idx] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(adj, k);

        string ans = "";

        for (int node : topo)
        {
            ans += node + 'a';
        }

        return ans;
    }
};

int main()
{

    return 0;
}
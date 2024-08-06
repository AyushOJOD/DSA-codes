#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<int> adj[numCourses];

        for (auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> inDegree(numCourses);

        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

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

        unordered_map<int, unordered_set<int>> mp;

        for (int i = 0; i < numCourses; i++)
        {
            mp[i] = unordered_set<int>();
        }

        for (int i = 0; i < numCourses; i++)
        {
            int u = topo[i];

            for (auto v : adj[u])
            {
                mp[v].insert(u);

                mp[v].insert(mp[v].begin(), mp[v].end());
            }
        }

        vector<bool> ans;

        for (auto q : queries)
        {
            int u = q[0];
            int v = q[1];

            if (mp[u].find(v) != mp[u].end())
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}
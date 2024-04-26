#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, rank;
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int rootU = findUPar(u);
        int rootV = findUPar(v);

        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    unordered_map<string, int> emailToIndex;
    DisjointSet ds(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (emailToIndex.find(accounts[i][j]) == emailToIndex.end())
            {
                emailToIndex[accounts[i][j]] = i;
            }
            else
            {
                ds.unionByRank(i, emailToIndex[accounts[i][j]]);
            }
        }
    }

    vector<string> mergedMail[n];

    for (auto it : emailToIndex)
    {
        string mail = it.first;
        int node = ds.findUPar(it.second);

        mergedMail[node].push_back(mail);
    }

    vector<vector<string>> res;

    for (int i = 0; i < n; i++)
    {
        if (mergedMail[i].size() == 0)
            continue;

        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;

        temp.push_back(accounts[i][0]);

        for (auto it : mergedMail[i])
        {
            temp.push_back(it);
        }
        res.push_back(temp);
    }

    return res;
}

int main()
{

    return 0;
}
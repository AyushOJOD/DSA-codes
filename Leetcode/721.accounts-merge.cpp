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

    DisjointSet ds(n);

    // add the value to map and use ds
    unordered_map<string, int> accountMap;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string currAccount = accounts[i][j];

            if (accountMap.find(currAccount) == accountMap.end())
            {
                accountMap[currAccount] = i;
            }
            else
            {
                ds.unionByRank(i, accountMap[currAccount]);
            }
        }
    }

    // storing the data in required format

    vector<string> mergedMail[n];

    for (auto it : accountMap)
    {
        string mail = it.first;
        int node = ds.findUPar(it.second);

        mergedMail[node].push_back(mail);
    }

    // get the result
    vector<vector<string>> result;

    for (int i = 0; i < n; i++)
    {
        if (mergedMail[i].size() == 0)
        {
            continue;
        }

        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;

        temp.push_back(accounts[i][0]);

        for (auto it : mergedMail[i])
        {
            temp.push_back(it);
        }
        result.push_back(temp);
    }
    return result;
}

int main()
{

    return 0;
}
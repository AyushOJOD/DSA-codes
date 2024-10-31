#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void helper(vector<vector<int>> &graph, vector<vector<int>> &res, vector<int> &curr, int node)
    {
        curr.push_back(node);
        if (node == graph.size() - 1)
        {
            res.push_back(curr);
            return;
        }
        else
        {
            for (int i = 0; i < graph[node].size(); i++)
            {
                helper(graph, res, curr, graph[node][i]);
            }
        }
        curr.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> curr;
        vector<vector<int>> res;

        helper(graph, res, curr, 0);
        return res;
    }
};

int main()
{

    return 0;
}
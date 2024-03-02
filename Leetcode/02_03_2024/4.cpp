#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> nums;
int k;

void dfs(int node, int parent, vector<int> &xorVals, long long &result)
{
    xorVals[node] = (parent == -1) ? nums[node] : (xorVals[parent] ^ nums[node]);
    result += xorVals[node];
    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfs(child, node, xorVals, result);
        }
    }
}

long long maxSum(int n)
{
    vector<int> xorVals(n, 0);
    long long result = 0;
    dfs(0, -1, xorVals, result);
    long long maxResult = 0;
    for (int i = 0; i < n; ++i)
    {
        maxResult = max(maxResult, result - xorVals[i] + (xorVals[i] ^ k));
    }
    return maxResult;
}

int main()
{
    int n;
    cin >> n;
    tree.resize(n);
    nums.resize(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cin >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << maxSum(n) << endl;

    return 0;
}

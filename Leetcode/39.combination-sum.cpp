#include <bits/stdc++.h>
using namespace std;

void findComb(vector<int> &candidates, int target, vector<int> &ds, int idx, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(ds);
        return;
    }

    if (idx >= candidates.size())
    {
        return;
    }

    if (candidates[idx] <= target)
    {
        ds.push_back(candidates[idx]);
        findComb(candidates, target - candidates[idx], ds, idx, res);
        ds.pop_back();
    }

    findComb(candidates, target, ds, idx + 1, res);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> ds;
    vector<vector<int>> res;
    f(candidates, target, ds, 0, res);

    return res;
}

int main()
{

    return 0;
}
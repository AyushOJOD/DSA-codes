#include <bits/stdc++.h>
using namespace std;

void findComb(vector<int> &candidates, int target, vector<int> &ds, int idx, set<vector<int>> &res)
{
    if (target == 0)
    {
        res.insert(ds);
        return;
    }

    if (idx >= candidates.size())
    {
        return;
    }

    ds.push_back(candidates[idx]);
    findComb(candidates, target - candidates[idx], ds, idx + 1, res);
    ds.pop_back();
    findComb(candidates, target, ds, idx + 1, res);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    set<vector<int>> res;
    vector<int> ds;

    findComb(candidates, target, ds, 0, res);

    vector<vector<int>> final(res.begin(), res.end());

    return final;
}

int main()
{

    return 0;
}
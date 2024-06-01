#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &nums, vector<int> &ds, vector<int> &freq, vector<vector<int>> &res)
{
    if (ds.size() == nums.size())
    {
        res.push_back(ds);
    }

    for (int idx = 0; idx < num.size(); idx++)
    {
        if (!freq[idx])
        {
            ds.push_back(nums[idx]);
            freq[idx] = 1;
            func(nums, ds, freq, res);
            ds.pop_back();
            freq[idx] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> ds;
    vector<int> freq(nums.size(), 0);

    func(nums, ds, freq, res);

    return res;
}

int main()
{

    return 0;
}
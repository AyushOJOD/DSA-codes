#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printS(vector<int> &nums, vector<int> &ds, int sum, int idx, int target, vector<vector<int>> &res)
{
    if (idx == nums.size())
    {
        if (sum == target)
        {
            res.push_back(ds);
            return;
        }
    }

    ds.push_back(nums[idx]);
    sum += nums[idx];
    printS(nums, ds, sum, idx + 1, target, res);
    ds.pop_back();
    sum -= nums[idx];
    printS(nums, ds, sum, idx + 1, target, res);
}

int main()
{

        return 0;
}
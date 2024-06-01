#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &nums, int k, int sum, vector<vector<int>> &res, int idx, int currSum, vector<int> &ds)
{
    if (currSum == sum)
    {
        res.push_back(ds);
        return;
    }

    if (idx >= nums.size())
        return;

    for (int i = idx; i < nums.size(); i++)
    {
        if (currSum + nums[i] > sum)
            break;

        ds.push_back(nums[i]);
        int temp = nums[i];
        nums[i] = 0;
        currSum += nums[i];
        func(nums, k, sum, res, i + 1, currSum, ds);
        currSum -= nums[i];
        nums[i] = temp;
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> res;
    vector<int> ds;

    func(nums, k, n, res, 0, 0, ds);

    return res;
}

int main()
{

    return 0;
}
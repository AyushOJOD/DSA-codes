#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &nums, int idx, vector<int> &ds, vector<vector<int>> &final)
{

    final.push_back(ds);

    for (int i = idx; i < nums.size(); i++)
    {
        if (i != idx && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        func(nums, i + 1, ds, final);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> final;
    vector<int> ds;
    sort(nums.begin(), nums.en());

    func(nums, 0, ds, final);

    return final;
}

int main()
{

    return 0;
}
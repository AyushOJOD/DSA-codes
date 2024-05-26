#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &nums, int idx, vector<int> &temp, vector<vector<int>> &res)
{

    res.push_back(temp);

    for (int i = idx; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);     // added
        dfs(nums, i + 1, temp, res); // dfs for next level
        temp.pop_back();             // remove(backtrack)
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> temp;
    vector<vector<int>> res;

    dfs(nums, 0, temp, res);

    return res;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int idx, int prev, vector<vector<int>> &dp)
{
    // base case
    if (idx == nums.size())
    {
        return 0;
    }

    if (dp[idx][prev + 1] != -1)
    {
        return dp[idx][prev + 1];
    }

    int notTake = 0 + helper(nums, idx + 1, prev, dp);

    int take = 0;

    if (prev == -1 || nums[idx] > nums[idx - 1])
    {
        take = 1 + helper(nums, idx + 1, idx, dp);
    }

    return dp[idx][prev + 1] = max(notTake, take);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return helper(nums, 0, -1, dp);
}

int main()
{

    return 0;
}
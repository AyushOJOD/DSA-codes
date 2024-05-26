#include <bits/stdc++.h>
using namespace std;

// Memoization

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    vector<int> dp(nums.size(), -1);

    return f(nums, n - 1, dp);
}

int f(vector<int> &nums, int idx, vector<int> &dp)
{
    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    if (idx == 0)
    {
        return nums[idx];
    }
    if (idx < 0)
    {
        return 0;
    }

    int pick = nums[idx] + f(nums, idx - 2, dp);
    int notPick = 0 + f(nums, idx - 1, dp);

    return dp[idx] = max(pick, notPick);
}

// Tabulation

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();

    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            take += prev2;

        int notPick = prev;

        curr = max(pick, notPick);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{

    return 0;
}
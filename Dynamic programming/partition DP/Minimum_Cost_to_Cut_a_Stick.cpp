#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int mini = INT_MAX;

        for (int k = i; k <= j; k++)
        {
            int cost = (nums[j + 1] - nums[i - 1]) + helper(nums, i, k - 1, dp) + helper(nums, k + 1, j.dp);

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        vector<int> nums;

        nums.push_back(0);

        for (int i = 0; i < cuts.size(); i++)
        {
            nums.push_back(cuts[i]);
        }

        nums.push_back(n);

        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

        return helper(nums, 1, nums.size() - 2, dp);
    }
};

int main()
{

    return 0;
}
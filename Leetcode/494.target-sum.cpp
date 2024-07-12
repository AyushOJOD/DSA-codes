#include <bits/stdc++.h>
using namespace std;

// Find the number of subsets with sum = (TotalSum - target)/2

class Solution
{
private:
    int helper(vector<int> &nums, int sum, int idx, vector<vector<int>> &dp)
    {

        int n = nums.size();

        // base case

        if (idx = n - 1)
        {
            if (sum == 0 && nums[n - 1] == 0)
            {
                return 2;
            }
            if (sum == 0 || sum == nums[n - 1])
            {
                return 1;
            }
            return 0;
        }

        if (dp[idx][sum] != -1)
        {
            return dp[idx][sum];
        }

        // recursion

        int notTake = helper(nums, sum, idx + 1, dp);

        int take = 0;

        if (nums[idx] <= sum)
        {
            take = helper(nums, sum - nums[idx], idx + 1, dp);
        }

        return dp[idx][sum] = take + notTake;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalSum = 0;

        for (int it : nums)
        {
            totalSum += it;
        }

        if (totalSum < target)
        {
            return 0;
        }

        int sum = (totalSum - target) / 2;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));

        return helper(nums, sum, 0, dp);
    }
};

int main()
{

    return 0;
}
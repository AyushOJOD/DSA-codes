#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool helper(vector<int> &nums, int idx, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
        {
            return true;
        }

        if (sum < 0 || idx >= nums.size())
        {
            return false;
        }

        if (dp[idx][sum] != -1)
        {
            return dp[idx][sum];
        }

        bool pick = helper(nums, idx + 1, sum - nums[idx], dp);
        bool notPick = helper(nums, idx + 1, sum, dp);

        return dp[idx][sum] = pick || notPick;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;

        for (auto it : nums)
        {
            totalSum += it;
        }

        if (totalSum % 2 != 0)
        {
            return false;
        }

        int sum = totalSum / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));

        return helper(nums, 0, sum, dp);
    }
};

int main()
{

    return 0;
}
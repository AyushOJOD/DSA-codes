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

        int maxi = INT_MIN;

        for (int k = i; k <= j; k++)
        {
            int coins = nums[i - 1] * nums[k] * nums[j + 1] + helper(nums, i, k - 1, dp) + helper(nums, k + 1, j, dp);

            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

        return helper(nums, 1, nums.size() - 2, dp);
    }
};

int main()
{

    return 0;
}
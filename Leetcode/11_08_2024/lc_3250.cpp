#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // For v1:
    // nums[idx] >= prev1;
    // For v2:
    // nums[idx] <= prev2;

public:
    int MOD = 1e9 + 7;

    int helper(vector<int> &nums, int idx, int prev1, int prev2, int n, vector<vector<vector<int>>> &dp)
    {
        if (idx == n)
        {
            return 1;
        }

        if (dp[idx][prev1][prev2] != -1)
        {
            return dp[idx][prev1][prev2];
        }

        int cnt = 0;
        for (int i = prev1; i <= nums[idx]; i++)
        {
            int a = i, b = nums[idx] - i;

            if (a >= prev1 && b <= prev2)
            {
                cnt = (cnt + helper(nums, idx + 1, a, b, n, dp)) % MOD;
            }
        }

        return dp[idx][prev1][prev2] = cnt;
    }

    int countOfPairs(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(1001, vector<int>(1001, -1)));

        int maxEl = *max_element(nums.begin(), nums.end());

        return helper(nums, 0, 0, maxEl, n, dp);
    }
};

int main()
{

    return 0;
}
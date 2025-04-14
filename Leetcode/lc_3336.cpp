#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getGCD(long long a, long long b)
    {
        if (b == 0)
        {
            return a;
        }
        return getGCD(b, a % b);
    }

    int helper(vector<int> &nums, int gcd1, int gcd2, int idx, vector<vector<vector<int>>> dp)
    {
        if (idx >= nums.size())
        {
            return (gcd1 == gcd2);
        }

        if (dp[idx][gcd1][gcd2] != -1)
        {
            return dp[idx][gcd1][gcd2];
        }

        int takeTo1 = helper(nums, getGCD(gcd1, nums[idx]), gcd2, idx + 1, dp) % MOD;
        int takeTo2 = helper(nums, gcd1, getGCD(gcd2, nums[idx]), idx + 1, dp) % MOD;
        int notTake = helper(nums, gcd1, gcd2, idx + 1, dp) % MOD;

        return dp[idx][gcd1][gcd2] = (takeTo1 + takeTo2 + notTake) % MOD;
    }

public:
    const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int> &nums)
    {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(maxi + 1, vector<int>(maxi + 1, -1)));

        return (helper(nums, 0, 0, 0, dp) - 1 + MOD) % MOD;
    }
};

int main()
{

    return 0;
}
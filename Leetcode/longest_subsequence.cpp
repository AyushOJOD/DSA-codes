#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubsequence(vector<int> &nums, int target)
{
    vector<int> dp(target + 1, -1);
    dp[0] = 0;

    for (int num : nums)
    {
        for (int currSum = target; currSum >= num; currSum--)
        {
            if (dp[currSum - num] != -1)
            {
                dp[currSum] = max(dp[currSum], dp[currSum - num] + 1);
            }
        }
    }

    return dp[target] != -1 ? dp[target] : -1;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int totalSum = 0;

        int n = nums.size();

        for (int num : nums)
        {
            totalSum += num;
        }

        int sum = totalSum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        if (nums[0] <= sum)
        {
            dp[0][nums[0]] = true;
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target < sum; target++)
            {
                bool notTake = dp[i - 1][]
            }
        }
    }
};

int main()
{

    return 0;
}
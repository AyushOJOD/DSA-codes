#include <bits/stdc++.h>
using namespace std;

int maximumLength(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 1));
    int ans = 1;
    vector<int> temp(k + 1, -1);
    vector<map<int, int>> freq(k + 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l < j; l++)
            {
                dp[i][j] = max(dp[i][j], 1 + temp[l]);
            }

            if (freq[j].find(nums[i]) != freq[j].end())
            {
                dp[i][j] = max(dp[i][j], 1 + freq[j][nums[i]]);
            }

            ans = max(ans, dp[i][j]);
        }

        for (int j = 0; j <= k; j++)
        {
            temp[j] = max(temp[j], dp[i][j]);
            freq[j][nums[i]] = max(freq[j][nums[i]], dp[i][j]);
        }
    }

    return ans;
}

int main()
{

    return 0;
}
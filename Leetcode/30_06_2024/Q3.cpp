#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 1));

        table(nums, k, dp);

        return findMaxSubsequenceLength(dp);
    }

private:
    void table(vector<int> &nums, int k, vector<vector<int>> &dp)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int remainder = (nums[i] + nums[j]) % k;
                dp[i][remainder] = max(dp[i][remainder], dp[j][remainder] + 1);
            }
        }
    }

    int findMaxSubsequenceLength(vector<vector<int>> &dp)
    {
        int maxVal = 0;
        for (auto &row : dp)
        {
            for (int it : row)
            {
                maxVal = max(maxVal, it);
            }
        }
        return maxVal;
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dp[2001][4001];

int helper(vector<int> &rewardValues, int n, int collected, int idx)
{
    // Base case
    if (idx >= n)
    {
        return 0;
    }

    if (dp[idx][collected] != -1)
    {
        return dp[idx][collected];
    }

    int pick = 0;

    if (collected < rewardValues[idx])
    {
        pick = rewardValues[idx] + helper(rewardValues, n, collected + rewardValues[idx], idx + 1);
    }

    int notPick = helper(rewardValues, n, collected, idx + 1);

    return dp[idx][collate] = max(pick, notPick);
}

int maxTotalReward(vector<int> &rewardValues)
{
    int n = rewardValues.size();

    memset(dp, -1, sizeof(dp));

    sort(rewardValues.begin(), rewardValues.end());

    return helper(rewardValues, n, 0, 0, dp);
}

int main()
{

    return 0;
}
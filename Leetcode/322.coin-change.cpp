#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp)
{
    // Base case
    if (idx == 0)
    {
        if (amount % coins[idx] == 0)
        {
            return amount / coins[idx];
        }
        else
        {
            return INT_MAX - 1;
        }
    }

    if (dp[idx][amount] != -1)
    {
        return dp[idx][amount];
    }

    int notPick = func(coins, amount, idx - 1, dp);
    int pick = INT_MAX - 1;

    if (coins[idx] <= amount)
    {
        pick = 1 + func(coins, amount - coins[idx], idx, dp);
    }

    return dp[idx][amount] = min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0)); // dp[idx][amount]
}

int main()
{

    return 0;
}
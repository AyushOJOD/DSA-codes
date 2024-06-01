#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp)
{
    // Base cases
    if (amount == 0)
    {
        return 1; // There is one way to make amount 0, by choosing nothing
    }
    if (idx < 0)
    {
        return 0; // No coins left to use
    }
    if (amount < 0)
    {
        return 0; // Invalid amount
    }

    if (dp[idx][amount] != 0)
    {
        return dp[idx][amount];
    }

    int notTake = func(coins, amount, idx - 1, dp);

    // Take the current coin
    int take = 0;
    if (coins[idx] <= amount)
    {
        take = func(coins, amount - coins[idx], idx, dp);
    }

    return dp[idx][amount] = take + notTake;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount, 0)); // dp[idx][amount]

    for (int idx = 0; idx < n; idx++)
    {
        dp[idx][0] = 1;
    }

    for (int idx = 1; idx <= n; idx++)
    {
        for (int val = 1; val <= amount; val++)
        {
            int notTake = dp[idx - 1][val];

            int take = 0;
            if (coins[idx - 1] <= val)
            {
                take = dp[idx][val - coins[idx - 1]];
            }

            dp[idx][val] = take + notTake;
        }
    }

    return dp[n][amount];
}

int main()
{

    return 0;
}
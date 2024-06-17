#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &prices, int fee, int idx, bool canBuy, vector<vector<int>> &dp)
{
    // Base case
    if (idx == prices.size())
    {
        return 0;
    }

    if (dp[idx][canBuy] != -1)
    {
        return dp[idx][canBuy];
    }

    // recursive

    int profit = 0;

    if (canBuy)
    {
        int notBuy = helper(prices, fee, idx + 1, 1, dp);
        int buy = helper(prices, fee, idx + 1, 0, dp) - prices[idx];

        profit = max(buy, notBuy);
    }
    else
    {
        int notSell = helper(prices, fee, idx + 1, 0, dp);
        int sell = helper(prices, fee, idx + 1, 1, dp) + prices[idx] - fee;

        profit = max(sell, notSell);
    }

    return dp[idx][canBuy] = profit;
}

int maxProfit(vector<int> &prices, int fee)
{

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    dp[n][0] = dp[n][1] = 0;

    for (int idx = n;)
}

int main()
{

    return 0;
}

// Variations : idx, canBuy
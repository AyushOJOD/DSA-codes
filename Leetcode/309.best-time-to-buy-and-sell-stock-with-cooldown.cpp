#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &prices, int idx, bool canBuy, vector<vector<int>> &dp)
{
    // Base case
    if (idx >= prices.size())
    {
        return 0;
    }

    if (dp[idx][canBuy] != -1)
    {
        return dp[idx][canBuy];
    }

    int profit = 0;

    if (canBuy)
    {
        int buy = helper(prices, idx + 1, 0, dp) - prices[idx];
        int notBuy = helper(prices, idx + 1, 1, dp);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = helper(prices, idx + 2, 1, dp) + prices[idx];
        int notSell = helper(prices, idx + 1, 0, dp);
        profit = max(sell, notSell);
    }

    return dp[idx][canBuy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            int profit = 0;

            if (canBuy)
            {
                int buy = dp[idx + 1][0] - prices[idx];
                int notBuy = dp[idx + 1][1];
                profit = max(buy, notBuy);
            }
            else
            {
                int sell = dp[idx + 2][1] + prices[idx];
                int notSell = dp[idx + 1][0];
                profit = max(sell, notSell);
            }

            dp[idx][canBuy] = profit;
        }
    }

    return dp[0][1];
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &prices, int idx, bool canBuy, vector<vector<int>> &dp)
{
    // base case
    if (idx == prices.size())
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
        int buy = helper(prices, idx + 1, false, dp) - prices[idx];

        int notBuy = helper(prices, idx + 1, true, dp);

        profit = max(buy, notBuy);
    }
    else
    {
        int sell = helper(prices, idx + 1, true, dp) + prices[idx];
        int notSell = helper(prices, idx + 1, false, dp);

        profit = max(sell, notSell);
    }

    return dp[idx][canBuy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<int> curr(2, 0);
    vector<int> ahead(2, 0);

    ahead[0] = ahead[1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int canBuy = 0; canBuy < 2; canBuy++)
        {
            int profit = 0;

            if (canBuy)
            {
                int buy = ahead[0] - prices[idx];
                int notBuy = ahead[1];
                profit = max(buy, notBuy);
            }
            else
            {
                int sell = ahead[1] + prices[idx];
                int notSell = ahead[0];
                profit = max(sell, notSell);
            }

            curr[canBuy] = profit;
        }
        ahead = curr;
    }

    return ahead[1];
}

int main()
{

    return 0;
}
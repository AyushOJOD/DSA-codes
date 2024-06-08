#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &prices, int idx, bool canBuy, int transactions, vector<vector<vector<int>>> &dp)
{
    // base case
    if (idx == prices.size())
    {
        return 0;
    }

    if (transactions == 2)
    {
        return 0;
    }

    if (dp[idx][canBuy][transactions] != -1)
    {
        return dp[idx][canBuy][transactions];
    }

    int profit = 0;

    if (canBuy)
    {
        int buy = helper(prices, idx + 1, false, transactions, dp) - prices[idx];
        int notBuy = helper(prices, idx + 1, true, transactions, dp);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = helper(prices, idx + 1, true, transactions + 1, dp) + prices[idx];
        int notSell = helper(prices, idx + 1, false, transactions, dp);
        profit = max(sell, notSell);
    }

    return dp[idx][canBuy][transactions] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0))); // dp[idx][canBuy][transactions]

    // Base case for trans actions
    for (int idx = 0; idx < n; idx++)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            dp[idx][canBuy][2] = 0;
        }
    }

    // Base case for idx
    for (int canBuy = 0; canBuy <= 1; canBuy++)
    {
        for (int tc = 0; tc <= 2; tc++)
        {
            dp[n][canBuy][tc] = 0;
        }
    }

    // recursion

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int tc = 0; tc <= 2; tc++)
            {
                int profit = 0;

                if (canBuy)
                {
                    int buy = dp[idx + 1][0][tc] - prices[idx];
                    int notBuy = dp[idx + 1][1][tc];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = dp[idx + 1][1][tc + 1] + prices[idx];
                    int notSell = dp[idx + 1][false][tc];
                    profit = max(sell, notSell);
                }
            }
        }
    }

    return dp[0][1][0];
}

int main()
{

    return 0;
}
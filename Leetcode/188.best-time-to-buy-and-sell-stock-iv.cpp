#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<int> &prices, int k, bool canBuy, int idx, vector<vector<vector<int>>> &dp)
    {
        int n = prices.size();

        // base case
        if (idx == n || k == 0)
        {
            return 0;
        }

        if (dp[idx][k][canBuy] != -1)
        {
            return dp[idx][k][canBuy];
        }

        int profit = 0;

        if (canBuy)
        {
            int buy = helper(prices, k, 0, idx + 1, dp) - prices[idx];

            int notBuy = helper(prices, k, 1, idx + 1, dp);

            profit = max(buy, notBuy);
        }

        else
        {
            int sell = helper(prices, k - 1, 1, idx + 1, dp) + prices[idx];
            int notSell = helper(prices, k, 0, idx + 1, dp);

            profit = max(sell, notSell);
        }

        return dp[idx][k][canBuy] = profit;
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();

        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
    }
};

int main()
{

    return 0;
}
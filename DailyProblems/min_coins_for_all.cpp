#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<int> &prices, int curr, int collected)
    {
        int n = prices.size();

        if (curr >= n)
        {
            return 0;
        }

        if (dp[curr][collected] != -1)
        {
            return dp[curr][collected];
        }

        if (collected == 0)
        {
            return prices[curr] + helper(prices, curr + 1, curr + 1);
        }

        int ans = helper(prices, curr + collected, 0);

        for (int i = curr; i <= min(n - 1, curr + collected - 1); i++)
        {
            ans = min(ans, prices[i] + helper(prices, i + 1, i + 1));
        }

        return dp[curr][collected] = ans;
    }

public:
    int dp[1001][1001];
    int minimumCoins(vector<int> &prices)
    {

        memset(dp, -1, sizeof(dp));
        return helper(prices, 0, 0);
    }
};

int main()
{

    return 0;
}
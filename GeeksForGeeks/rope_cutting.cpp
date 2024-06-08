#include <bits/stdc++.h>
using namespace std;

int func(int price[], int n, int idx, vector<vector<int>> &dp)
{
    // Base case

    if (idx == 0)
    {
        return (n * price[0]);
    }

    if (dp[idx][n] != -1)
    {
        return dp[idx][n];
    }

    int notPick = 0 + func(price, n, idx - 1, dp);
    int pick = INT_MIN;

    if (n >= idx + 1)
    {
        pick = price[idx] + func(price, n - (idx + 1), idx, dp);
    }

    return dp[idx][n] = max(pick, notPick);
}

int cutRod(int price[], int n)
{
    // code here

    vector<vector<int>> dp(n, vector<int>(n + 1, 0)); // dp[idx][n]

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int size = 0; size <= n; size++)
        {
            int notPick = dp[idx - 1][size];
            int pick = INT_MIN;
            if (size >= idx + 1)
            {
                pick = dp[idx][size - (idx + 1)] + price[idx];
            }

            dp[idx][size] = max(pick, notPick);
        }
    }

    return dp[n - 1][n];
}

int main()
{

    return 0;
}
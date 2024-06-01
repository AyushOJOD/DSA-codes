#include <bits/stdc++.h>
using namespace std;

// Changing variables = Weight, idx

int func(int W, int wt[], int val[], int n, int idx, vector<vector<int>> &dp)
{

    if (idx == 0)
    {
        if (W >= wt[idx])
        {
            return val[idx];
        }
        else
        {
            return 0;
        }
    }

    if (dp[W][idx] != -1)
    {
        return dp[W][idx];
    }

    int notPick = func(W, wt, val, n, idx - 1, dp);
    int pick = INT_MIN;

    if (wt[idx] <= W)
    {
        pick = val[idx] + func(W - wt[idx], wt, val, n, idx - 1, dp);
    }

    return dp[W][idx] = max(pick, notPick);
}

int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here

    vector<vector<int>> dp(W + 1, vector<int>(n, 0)); // dp[weight][idx]

    vector<int> prev(n, 0);
    vector<int> curr(n, 0);

    for (int w = wt[0]; w <= W; w++)
    {
        prev[0] = val[0];
    }

    for (int w = 0; w <= W; w++)
    {
        for (int idx = 1; idx < n; idx++)
        {
            int notPick = dp[w][idx - 1];
            int pick = INT_MIN;
            if (wt[idx] <= w)
            {
                pick = val[idx] + dp[w - wt[idx]][idx - 1];
            }

            dp[w][idx] = max(pick, notPick);
        }
    }

    return dp[W][n - 1];
}

int main()
{

    return 0;
}
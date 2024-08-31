#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(int w, vector<int> &wt, vector<int> &val, int idx, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (wt[idx] <= w)
            {
                return val[idx];
            }
            else
            {
                return 0;
            }
        }

        if (dp[w][idx] != -1)
        {
            return dp[w][idx];
        }

        int take = INT_MIN;

        if (wt[idx] <= w)
        {
            take = helper(w - wt[idx], wt, val, idx - 1, dp) + val[idx];
        }

        int notTake = helper(w, wt, val, idx - 1, dp);

        return dp[w][idx] = max(take, notTake);
    }

public:
    int knapSack(int W, vector<int> &wt, vector<int> &val)
    {
        int n = wt.size();

        vector<vector<int>> dp(W + 1, vector<int>(n, -1));

        return helper(W, wt, val, n - 1, dp);
    }
};

int main()
{

    return 0;
}
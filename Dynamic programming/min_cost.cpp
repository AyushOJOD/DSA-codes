#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &num, int x, vector<int> &dp, int idx)
{
    if (x == 0)
        return 0;
    if (idx >= num.size())
        return INT_MAX;
    if (dp[x] != -1)
        return dp[x];

    int notTake = func(num, x, dp, idx + 1);
    int take = INT_MAX;
    if (num[idx] <= x)
    {
        int val = func(num, x - num[idx], dp, idx);

        if (val != INT_MAX)
        {
            take = val + 1;
        }
    }

    dp[x] = min(take, notTake);
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> dp(num.size(), -1);

    int res = func(num, x, dp, 0);

    return (res != INT_MAX) ? res : -1;
}

int main()
{

    return 0;
}
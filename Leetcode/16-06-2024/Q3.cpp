#include <bits/stdc++.h>
using namespace std;

long long helper(vector<int> &power, int idx, int prev)
{
    int n = power.size();

    // Base case
    if (idx == n)
    {
        return 0;
    }

    if (dp[idx][prev] != -1)
    {
        return dp[idx][prev];
    }

    // recursion

    long long notTake = 0 + helper(power, idx + 1, prev);

    long long take = INT_MIN;

    if (prev + 2 != power[idx] && prev + 1 != power[idx] && prev - 1 != power[idx] && prev - 2 != power[idx])
    {
        take = power[idx] + helper(power, idx + 1, power[idx]);
    }

    return dp[idx][prev] = max(take, notTake);
}

long long maximumTotalDamage(vector<int> &power)
{
    sort(power.begin(), power.end());

    vector<vector<long long>> dp(n, vector<long long>(n, -1));

    return helper(power, 0, -2);
}

int main()
{

    return 0;
}
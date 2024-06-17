// There is a scientist who is working on a virus. He has n virus he can add or subtract 1 from the count or may reduce the size of the virus by half. Find the minimum number of operations to reduce the virus to 1.

#include <bits/stdc++.h>
using namespace std;

int helper(int n, vector<int> &dp)
{
    // base case
    if (n == 1)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int addOne = solve(n + 1) + 1;
    int subOne = solve(n - 1) + 1;

    int divide = INT_MAX;

    if (n % 2 == 0)
    {
        divide = solve(n / 2) + 1;
    }

    return dp[n] = min(divide, min(addOne, subOne));
}

int solve(int n)
{
    vector<int> dp(n + 1, -1);

    return helper(n, dp);
}

int main()
{

    return 0;
}
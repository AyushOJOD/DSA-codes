#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int idx, int cnt, int n, vector<vector<int>> &dp)
{
    // Base case
    if (cnt == n / 2)
    {
        return 0;
    }

    if (idx == n)
    {
        return 0;
    }

    if (dp[idx][cnt] != -1)
    {
        return dp[idx][cnt];
    }

    int notTake = solve(a, idx + 1, cnt, n, dp);

    int take = a[idx] ^ solve(a, idx + 1, cnt + 1, n, dp);

    return dp[idx][cnt] = max(take, notTake);
}

int main()
{

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(n / 2 + 1, -1));

    return solve(a, 0, 0, n, dp);

    return 0;
}
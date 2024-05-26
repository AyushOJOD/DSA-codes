#include <bits/stdc++.h>
using namespace std;

int frogJumpK(int n, vector<int> &heights, int k)
{

    vector<int> dp(n, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                minSteps = min(minSteps, (dp[i - j] + abs(heights[i] - heights[i - j])));
            }
        }
        dp[i] = minSteps;
    }
    return dp[n - 1];
}

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> heights(n);

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    cout << frogJumpK(n, heights, k) << endl;

    return 0;
}
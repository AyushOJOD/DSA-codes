#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n);

    dp[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = max(dp[i + 1] + 1, a[i]);
    }

    cout << dp[0] << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
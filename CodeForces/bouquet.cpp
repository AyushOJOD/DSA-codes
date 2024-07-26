#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    long long m;
    cin >> n >> m;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int left = 0;
    long long sum = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        while (sum > m || (left < n && ((a[i] - a[left]) > 1)))
        {
            sum -= a[left];
            left++;
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
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
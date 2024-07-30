#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            ans = max(ans, a[i]);
        }
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
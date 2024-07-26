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

    int max_diff = 0, coins = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int curr_diff = a[i] - a[i + 1];
        if (curr_diff > 0)
        {
            if (curr_diff > max_diff)
            {
                curr_diff -= max_diff;
                max_diff = curr_diff;
                coins += i + 3;
            }
        }
    }

    cout << coins << endl;
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
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    x--, y--;

    vector<int> a(n);

    int curr = -1;
    for (int i = y - 1; i >= 0; i--)
    {
        a[i] = curr;
        curr = -curr;
    }

    curr = -1;
    for (int i = x + 1; i < n; i++)
    {
        a[i] = curr;
        curr = -curr;
    }

    for (int i = y; i <= x; i++)
    {
        a[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
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
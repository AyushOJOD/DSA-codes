#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n;

    cin >> n;

    int ans = log(n) / log(2);

    cout << fixed << setprecision(0) << pow(2, ans) << endl;
}

int main()
{
    long long tst;

    cin >> tst;

    while (tst--)
    {
        solve();
    }

    return 0;
}
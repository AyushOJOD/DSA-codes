#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    long long maxProfit = 0;

    int k = min(n, b);

    for (int i = 0; i <= k; i++)
    {
        long long promoPrice = 0;

        for (int j = 1; j <= i; j++)
        {
            promoPrice += (b - j + 1);
        }

        promoPrice += (n - i) * (long long)a;

        maxProfit = max(maxProfit, promoPrice);
    }

    cout << maxProfit << endl;
}

int main()
{
    int tst;
    cin >> tst;

    while (tst--)
    {
        solve();
    }

    return 0;
}

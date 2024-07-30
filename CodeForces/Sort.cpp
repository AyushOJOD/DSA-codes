#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a;
    cin >> b;

    int q;
    cin >> q;

    vector<vector<int>> query(q, vector<int>(2));

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> query[i][j];
        }
    }
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
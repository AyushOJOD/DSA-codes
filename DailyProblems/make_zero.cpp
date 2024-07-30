#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        a[i]--;
    }

    cost += x;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            cost += y;
        }
    }

    cout << cost;

    return 0;
}
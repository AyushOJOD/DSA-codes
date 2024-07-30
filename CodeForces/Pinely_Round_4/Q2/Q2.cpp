#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        n--;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<int> ans(n + 1);
        ans[0] = v[0];
        ans[n] = v[n - 1];
        for (int i = 1; i < n; i++)
        {
            ans[i] = v[i] | v[i - 1];
        }
        int ok = 0;
        for (int i = 0; i < n; i++)
        {
            if ((ans[i] & ans[i + 1]) != v[i])
            {
                ok = 1;
                break;
            }
        }
        if (ok)
            cout << -1 << endl;
        else
        {
            for (auto i : ans)
                cout << i << " ";
            cout << endl;
        }
    }
}
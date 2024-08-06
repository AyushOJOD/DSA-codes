#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int a = 0, b = 0, c = 0, d = 0, x = 0;

    for (int i = 0; i < 4 * n; i++)
    {
        if (s[i] == 'A')
        {
            a++;
        }
        else if (s[i] == 'B')
        {
            b++;
        }
        else if (s[i] == 'C')
        {
            c++;
        }
        else if (s[i] == 'D')
        {
            d++;
        }
        else
        {
            x++;
        }
    }

    cout << min(a, n) + min(b, n) + min(c, n) + min(d, n) << endl;
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
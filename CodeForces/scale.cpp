#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 20;
int n, k;
string s[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;

        for (int i = 0; i < n; i++)
            cin >> s[i];

        for (int i = 0; i < n; i += k)
        {
            for (int j = 0; j < n; j += k)
                cout << s[i][j];
            cout << endl;
        }
    }
}
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

        int cnt = 0;

        cnt += n / 4;
        int left = n % 4;

        if (left >= 2)
        {
            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
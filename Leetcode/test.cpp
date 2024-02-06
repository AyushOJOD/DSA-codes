#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;

    cin >> a >> b;

    int dif = a[0] - b[0];

    if (dif >= 0)
    {

        for (int cntr = 0; cntr < a.size(); cntr++)
        {
            if (a[cntr] - b[cntr] != dif && int((b[cntr] + dif) % 123) != int(a[cntr] - 'a'))
            {
                cout << "No";
                return 0;
            }
        }
        cout << "Yes";
        return 0;
    }
    else
    {

        dif = b[0] - a[0];
        for (int cntr = 0; cntr < a.size(); cntr++)
        {
            if (b[cntr] - a[cntr] != dif && int((a[cntr] + dif) % 123) != int(b[cntr] - 'a'))
            {
                cout << "No";
                return 0;
            }
        }

        return 0;
    }
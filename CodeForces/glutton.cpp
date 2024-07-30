#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<string> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int sweet_cnt = 0, dish_cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == "sweet")
        {
            sweet_cnt++;
            dish_cnt++;
            if (sweet_cnt >= 2)
            {
                break;
            }
        }
        else
        {
            sweet_cnt = 0;
            dish_cnt++;
        }
    }

    if (dish_cnt == n)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
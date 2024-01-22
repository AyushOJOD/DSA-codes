#include <bits/stdc++.h>
using namespace std;

bool isColliner(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2 == 0)
    {
        return true;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;

    vector<int> x;
    vector<int> y;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    int count = 0;

    int x1, y1, x2, y2, x3, y3;

    for (int i = 0; i < n - 2; i++)
    {
        x1 = x[i];
        y1 = y[i];
        x2 = x[i + 1];
        y2 = y[i + 1];
        x3 = x[i + 2];
        y3 = y[i + 2];
        if (isColliner(x1, y1, x2, y2, x3, y3))
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int a[], int n)
{
    // Code here
    vector<int> res;
    int lMax = a[n - 1];
    res.push_back(a[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > lMax)
        {
            res.push_back(a[i]);
            lMax = a[i];
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{

    return 0;
}
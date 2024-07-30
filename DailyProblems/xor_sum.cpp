#include <bits/stdc++.h>
using namespace std;

int xorSum(vector<int> &a, int x)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += x xor a[i];
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;

    int right;
    cin >> right;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int left = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
    }

    return 0;
}
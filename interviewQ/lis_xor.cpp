#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &a, int prev, int curr)
{
    int andVal = a[prev] & a[curr];
    int orVal = a[prev] | a[curr];

    return andVal * 2 < orVal;
}

int helper(vector<int> &a, int curr, int prev)
{
    if (curr == a.size())
    {
        return 0;
    }

    int notTake = 0 + helper(a, curr + 1, prev);

    int take = 0;

    if (prev == -1 || (a[curr] > a[prev] && isValid(a, prev, curr)))
    {
        take = 1 + helper(a, curr + 1, curr);
    }

    return max(take, notTake);
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << helper(a, 0, -1) << endl;

    return 0;
}
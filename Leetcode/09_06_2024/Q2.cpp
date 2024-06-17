#include <bits/stdc++.h>
using namespace std;

int valueAfterKSeconds(int n, int k)
{
    int MOD = 1e9 + 7;

    vector<int> v(n, 1);

    for (int i = 0; i < k; i++)
    {
        for (int i = 1; i < n; i++)
        {
            v[i] = (v[i] + v[i - 1]) % MOD;
        }
    }

    return v[n - 1] % MOD;
}

int main()
{

    return 0;
}
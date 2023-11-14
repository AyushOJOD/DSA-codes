#include <bits/stdc++.h>
using namespace std;

long long distributeCandies(int n, int limit)
{
    auto var = [](int n)
    {
        return 1LL * n * (n - 1) / 2;
    };
    if (n > 3 * limit)
    {
        return 0;
    }
    long long res = var(n + 2);
    if (n > limit)
    {
        res -= 3 * var(n - limit + 1);
    }
    if (n - 2 >= 2 * limit)
    {
        res += 3 * var(n - 2 * limit);
    }
    return res;
}

int main()
{

    cout << distributeCandies(3, 3);

    return 0;
}
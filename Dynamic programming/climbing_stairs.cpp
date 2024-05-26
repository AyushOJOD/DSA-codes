#include <bits/stdc++.h>
using namespace std;

int countWays(long long n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    int l = countWays(n - 1);
    int r = countWays(n - 2);

    return l + r;
}

int main()
{

    return 0;
}
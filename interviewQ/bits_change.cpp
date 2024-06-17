#include <bits/stdc++.h>
using namespace std;

int numOfBits(int n, int m)
{
    int val = n ^ m;

    return __builtin_popcount(val);
}

int main()
{
    int n = 5, m = 3;

    cout << numOfBits(n, m);

    return 0;
}
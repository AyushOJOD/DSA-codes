#include <bits/stdc++.h>
using namespace std;

int pivotInteger(int n)
{
    int sum = n * (n + 1) / 2;

    int leftSum = 0;

    for (int i = 1; i <= n; i++)
    {
        leftSum += i;
        if ((sum - leftSum + i) == leftSum)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    return 0;
}
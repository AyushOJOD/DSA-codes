#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int x)
{
    int left = 1, right = x;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        long long value = mid * mid;

        if (value <= x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}

int main()
{

    return 0;
}
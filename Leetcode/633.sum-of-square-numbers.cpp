#include <bits/stdc++.h>
using namespace std;

bool judgeSquareSum(int c)
{
    long long left = 0;
    long long right = (sqrt(c));

    while (left <= right)
    {
        long long sum = left * left + right * right;

        if (sum == c)
        {
            return true;
        }
        else if (sum > c)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return false;
}

int main()
{

    return 0;
}
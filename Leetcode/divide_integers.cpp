#include <bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor)
{
    int count = 0;
    int absDivisor = abs(divisor);
    int absDividend = abs(dividend);
    bool isDivisorPos = true;
    bool isDividendPos = true;
    int res = absDividend;

    if (dividend == INT_MAX)
    {
        return 
    }
    if(dividend == INT_MIN && divisor == 1){
        return INT_MIN;
    }
    if(dividend == INT_MAX && divisor == )

    if (divisor < 0)
    {
        isDivisorPos = false;
    }

    if (dividend < 0)
    {
        isDividendPos = false;
    }

    if (absDividend < absDivisor)
    {
        return 0;
    }
    else
    {
        while (res >= absDivisor)
        {
            res -= absDivisor;
            count++;
        }
    }

    if (isDivisorPos == false && isDividendPos == true)
    {
        return count - 2 * count;
    }
    else if (isDividendPos == false && isDivisorPos == true)
    {
        return count - 2 * count;
    }
    else
    {
        return count;
    }
}

int main()
{
    int dividend = 7;
    int divisor = -3;

    cout << divide(dividend, divisor) << endl;
    cout << divisor;

    return 0;
}
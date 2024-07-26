#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;
#define ll long long

ll helper(string &exp, int i, int j, bool isTrue)
{
    if (i > j)
    {
        return 0;
    }

    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
        {
            return exp[i] == 'F';
        }
    }

    ll ways = 0;

    for (int idx = i + 1; idx <= j - 1; idx += 2)
    {

        ll LT = helper(exp, i, idx - 1, 1);
        ll LF = helper(exp, i, idx - 1, 0);
        ll RT = helper(exp, idx + 1, j, 1);
        ll RF = helper(exp, idx + 1, j, 0);

        if (exp[idx] == '&')
        {
            if (isTrue)
            {
                ways += (LT * RT) % MOD;
            }
            else
            {
                ways += ((LT * RF) % MOD + (LF * RT) % MOD + (LF * RF) % MOD) % MOD;
            }
        }
        else if (exp[idx] == '|')
        {
            if (isTrue)
            {
                ways += ((LT * RT) % MOD + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
            }
            else
            {
                ways += (LF * RF) % MOD;
            }
        }
        else
        {
            if (isTrue)
            {
                ways += ((LT * RF) % MOD + (RT * LF) % MOD) % MOD;
            }
            else
            {
                ways += ((LT * RT) % MOD + (LF * RF) % MOD) % MOD;
            }
        }
    }

    return ways % MOD;
}

int evaluateExp(string &exp)
{
    // Write your code here.

    return helper(exp, 0, exp.length() - 1, 1);
}
int main()
{

    return 0;
}
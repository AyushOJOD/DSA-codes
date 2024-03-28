#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    int prev2 = 0, prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main()
{

    return 0;
}
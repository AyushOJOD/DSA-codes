#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int N;

    int helper(int cnt, int copied)
    {
        if (cnt >= N)
        {
            return 0;
        }

        if (N % cnt == 0)
        {
            return 2 + helper(cnt + cnt, cnt);
        }

        return 1 + helper(cnt + copied, copied);
    }

    int minSteps(int n)
    {
        N = n;

        return helper(1, 1);
    }
};

int main()
{

    return 0;
}
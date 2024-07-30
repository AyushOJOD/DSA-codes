#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (check(arr[i], arr[prev]) && 1 + dp[prev] = dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
        }
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dp[1006];

int solve(int i, string &s)
{
    if (i < 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int freq[26] = {0}, ans = 5005;
    for (int j = i; j >= 0; --j)
    {
        freq[s[j] - 'a'] += 1;
        int mini = 5005, maxi = 0;
        for (int k = 0; k < 26; ++k)
        {
            if (freq[k])
            {
                mini = min(mini, freq[k]);
                maxi = max(maxi, freq[k]);
            }
        }
        if (mini == maxi)
        {
            ans = min(ans, 1 + solve(j - 1, s));
        }
    }
    return dp[i] = ans;
}

int minimumSubstringsInPartition(string s)
{
    memset(dp, -1, sizeof(dp));
    return solve(s.size() - 1, s);
}

int main()
{

    return 0;
}
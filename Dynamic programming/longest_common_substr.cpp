#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    // your code here

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i] == S2[j])
            {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        prev = curr;
    }

    return ans;
}

int main()
{

    return 0;
}
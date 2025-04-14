#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });

        vector<int> dp(n, 1);

        int maxEnvelopes = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (envelopes[i][1] > envelopes[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxEnvelopes = max(maxEnvelopes, dp[i]);
        }

        return maxEnvelopes;
    }
};

int main()
{

    return 0;
}
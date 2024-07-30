#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> LCS(string s, string t)
{
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp;
}

void printLCS(string s, string t)
{
    vector<vector<int>> dp = LCS(s, t);

    int n = dp.size();
    int m = dp[0].size();

    vector<char> lcs;

    for (int i = 0; i < n; i++)
    {
        lcs += '$';
    }

    int idx = n - 1;
    int i = n - 1, j = m - 1;

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            lcs[idx] = s[i - 1];
            idx--;
            i--, j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    cout << lcs << endl;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void minDistance(string word1, string word2, vector<vector<int>> &dp)
{
    int n = word1.length();
    int m = word2.length();

    if (n == 0 || m == 0)
    {
        return max(m, n);
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int del = 1 + dp[i - 1][j];
                int insert = 1 + dp[i][j - 1];
                int replace = 1 + dp[i - 1][j - 1];

                dp[i][j] = min({del, insert, replace});
            }
        }
    }
}

vector<string> diffBetweenTwoStrings(const string &source, const string &target)
{
    // your code goes here
    int n = source.length();
    int m = target.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    minDistance(source, target, dp);

    vector<string> ans;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (source[i] == target[j])
        {
            ans.push_back(source[i]);
            i++;
            j++;
        }
        else
        {
            if (dp[i + 1][j] <= dp[i][j + 1])
            {
                ans.push_back("-" + source[i]);
                i++;
            }
            else
            {
                ans.push_back("+" + target[j]);
                j++;
            }
        }
    }

    while (j < m)
    {
        ans.push_back("+" + target[j]);
        j++;
    }

    return ans;
}

// comment out main() before running tests
int main()
{
    // debug your code below
    string source = "ABCDEFG";
    string target = "ABDFFGH";
    vector<string> result = diffBetweenTwoStrings(source, target);
    for (const string &s : result)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
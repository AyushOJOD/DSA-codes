#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s)
{
    string s1 = s;
    int n = s.length();

    reverse(s1.begin(), s1.end());

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        prev[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int i = 0; i <= n; j++)
        {
            if (s[i - 1] == s1[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(curr[j - 1], prev[j]);
            }
        }
        prev = curr;
    }

    int maxLen = prev[n];

    return n - maxLen;
}

int main()
{

    return 0;
}
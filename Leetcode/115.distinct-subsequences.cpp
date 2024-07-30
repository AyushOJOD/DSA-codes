#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        vector<int> curr(m + 1, 0);
        vector<int> prev(m + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            curr[0] = 1;
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    curr[j] = prev[j - 1] + prev[j];
                }
                else
                {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};

int main()
{

    return 0;
}
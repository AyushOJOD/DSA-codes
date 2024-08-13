#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        int open = 0, close = 0;
        int maxLen = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }

            if (open == close)
            {
                maxLen = max(maxLen, 2 * close);
            }
            else if (open < close)
            {
                open = 0;
                close = 0;
            }
        }

        open = 0, close = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }

            if (open == close)
            {
                maxLen = max(maxLen, 2 * open);
            }
            else if (open > close)
            {
                open = 0, close = 0;
            }
        }

        return maxLen;
    }
};

int main()
{

    return 0;
}
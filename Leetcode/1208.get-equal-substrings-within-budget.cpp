#include <bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost)
{
    int n = s.length();
    int left = 0;
    int currVal = 0;
    int maxLen = 0;

    for (int right = 0; right < n; right++)
    {
        currVal += abs(s[right] - t[right]);

        while (currVal > maxCost)
        {
            currVal -= abs(s[left] - t[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{

    return 0;
}
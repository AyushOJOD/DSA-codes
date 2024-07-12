#include <bits/stdc++.h>
using namespace std;

int longestSubstr(string s, int k)
{
    unordered_map<char, int> mp;
    int left = 0, right = 0, maxLength = 0;

    while (right < s.length())
    {
        mp[s[right]]++;

        if (mp.size() > k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
            {
                mp.erase(s[left]);
            }
            left++;
        }

        int len = right - left + 1;
        maxLength = max(maxLength, len);
        right++;
    }

    return maxLength;
}

int main()
{

    return 0;
}
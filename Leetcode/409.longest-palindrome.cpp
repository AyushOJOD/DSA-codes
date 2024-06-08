#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
    unordered_map<char, int> freq;

    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    int cnt = 0;
    bool isSingle = false;

    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        char letter = it->first;
        int count = it->second;

        if (count % 2 == 0)
        {
            cnt += count;
        }
        else
        {
            isSingle = true;
        }
    }

    return isSingle ? cnt + 1 : cnt;
}

int main()
{

    return 0;
}
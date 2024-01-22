#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string &s1, string &s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;

    for (int i = 0; i < s1.length(); i++)
    {
        mp1[s1[i]]++;
        mp2[s2[i]]++;
    }

    for (int i = 0; i < mp1.size(); i++)
    {
        if (mp1[i] != mp2[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}
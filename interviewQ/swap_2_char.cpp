// Given two strings, return true if you could change 2 letters in the s string and return the goal string. If this isn't possible, return false.

#include <bits/stdc++.h>
using namespace std;

bool isPossible(string s, string t)
{
    pair<char, char> p1 = {'@', '@'};
    pair<char, char> p2 = {'@', '@'};
    bool isFilled = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            if (isFilled)
            {
                p1.first = s[i];
                p1.second = t[i];
                isFilled = true;
            }
            else
            {
                p2.first = s[i];
                p2.second = t[i];
            }
        }
    }
}

int main()
{

    return 0;
}
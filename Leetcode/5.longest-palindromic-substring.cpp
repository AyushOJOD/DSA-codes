#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    if (s == string(s.rbegin(), s.rend()))
    {
        return s;
    }

    string pick = longestPalindrome(s.substr(1));
    string notPick = longestPalindrome(s.substr(0, s.size() - 1));

    if (pick.length() > notPick.length())
    {
        return pick;
    }
    else
    {
        return notPick;
    }
}

int main()
{

    return 0;
}
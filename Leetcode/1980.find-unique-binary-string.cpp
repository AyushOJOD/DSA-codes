#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{

    if (s.length() == 0)
    {
        return true;
    }

    vector<char> alpha;

    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            alpha.push_back(s[i]);
        }
    }

    int size = alpha.size();

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        if (alpha[left] != alpha[right])
        {
            return false;
        }
    }
    return true;
}

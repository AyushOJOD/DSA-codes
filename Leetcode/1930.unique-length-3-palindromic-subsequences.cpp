#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }
    return true;
}

int countPalindromicSubsequence(string s)
{
}

int main()
{

    return 0;
}
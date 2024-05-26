#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}

void func(int idx, vector<string> &temp, vector<vector<string>> &res, string s)
{

    if (idx == s.length())
    {
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            temp.push_back(s.substr(idx, i + 1));
            func(idx + 1, temp, res, s);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<int>> res;
    vector<int> temp;
    func(0, temp, res, s);
    return res;
}

int main()
{

    return 0;
}
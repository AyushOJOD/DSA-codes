#include <bits/stdc++.h>
using namespace std;

void func(string &digits, unordered_map<char, string> &mp, int idx, vector<string> &res, string temp)
{
    if (idx == digits.size())
    {
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < mp[digits[idx]].size(); i++)
    {
        temp.push_back(mp[digits[idx]][i]);
        func(digits, mp, idx + 1, res, temp);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    unordered_map<char, string> mp;

    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    vector<string> res;
    string temp = "";
}

int main()
{

    return 0;
}
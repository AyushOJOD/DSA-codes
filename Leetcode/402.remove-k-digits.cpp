#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    string res = "";

    for (char &c : num)
    {
        while (res.size() && res.back() > c && k)
        {
            ans.pop_back();
            k--;
        }
        if (ans.size() || c != '0')
            ans.push_back(c);
    }

    while (res.size() && k--)
    {
        res.pop_back();
    }

    return res.empty() ? "0" : res;
}

int main()
{

    return 0;
}
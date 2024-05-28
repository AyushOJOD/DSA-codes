#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());

    int n = strs.size();

    string a = strs[0], b = strs[n - 1], ans = "";

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            ans += a[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{

    return 0;
}
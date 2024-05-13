#include <bits/stdc++.h>
using namespace std;

void subsequences(string s, string ans, int idx)
{
    if (idx >= s.length())
    {
        cout << ans << endl;
        return;
    }
    ans.append(1, s[idx]);
    subsequences(s, ans, idx + 1);
    ans.pop_back();
    subsequences(s, ans, idx + 1);
}

int main()
{
    string s = "abc";
    string ans = "";
    subsequences(s, ans, 0);

    return 0;
}
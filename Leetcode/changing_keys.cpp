#include <bits/stdc++.h>
using namespace std;

int changeKeys(string s)
{
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i + 1] - s[i] == 32 || s[i] - s[i + 1] == 32 || s[i + 1] == s[i])
        {
            continue;
        }
        else
        {
            count++;
        }
    }

    return count;
}

int main()
{
    string s;
    cin >> s;

    cout << changeKeys(s) << endl;
    return 0;
}
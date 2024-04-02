#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    if (s.length() == 0)
        return 0;

    int n = s.length();

    int res = 0;
    int lastWord = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (res != 0)
            {
                lastWord = res;
                res = 0;
            }
        }
        else
        {
            res++;
        }
    }

    if (res == 0)
    {
        return lastWord;
    }

    return res;
}

int main()
{
    string s = "Hello World";
    cout << lengthOfLastWord(s) << endl;

    return 0;
}
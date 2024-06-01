#include <bits/stdc++.h>
using namespace std;

int numSteps(string s)
{
    int cnt = 0;
    int i = s.length() - 1;

    while (i > 0)
    {
        if (s[i] == '0')
        {
            i--;
        }
        else
        {
            while (i > 0 && s[i] == '1')
            {
                s[i] = '0';
                i--;
            }
            if (i > 0)
            {
                s[i] = '1';
            }
        }
        cnt++;
    }
}

int main()
{

    string s = "1101";

    cout << numSteps(s);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int appendCharacters(string s, string t)
{
    int ps = 0, pt = 0;
    int ls = s.length(), lt = l.length();

    while (ps <= ls && pt <= lt)
    {
        if (s[ps] == t[pt])
        {
            pt++;
        }
        ps++;
    }

    return lt - pt;
}

int main()
{

    return 0;
}
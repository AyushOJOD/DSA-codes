#include <bits/stdc++.h>
using namespace std;

int minChanges(string s)
{
    int res = 0;
    int size = s.size();

    for (int i = 0; i < size - 1; i += 2)
    {

        if (s[i] != s[i + 1])
        {
            res++;
        }
    }
    return res;
}

int main()
{

    string s = "11000111";

    cout << minChanges(s);

    return 0;
}
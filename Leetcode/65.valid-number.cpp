#include <bits/stdc++.h>
using namespace std;

bool isNumber(string s)
{
    int i = 0, n = s.size();

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i >= n)
        return false;

    bool beforeInt = false;

    while (s[i] >= '0' && s[i] <= '9' && i < n)
    {
        i++;
        beforeInt = true;
    }

    if (i >= n)
        return true;

    bool dot = false;
    if (s[i] == '.')
    {
        i++;
        dot = true;
    }

    if (i >= n)
        if (dot == true && beforeInt == false)
            return false;
        else
            return true;

    if (dot)
        if (beforeInt)
        {
            if ((s[i] < '0' || s[i] > '9') && (s[i] != 'e' && s[i] != 'E'))
                return false;
        }
        else
        {
            if (s[i] < '0' || s[i] > '9')
                return false;
        }

    while (i < n && s[i] != 'e' && s[i] != 'E')
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
        i++;
    }
    if (!dot)
        if ((s[i] == 'e' || s[i] == 'E') && beforeInt == false)
            return false;
    if (i >= n)
        return true;

    i++; // next ot e

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i >= n)
        return false;

    bool lastInt = false;
    while (s[i] >= '0' && s[i] <= '9' && i < n)
    {
        i++;
        lastInt = true;
    }

    if (!lastInt)
        return false;

    if (i >= n)
        return true;
    return false;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool isRoataion(string &s1, string &s2)
{

    if (s1.length() != s2.length())
    {
        return false;
    }
    else
    {
        return ((s1 + s2).find(s2) != string::npos) // we use string::npos because .find() gives a index
    }
}

int main()
{

    return 0;
}
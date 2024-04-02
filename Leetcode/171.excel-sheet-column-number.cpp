#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle)
{
    int len = columnTitle.length();
    int res = 0;

    for (int i = 0; i < len; i++)
    {
        res = res * 26 + (columnTitle[i] - 'A' + 1);
    }

    return res;
}

int main()
{

    return 0;
}
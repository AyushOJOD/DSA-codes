#include <bits/stdc++.h>
using namespace std;

void patterns(string &txt, string &patt)
{
    int n = txt.length();
    int m = patt.length();

    for (int i = 0; i < n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (txt[i + j] != patt[j])
            {
                break;
            }
            if (j == m)
            {
                cout << i << " ";
            }
        }
    }
}

int main()
{

    return 0;
}
// Only works for distinct

#include <bits/stdc++.h>
using namespace std;

void distinctSearch(string &txt, string &patt)
{
    int n = txt.length();
    int m = patt.length();

    for (int i = 0; i < n - m;)
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
            if (j == 0)
            {
                i++;
            }
            else
            {
                i = i + j;
            }
        }
    }
}

int main()
{

    return 0;
}
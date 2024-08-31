#include <bits/stdc++.h>
using namespace std;

vector<int> getLPS(string &p)
{
    int m = p.length();

    vector<int> lps(m, 0);

    int idx = 1;
    lps[0] = 0;
    int length = 0;

    while (idx < m)
    {
        if (p[idx] == p[length])
        {
            length++;
            lps[idx] = length;
            idx++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                idx++;
            }
        }
    }
}

vector<int> search(string txt, string patt)
{
    int n = txt.length();
    int m = patt.length();

    vector<int> res;

    // We need to find the LPS(Longest Prefix Suffix) vector of the pattern
    // LPS[i] is the length of maximum prefix from 0->i equal to suffix from i->m-1

    vector<int> LPS = getLPS(patt);

    int i = 0, j = 0;

    while (i < n)
    {
        if (txt[i] == patt[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            res.push_back(i - m + 1);
        }
        else if (txt[i] != patt[j])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return res;
}

int main()
{

    return 0;
}

// a a a a c
// a a c
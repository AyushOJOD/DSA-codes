// Here we need to search if the pattern string is present in txt or any of its anagram is present in it

#include <bits/stdc++.h>
using namespace std;

bool anagramSearch(string &txt, string &patt)
{
    int CT[char] = {0}, CP[char] = {0};

    for (int i = 0; i < patt.length(); i++)
    {
        CT[txt[i]]++;
        CP[patt[i]]++;
    }
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> mp;

    for (char c : s)
    {
        mp[c]++;
    }

    int cmp(pair<char, int> a, pair<char, int> b)
    {
        return a.second < b.second;
    }

    sort(mp.begin(), mp.end(), cmp);
}

int main()
{

    return 0;
}
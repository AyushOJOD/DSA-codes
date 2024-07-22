#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;

    unordered_map<char, vector<int>> mp; //{char -> {index}}

    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]].push_back(i);
    }

    vector<pair<int, char>> v;

    for (auto &it : mp)
    {
        if (it.second.size() == 1)
        {
            v.push_back({it.second[0], it.first});
        }
    }

    sort(v.begin(), v.end());

    cout << v[0].second;

    return 0;
}
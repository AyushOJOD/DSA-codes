#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> freq;
    priority_queue<pair<int, char>> pq;

    for (auto x : s)
    {
        freq[x]++;
    }

    for (auto it : freq)
    {
        pq.push({it.second, it.first});
    }

    string res = "";

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        for (int i = 0; i < it.first; i++)
        {
            res += it.second;
        }
    }

    return res;
}

int main()
{

    return 0;
}
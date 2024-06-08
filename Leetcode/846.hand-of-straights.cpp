#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    int n = hand.size();

    if (n % groupSize != 0)
    {
        return false;
    }

    map<int, int> mp;

    for (auto x : hand)
    {
        mp[x]++;
    }

    for (auto [key, val] : mp)
    {
        if (val == 0)
            continue;

        while (val--)
        {
            for (int curr = key; curr < key + groupSize; curr++)
            {
                if (mp[curr] == 0)
                {
                    return false;
                }
                mp[curr]--;
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}
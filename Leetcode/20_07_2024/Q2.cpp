#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        unordered_map<char, int> mp;

        for (char ch : s)
        {
            mp[ch]++;
        }

        for (auto it : mp)
        {
            int freq = it.second;

            while (freq >= 3)
            {
                freq -= 2;
            }

            it.second = freq;
        }

        int cnt = 0;

        for (auto it : mp)
        {
            cnt += it.second;
        }

        return cnt;
    }
};

int main()
{

    return 0;
}
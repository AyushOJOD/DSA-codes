#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();

        if (n > m)
        {
            return false;
        }

        unordered_map<char, int> mp; // char->freq

        for (char c : s1)
        {
            mp[c]++;
        }

        for (int i = 0; i < n; i++)
        {
            mp[s2[i]]--;
            if (mp[s2[i]] == 0)
            {
                mp.erase(s2[i]);
            }
        }

        if (mp.empty())
        {
            return true;
        }

        for (int i = 1; i <= m - n; i++)
        {
            mp[s2[i - 1]]++;
            if (mp[s2[i - 1]] == 0)
            {
                mp.erase(s2[i - 1]);
            }

            mp[s2[i + n - 1]]--;
            if (mp[s2[i + n - 1]] == 0)
            {
                mp.erase(s2[i + n - 1]);
            }

            if (mp.empty())
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}

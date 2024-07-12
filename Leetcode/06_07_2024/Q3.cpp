#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        ll n = colors.size();
        ll cnt = 0, idx = 1;

        vector<int> newColors = colors;
        newColors.insert(newColors.end(), colors.begin(), colors.begin() + k - 1);

        for (ll i = 1; i < newColors.size(); ++i)
        {
            if (newColors[i] != newColors[i - 1])
            {
                ++idx;
            }
            else
            {
                idx = 1;
            }
            if (idx >= k)
            {
                ++cnt;
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}
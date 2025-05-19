#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        unordered_map<vector<int>, bool> mp;

        deque<int> check;

        for (auto domi : dominoes)
        {
            mp[domi] = true;
        }

        int res = 0;

        for (auto dom : dominoes)
        {
            auto curr = dom;
            swap(dom[0], dom[1]);

            if (mp.find(curr) != mp.end())
            {
                res++;
                mp[curr] = false;
            }

            if (mp.find(dom) != mp.end())
            {
                res++;
                mp[dom] = false;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}
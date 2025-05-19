#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> mp;

        for (int a : answers)
        {
            mp[a]++;
        }

        int cnt = 0;
        for (auto &[k, v] : mp)
        {
            int groups = (v + k) / (k + 1);
            cnt += (k + 1) * groups;
        }

        return cnt;
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// find the longest subarray having only two types of fruit

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();

        unordered_map<int, int> mp;

        int left = 0, right = 0, maxlen = 0;

        while (right < n)
        {
            mp[fruits[right]]++;

            if (mp.size() > 2)
            {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);
                }
            }
            else
            {
                maxlen = max(maxlen, right - left + 1);
                right++;
            }
        }

        return maxlen;
    }
};

int main()
{

    return 0;
}
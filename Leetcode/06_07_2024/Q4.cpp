#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        ll cnt = 0;

        unordered_map<ll, ll> last;

        for (auto num : nums)
        {
            unordered_map<ll, ll> curr;

            if (num == k)
            {
                cnt++;
            }

            curr[num] = 1;

            for (auto &it : last)
            {
                ll currRes = it.first & num;
                if (currRes == k)
                {
                    cnt += it.second;
                }

                curr[currRes] += it.second;
            }

            last = curr;
        }
        return cnt;
    }
};

int main()
{

    return 0;
}
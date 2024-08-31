#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long int ll;

    ll helper(string s, int k)
    {
        int n = s.length();
        d if (k <= 0)
        {
            return 0;
        }

        unordered_map<char, int> freq;
        int left = 0, right = 0, cnt = 0;
        ll ans = 0;

        while (right < n)
        {
            freq[s[right]]++;
            if (freq[s[right]] == 1)
            {
                cnt++;
            }

            while (cnt > k)
            {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                {
                    cnt--;
                }
                left++;
            }

            ans += (right - left + 1);
            right++;
        }

        return ans;
    }

    long long int substrCount(string s, int k)
    {
        return helper(s, k) - helper(s, k - 1);
    }
};

int main()
{

    return 0;
}
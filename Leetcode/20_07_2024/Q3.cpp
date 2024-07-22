#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minChanges(vector<int> &nums, int k)
    {
        int n = nums.size();

        map<int, vector<int>> freqMap;
        vector<int> maxDiff;

        for (int i = 0; i < n / 2; ++i)
        {
            int a = nums[i];
            int b = nums[n - i - 1];
            int diff = abs(a - b);

            int diffrence = max({a, b, k - a, k - b});

            freqMap[diff].push_back(diffrence);
            maxDiff.push_back(diffrence);
        }

        int res = n;

        sort(maxDiff.begin(), maxDiff.end());

        for (auto &[key, value] : freqMap)
        {
            int minVal = lower_bound(maxDiff.begin(), maxDiff.end(), key) - maxDiff.begin();
            minVal = (n / 2 - minVal) + minVal * 2;

            for (auto &diffrence : value)
            {
                if (diffrence < key)
                {
                    minVal -= 2;
                }
                else
                {
                    minVal -= 1;
                }
            }

            res = min(res, minVal);
        }

        return res;
    }
};

int main()
{

    return 0;
}
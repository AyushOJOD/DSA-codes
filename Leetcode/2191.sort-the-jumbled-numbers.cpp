#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        int n = nums.size();

        vector<pair<int, int>> mappedWithIdx(n);

        for (int i = 0; i < n; i++)
        {
            int og = nums[i];
            int mappedNum = (og == 0) ? mapping[0] : 0;
            int idx = 1;

            while (og > 0)
            {
                int digit = og % 10;
                mappedNum += idx * mapping[digit];
                og /= 10;
                idx *= 10;
            }

            mappedWithIdx[i] = {mappedNum, i};
        }

        sort(mappedWithIdx.begin(), mappedWithIdx.end());

        vector<int> res;

        for (auto it : mappedWithIdx)
        {
            res.push_back(nums[it.second]);
        }

        return res;
    }
};

int main()
{

    return 0;
}
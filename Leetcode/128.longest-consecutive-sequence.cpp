#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> data(nums.begin(), nums.end());

        int res = 0;

        for (int num : nums)
        {
            if (data.find(num - 1) == data.end())
            {
                int curr = num;
                int currLen = 1;

                while (data.find(curr + 1) != data.end())
                {
                    curr += 1;
                    currLen++;
                }
                res = max(res, currLen);
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxVal = *max_element(nums.begin(), nums.end());

        int maxLen = INT_MIN, currLen = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == maxVal)
            {
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            else
            {
                currLen = 0;
            }
        }

        return maxLen;
    }
};

int main()
{

    return 0;
}
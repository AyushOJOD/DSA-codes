#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int currInc = 1, currDec = 1, res = 0, idx = 0;
        if (nums.size() == 1)
            return 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                currInc++;
                currDec = 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                currDec++;
                currInc = 1;
            }
            else
            {
                currInc = 1;
                currDec = 1;
            }

            ans = max(currInc, currDec);
        }

        return ans;
    }
};

int main()
{

    return 0;
}
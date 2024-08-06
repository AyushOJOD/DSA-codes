#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();

        int ones = 0;

        for (int i : nums)
        {
            if (i == 1)
            {
                ones++;
            }
        }

        nums.insert(nums.end(), nums.begin(), nums.end());

        int currOnes = 0;

        for (int i = 0; i < ones; i++)
        {
            if (nums[i] == 1)
            {
                currOnes++;
            }
        }

        int maxOnes = currOnes;

        int left = 0, right = ones - 1;

        while (right < 2 * n - 1)
        {
            currOnes -= nums[left];
            currOnes += nums[right + 1];

            left++;
            right++;

            maxOnes = max(maxOnes, currOnes);
        }

        return ones - maxOnes;
    }
};

int main()
{

    return 0;
}
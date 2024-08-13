#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<string> ans;

        if (n == 0)
        {
            return ans;
        }

        int start = nums[0]; // Start of the current range

        for (int i = 1; i < n; ++i)
        {
            // If the current number is not consecutive with the previous
            if (nums[i] != nums[i - 1] + 1)
            {
                // If start and previous number are the same, it's a single number
                if (start == nums[i - 1])
                {
                    ans.push_back(to_string(start));
                }
                else
                {
                    ans.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                // Update start to the current number
                start = nums[i];
            }
        }

        // Add the final range or number
        if (start == nums[n - 1])
        {
            ans.push_back(to_string(start));
        }
        else
        {
            ans.push_back(to_string(start) + "->" + to_string(nums[n - 1]));
        }

        return ans;
    }
};

int main()
{

    return 0;
}
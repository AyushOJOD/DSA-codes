#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int maxDist = INT_MIN;
        int change = 0;
        int n = nums.size();
        int count = 0;

        // First pass: Check alternating pattern starting with change = 0
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == change)
            {
                count++;
                change = 1 - change; // Toggle change (0 to 1 or 1 to 0)
            }
        }
        maxDist = max(maxDist, count);

        // Second pass: Check alternating pattern starting with change = 1
        change = 1;
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == change)
            {
                count++;
                change = 1 - change; // Toggle change (0 to 1 or 1 to 0)
            }
        }
        maxDist = max(maxDist, count);

        // Third pass: Count consecutive elements with change = 0
        change = 0;
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == change)
            {
                count++;
            }
        }
        maxDist = max(maxDist, count);

        // Fourth pass: Count consecutive elements with change = 1
        change = 1;
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == change)
            {
                count++;
            }
        }
        maxDist = max(maxDist, count);

        return maxDist;
    }
};

int main()
{

    return 0;
}
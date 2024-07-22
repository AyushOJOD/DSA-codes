#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumOperations(vector<int> &nums, vector<int> &target)
    {
        int n = target.size();
        int res = 0;
        int currSign = 0;

        for (int i = 0; i < n; i++)
        {
            int currDiff = target[i] - nums[i];

            if (currSign >= 0 && currDiff < 0 || currSign <= 0 && currDiff > 0 || i == 0)
            {
                res += abs(currDiff);
            }
            else
            {
                res += abs(currDiff - currSign);
            }
            currSign = currDiff;
        }

        return res;
    }
};

int main()
{

    return 0;
}
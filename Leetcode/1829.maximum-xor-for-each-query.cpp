#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getK(int k, int currXOR)
    {
        int maxVal = INT_MIN;

        for (int i = 0; i < k; i++)
        {
            int temp = currXOR ^ i;
            maxVal = max(maxVal, temp);
        }

        return maxVal;
    }

public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size();

        vector<int> ans(n, -1);

        int totalXOR = 0;

        for (int x : nums)
        {
            totalXOR ^= x;
        }

        int k = pow(2, maximumBit);

        for (int i = 0; i < n; i++)
        {
            int maxK = getK(k, totalXOR);
            ans[i] = maxK;
            totalXOR ^= nums[n - 1 - i];
        }

        return ans;
    }
};

int main()
{

    return 0;
}

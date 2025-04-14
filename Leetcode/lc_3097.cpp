#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void addContri(int val, vector<int> &BitArray, bool isAdding)
    {
        int idx = 0;
        while (val > 0)
        {
            BitArray[idx] = BitArray[idx] + (isAdding ? 1 : -1) * val % 2;
            val = val / 2;
            idx++;
        }
    }

    bool moreThanEqual(int k, vector<int> &bitArray)
    {
        int val = 0;

        for (int i = 0; i < 32; i++)
        {
            val += (bitArray[i] ? 1 : 0) * pow(2, i);
        }

        return val >= k;
    }

public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0, ans = INT_MAX;
        vector<int> BitArray(32, 0);

        while (j < n)
        {
            addContri(nums[j], BitArray, true);
            while (moreThanEqual(k, BitArray) && i <= j)
            {
                ans = min(ans, (j - i + 1));
                addContri(nums[i], BitArray, false);
                i++;
            }
            j++;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main()
{

    return 0;
}
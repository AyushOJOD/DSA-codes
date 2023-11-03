#include <bits/stdc++.h>
using namespace std;

int findKOr(vector<int> &nums, int k)
{
    int res = 0;
    for (int i = 31; i >= 0; i--)
    {
        int count = 0;
        for (int n : nums)
        {
            if ((n >> i) & 1)
            {
                count++;
            }
        }
        if (count >= k)
        {
            // Set the ith bit in the result if at least k elements have the ith bit set
            res |= (1 << i);
        }
    }
    return res;
}

int main()
{

    return 0;
}
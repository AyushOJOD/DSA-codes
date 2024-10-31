#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int minBits(int n)
    {
        return floor(log2(n)) + 1;
    }

public:
    int maxGoodNumber(vector<int> &nums)
    {
        int pop0 = __builtin_popcount(nums[0]);
        int pop1 = __builtin_popcount(nums[1]);
        int pop2 = __builtin_popcount(nums[2]);

        int min0 = minBits(nums[0]);
        int min1 = minBits(nums[1]);
        int min2 = minBits(nums[2]);

        string binaryVal = "";

        for (int i = 0; i < (pop0 + pop1 + pop2); i++)
        {
            binaryVal += '1';
        }

        int req0 = (min0 + min1 + min2) - (pop0 + pop1 + pop2);

        for (int i = 0; i < req0; i++)
        {
            binaryVal += '0';
        }

        std::bitset<32> bitset(binaryVal);

        unsigned long number = bitset.to_ulong();

        return number;
    }
};

int main()
{

    return 0;
}
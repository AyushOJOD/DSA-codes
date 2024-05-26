#include <bits/stdc++.h>
using namespace std;

long long sumDigitDifferences(vector<int> &nums)
{
    int num_digits = to_string(nums[0]).length();
    int n = nums.size();
    long long total_diff = 0;

    for (int pos = 0; pos < num_digits; pos++)
    {
        vector<long long> count(10, 0);
        for (int num : nums)
        {
            int digit = getDigit(num, pos);
            count[digit]++;
        }
        for (int digit = 0; digit < 10; digit++)
        {
            long long pairs_count = count[digit] * (n - count[digit]);
            total_diff += pairs_count;
        }
    }
    return total_diff / 2;
}

int getDigit(int num, int position)
{
    return (num / static_cast<int>(pow(10, position))) % 10;
}

int main()
{

    return 0;
}
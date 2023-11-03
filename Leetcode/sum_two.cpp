#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long minSum(vector<int> &nums1, vector<int> &nums2)
{
    ll sum1 = 0;
    ll sum2 = 0;
    ll zero1 = 0;
    ll zero2 = 0;

    for (int i = 0; i < nums1.size(); i++)
    {
        sum1 += nums1[i];
        if (nums1[i] == 0)
        {
            zero1++;
        }
    }

    for (int j = 0; j < nums2.size(); j++)
    {
        sum2 += nums2[j];
        if (nums2[j] == 0)
        {
            zero2++;
        }
    }

    if (sum1 + zero1 < sum2 + zero2)
    {
        swap(sum1, sum2);
        swap(zero1, zero2);
    }

    if (sum1 + zero1 > sum2 && zero2 == 0)
    {
        return -1;
    }

    return sum1 + zero1;
}

int main()
{

    vector<int> nums1 = {3, 2, 0, 1, 0};
    vector<int> nums2 = {6, 5, 0};

    minSum(nums1, nums2);

    return 0;
}
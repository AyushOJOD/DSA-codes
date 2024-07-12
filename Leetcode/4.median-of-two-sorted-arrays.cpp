#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0, right = m;

        while (left <= right)
        {
            int mid1 = left + (right - left) / 2;
            int mid2 = (m + n + 1) / 2 - mid1;

            // left half
            int x1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int x2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];

            // right half
            int x3 = (mid1 == m - 1) ? INT_MAX : nums1[mid1];
            int x4 = (mid2 == n - 1) ? INT_MAX : nums2[mid2];

            if (x1 <= x4 && x2 <= x3)
            {
                if ((m + n) % 2 == 0)
                {
                    return (max(x1, x2) + min(x3, x4)) / 2.0;
                }
                else
                {
                    return max(x1, x2);
                }
            }
            else if (x1 > x4)
            {
                right = mid1 - 1;
            }
            else
            {
                left = mid1 + 1;
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}
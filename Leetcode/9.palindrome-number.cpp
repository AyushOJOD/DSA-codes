#include <vector>

int minSum(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int sum1 = 0;
    int zeroes1 = 0;

    for (int num : nums1)
    {
        if (num == 0)
        {
            zeroes1++;
        }
        sum1 += num;
    }

    int sum2 = 0;
    int zeroes2 = 0;

    for (int num : nums2)
    {
        if (num == 0)
        {
            zeroes2++;
        }
        sum2 += num;
    }

    if (sum1 + zeroes1 < sum2 + zeroes2)
    {
        std::swap(sum1, sum2);
        std::swap(zeroes1, zeroes2);
    }

    if (sum1 + zeroes1 > sum2 && zeroes2 == 0)
    {
        return -1;
    }

    return sum1 + zeroes1;
}

int main()
{
    std::vector<int> nums1 = {0, 2, 4};
    std::vector<int> nums2 = {1, 3, 5};
    int result = minSum(nums1, nums2);
    return 0;
}

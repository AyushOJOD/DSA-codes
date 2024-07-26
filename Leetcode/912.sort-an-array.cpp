#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        vector<int> temp;
        int low = left;
        int high = mid + 1;

        while (low <= mid && high <= right)
        {
            if (nums[low] <= nums[high])
            {
                temp.push_back(nums[low]);
                low++;
            }
            else
            {
                temp.push_back(nums[high]);
                high++;
            }
        }

        while (low <= mid)
        {
            temp.push_back(nums[low]);
            low++;
        }

        while (high <= right)
        {
            temp.push_back(nums[high]);
            high++;
        }

        for (int i = left; i <= right; i++)
        {
            nums[i] = temp[i - left];
        }
    }

    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};

int main()
{

    return 0;
}
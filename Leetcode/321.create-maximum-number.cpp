#include <bits/stdc++.h>
using namespace std;

// nums1 = [3,4,6,5],
// nums2 = [9,1,2,5,8,3]
// k = 5

class Solution
{
private:
    vector<int> getLargest(vector<int> &nums, int len)
    {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            while (!ans.empty() && ans.back() < nums[i] && len - ans.size() < (nums.size() - i))
            {
                ans.pop_back();
            }
            if (ans.size() < len)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }

    vector<int> mergeTwo(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();

        vector<int> ans;

        int i = 0, j = 0;

        while (i < n1 && j < n2)
        {
            if (nums1[i] > nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while (i < n1)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < n2)
        {
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }

public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> maxNum = {-1};

        for (int i = 0; i < k; i++)
        {
            vector<int> great1 = getLargest(nums1, i);
            vector<int> great2 = getLargest(nums2, k - i);
            vector<int> merged = mergeTwo(great1, great2);

            maxNum = max(maxNum, merged);
        }

        return maxNum;
    }
};

int main()
{

        return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> res(2);

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        for (int i = 0; i < nums1.size(); i++)
        {
            if (s1.find(nums1[i]) != s1.end() && s2.find(nums1[i]) == s2.end())
            {
                res[0].push_back(nums1[i]);
            }
            else if (s1.find(nums1[i]) == s1.end() && s2.find(nums1[i]) != s2.end())
            {
                res[1].push_back(nums1[i]);
            }
            else
            {
                continue;
            }
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (s1.find(nums2[i]) != s1.end() && s2.find(nums2[i]) == s2.end())
            {
                res[0].push_back(nums2[i]);
            }
            else if (s1.find(nums2[i]) == s1.end() && s2.find(nums2[i]) != s2.end())
            {
                res[1].push_back(nums2[i]);
            }
            else
            {
                continue;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}
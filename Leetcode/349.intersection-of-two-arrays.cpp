#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int maxSize = max(nums1.size(), nums2.size());

    unordered_set<int> st;
    int n1 = 0;
    int n2 = 0;

    while (n1 <= maxSize || n2 <= maxSize)
    {
        if (nums1[n1] == nums2[n2])
        {
            st.insert(nums1[n1]);
            n1++;
            n2++;
        }
        else if (nums1[n1] > nums2[n2])
        {
            n2++;
        }
        else
        {
            n1++;
        }
    }

    vector<int> res(st.begin(), st.end());

    return res;
}

int main()
{

    return 0;
}
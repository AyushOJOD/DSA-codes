#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = 0;
    int p2 = 0;
    int mergeIndex = 0;

    vector<int> res(m + n);

    while (p1 < m && p2 < n)
    {
        if (nums1[p1] <= nums2[p2])
        {
            res[mergeIndex] = nums1[p1];
            p1++;
        }
        else
        {
            res[mergeIndex] = nums2[p2];
            p2++;
        }
        mergeIndex++;
    }

    while (p1 < m)
    {
        res[mergeIndex] = nums1[p1];
        p1++;
        mergeIndex++;
    }
    while (p2 < n)
    {
        res[mergeIndex] = nums2[p2];
        p2++;
        mergeIndex++;
    }

    for (int j = 0; j < m + n; j++)
    {
        nums1[j] = res[j];
    }
}

int main()
{

    return 0;
}
// Given two sorted array and a number x, find the pair whose sum is closest to x and the pair has an element from each array.
// We are given two arrays ar1[0…m-1] and ar2[0..n-1] and a number x, we need to find the pair ar1[i] + ar2[j] such that absolute value of (ar1[i] + ar2[j] – x) is minimum.

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr1, vector<int> arr2, int target)
{
    int n = arr1.size();
    int m = arr2.size();

    int diff = INT_MAX;
    int leftVal, rightVal;

    int l = 0;
    int r = n - 1;

    while (l < n && r >= 0)
    {
        if (arr1[l] + arr2[r] - target < diff)
        {
            leftVal = l;
            rightVal = r;
            diff = arr1[l] + arr2[r] - target;
        }

        if (arr[l] + arr[r] > target)
        {
            r--;
        }
        else
        {
            l++;
        }
    }

    return {leftVal, rightVal};
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    if (n == 0)
    {
        return 0;
    }

    vector<int> temp;
    temp.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
            temp[it - temp.begin()] = arr[i];
        }
    }

    return temp.size();
}

int main()
{

    return 0;
}
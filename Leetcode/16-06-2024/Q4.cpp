#include <bits/stdc++.h>
using namespace std;

bool isPeak(vector<int> &arr, int n, int num, int i, int j)
{
    if (i >= 0 && arr[i] > num)
        return false;

    if (j < n && arr[j] > num)
        return false;

    return true;
}

vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();

    vector<int> ans;

    for (auto q : queries)
    {
        int type = q[0];
        int first = q[1];
        int second = q[2];

        if (type == 1)
        {
            for (int i = first; i < second; i++)
            {
                if ()
            }
        }
    }
}

int main()
{

    return 0;
}